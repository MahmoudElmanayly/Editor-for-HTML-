

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