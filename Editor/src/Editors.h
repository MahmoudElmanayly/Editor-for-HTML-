#pragma once
#include "Globals.h"

#include <FL/Fl_Text_Editor.H>
#include <string>

class Editors : public Fl_Text_Editor {
private:
	const char* m_fileName;
	bool m_saved;

public:
	Editors(Fl_Text_Buffer* Buffer, int posX, int posY, int width, int height,
		const char* fileName);
	~Editors();

};

class Editor : public Editors {
public:
	Editor(Fl_Text_Buffer* editorBuffer, int posX, int posY, int width, int height,
		const char* fileName);
	~Editor();
};

class Displayer : public Editors {
public:
	Displayer(Fl_Text_Buffer* displayerBuffer, int posX, int posY, int width, int height,
		const char* fileName);
	~Displayer();
};
