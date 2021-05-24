#pragma once

#include "Globals.h"
#include "Editors.h"

class Menu : public Fl_Menu_Bar {
private:
	Editor *editor;
	Displayer *displayer;

	static void NewFile_CB(Fl_Widget*, void*);
	static void LoadFile_CB(Fl_Widget*, void*);
	static void SavePlusPlus_CB(Fl_Widget*, void*);
	static void SaveHtml_CB(Fl_Widget*, void*);
	static void SaveAll_CB(Fl_Widget*, void*);
	void Save(Editors*);
	static void Quit_CB(Fl_Widget*, void*);

	
	static void Find_CB(Fl_Widget*, void*);
	static void FindBtn_CB(Fl_Widget*, void*);
	static void ReplaceAllBtn_CB(Fl_Widget*, void*);
	static void ReplaceNextBtn_CB(Fl_Widget*, void*);
	static void Delete_CB(Fl_Widget*, void*);
	static void SelectAll_CB(Fl_Widget*, void*);
	static void SelectAllEditor_CB(Fl_Widget*, void*);
	static void SelectAllDisplayer_CB(Fl_Widget*, void*);

	static void ViewShortCuts_CB(Fl_Widget*, void*);

	static void Run_CB(Fl_Widget*, void*);
	static void OpenBrowser_CB(Fl_Widget*, void*);

public:
	Menu(unsigned menu_x, unsigned menu_y, unsigned menu_width, unsigned menu_height);
	~Menu();
};
