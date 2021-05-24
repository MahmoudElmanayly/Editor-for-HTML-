

#include "Globals.h"
#include "Editors.h"

//###################### Parent Class ###############################


Editors::Editors(int posX, int posY, int width, int height, const char* fileName)
	: Fl_Text_Editor(posX, posY, width, height, fileName),
	m_fileName{ fileName },
	m_setName{ false }
{
	m_buffer = new Fl_Text_Buffer(g_initial_buffer_size);
	buffer(m_buffer);
	selection_color(FL_SELECTION_COLOR);
	linenumber_width(g_line_number_width);
	wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, Fl_Text_Display::WRAP_AT_COLUMN);
}

Editors::~Editors() {}


void Editors::setFileName(std::string fileName) {
	m_setName = true;
	this->m_fileName = fileName;
	label(m_fileName.c_str());
}

const char* Editors::getFileName() const {
	return m_fileName.c_str();
}

int Editors::saveFile() const {
	int status = -1;
	if (m_setName)
		 status = this->m_buffer->savefile(this->m_fileName.c_str());
	return status;
}


void Editors::Delete() {
	if (this->m_setName) {
		this->m_setName = false;
		this->m_fileName = "No File Selected";
		
		int buffSize = this->m_buffer->length();
		this->m_buffer->remove(0, buffSize - 1);
		
		std::string command = "del /f ";
		command += m_fileName;
		system(command.c_str());
		
		fl_message("The file has been deleted.");
	}
}


//################### End Parent Class #########################


//################# Editor Child Class #########################

Editor::Editor(int posX, int posY, int width, int height, const char* fileName)
	:Editors(posX, posY, width, height, fileName)
{
	color(FL_DISPLAYER_BG_COLOR);
	textcolor(FL_DISPLAYER_TXT_COLOR);

	cursor_color(FL_DISPLAYER_CURSOR_COLOR);
	cursor_style(Fl_Text_Display::HEAVY_CURSOR);
}

Editor::~Editor() {}

void Editor::loadFile(const char* filePath) {
	auto* buf = buffer();
	int status = buf->loadfile(filePath);
	if (status != 0) {
		fl_alert("Error: Could not Load File");
	}
	else {
		setFileName(filePath);
	}
}

void Editor::ConvertBtn_CB(Fl_Widget*, void*) {
	
}

void Editor::FindWord(const char* word) {
	fl_message("In the find word function");
	int pos = this->insert_position();
	int found = this->m_buffer->search_forward(pos, word, &pos);
	if (found) {
		this->m_buffer->select(pos, pos + strlen(word));
		this->insert_position(pos + strlen(word));
		this->show_insert_position();
	}
	else {
		fl_alert("No occurrences of \'%s\' found!", word);
	}
}

void Editor::ReplaceAllWords(const char* oldWord, const char* neWord) {
	this->insert_position(0);
	int times = 0;

	for (int found = 1; found; ) {
		int pos = this->insert_position();
		found = this->m_buffer->search_forward(pos, oldWord, &pos);

		if (found) {
			this->m_buffer->select(pos, pos + strlen(oldWord));
			this->m_buffer->remove_selection();
			this->m_buffer->insert(pos, neWord);
			this->insert_position(pos + strlen(neWord));
			this->show_insert_position();
			times++;
		}
	}
	if (times)
		fl_message("Replaced %d occurrences.", times);
	else
		fl_message("No occurrences of \'%s\' found!", oldWord);
}

void Editor::ReplaceNextWord(const char* oldWord, const char* neWord) {
	static int pos = -1;
	if (pos == -1) {
		this->insert_position(0);
		pos = this->insert_position();
	}

	int found = this->m_buffer->search_forward(pos, oldWord, &pos);
	if (found) {
		this->m_buffer->select(pos, pos + strlen(oldWord));
		this->m_buffer->remove_selection();
		this->m_buffer->insert(pos, neWord);
		this->insert_position(pos);
		this->show_insert_position();
	}
	else {
		fl_message("No occurrence of \'%s\' found!", oldWord);
	}
}


//############### End Editor Child Class #######################




//############## Displayer Child Class #########################

Displayer::Displayer(int posX, int posY, int width, int height, const char* fileName)
	:Editors(posX, posY, width, height, fileName)
{
	m_setName = true;

	color(FL_DISPLAYER_BG_COLOR);
	textcolor(FL_DISPLAYER_TXT_COLOR);

	cursor_color(FL_DISPLAYER_CURSOR_COLOR);
	cursor_style(Fl_Text_Display::HEAVY_CURSOR);
}


Displayer::~Displayer() {}
//############ End Displayer Child Class #######################