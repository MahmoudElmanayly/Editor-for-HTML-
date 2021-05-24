#pragma once
#include "Globals.h"

#include <FL/Fl_Text_Editor.H>
#include <string>

class Editors : public Fl_Text_Editor {

protected:
	std::string m_fileName;
	bool m_setName;
	Fl_Text_Buffer* m_buffer;
	

public:
	Editors(int posX, int posY, int width, int height, const char* fileName);
	~Editors();

	void setFileName(std::string fileName);
	const char* getFileName() const;
	int saveFile() const;
	void Delete();

	const char* test = "The editors class";
};

class Editor : public Editors {
public:
	Editor(int posX, int posY, int width, int height,
		const char* fileName);
	~Editor();


	void loadFile(const char* filePath);
	static void ConvertBtn_CB(Fl_Widget*, void*);

	void FindWord(const char*);
	void ReplaceAllWords(const char*, const char*);
	void ReplaceNextWord(const char*, const char*);
	
};

class Displayer : public Editors {
public:
	Displayer(int posX, int posY, int width, int height,
		const char* fileName);
	~Displayer();

	static void OpenBrowser_CB(Fl_Widget*, void*);
};
