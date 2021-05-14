
#include <FL/Fl.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/fl_ask.H>

#include "Globals.h"
#include "Editors.h"

//###################### Parent Class ###############################

Editors::Editors(Fl_Text_Buffer* buf, int posX, int posY, int width, int height,
	const char* fileName)
	: Fl_Text_Editor(posX, posY, width, height, fileName),
	m_fileName{ fileName }
{
	buffer(buf);
	selection_color(FL_SELECTION_COLOR);
	linenumber_width(g_line_number_width);
	wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, Fl_Text_Display::WRAP_AT_COLUMN);
}

Editors::~Editors() {}

//################### End Parent Class #########################


//################# Editor Child Class #########################
Editor::Editor(Fl_Text_Buffer* editorBuffer, int posX, int posY, int width, int height,
	const char* fileName)
	:Editors(editorBuffer, posX, posY, width, height, fileName)
{
	color(FL_DISPLAYER_BG_COLOR);
	textcolor(FL_DISPLAYER_TXT_COLOR);

	cursor_color(FL_DISPLAYER_CURSOR_COLOR);
	cursor_style(Fl_Text_Display::HEAVY_CURSOR);
}

Editor::~Editor() {}
//############### End Editor Child Class #######################




//############## Displayer Child Class #########################
Displayer::Displayer(Fl_Text_Buffer* displayerBuffer, int posX, int posY, int width, int height,
	const char* fileName)
	:Editors(displayerBuffer, posX, posY, width, height, fileName)
{
	color(FL_DISPLAYER_BG_COLOR);
	textcolor(FL_DISPLAYER_TXT_COLOR);

	cursor_color(FL_DISPLAYER_CURSOR_COLOR);
	cursor_style(Fl_Text_Display::HEAVY_CURSOR);
}


Displayer::~Displayer() {}
//############ End Displayer Child Class #######################