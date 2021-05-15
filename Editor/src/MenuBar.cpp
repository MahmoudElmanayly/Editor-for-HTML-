
#include "Globals.h"
#include "MenuBar.h"
#include "Editors.h"

Menu::Menu(unsigned menu_x, unsigned menu_y, unsigned menu_width, unsigned menu_height)
	:Fl_Menu_Bar(menu_x, menu_y, menu_width, menu_height)
{
    this->editor = new Editor(g_editor_x, g_editor_y, g_editor_width, g_editor_height, "No File Selected");
    this->displayer = new Displayer(g_displayer_x, g_displayer_y, g_displayer_width, g_displayer_height, "Displayer");

    add("File/New File", FL_CTRL + 'n', NewFile_CB, (void*)this);
    add("File/Load File", FL_CTRL+'l', LoadFile_CB, (void*)this);
    add("File/Save/New HTML Style File", FL_CTRL+'e', SavePlusPlus_CB, (void*)this);
    add("File/Save/Normal HTML File", FL_CTRL + 'h', SaveHtml_CB, (void*)this);
    add("File/Save All", FL_CTRL+'a', SaveAll_CB, (void*)this);
    add("File/Quit", FL_CTRL+'q', Quit_CB, (void*)this);

    add("Edit/Search Word");
    add("Edit/Find and Replace");
    add("Edit/Delete/New HTML Style");
    add("Edit/Delete/Normal HTML");
    add("Edit/Select All/New HTML Style");
    add("Edit/Select All/Normal HTML");

    add("View/Show Shortcuts");

    add("Run/Generate Normal Html");
    add("Run/Open Normal HTML File in a Browser");
}

Menu::~Menu(){}

void Menu::NewFile_CB(Fl_Widget* w, void* object) {
    Fl_Native_File_Chooser* chooser = new Fl_Native_File_Chooser();
    chooser->title("create a new file");
    chooser->show();
    
    if (chooser->filename() == NULL) {
        fl_message("No File Selected");
        return;
    }

    Menu* menu = (Menu*)object;
    menu->editor->loadFile(chooser->filename());
}

void Menu::LoadFile_CB(Fl_Widget*, void* object) {
   
    Fl_Native_File_Chooser *chooser = new Fl_Native_File_Chooser();
    chooser->show();

    if (chooser->filename() == NULL) {
        fl_message("No File Selected");
        return;
    }

    Menu* menu = (Menu*)object;
    menu->editor->loadFile(chooser->filename());
}

void Menu::SavePlusPlus_CB(Fl_Widget*, void* object) {
    Menu* menu = (Menu*)object;
    menu->Save(menu->editor);
    std::cout << "Plus Plus file saved\n";
}

void Menu::SaveHtml_CB(Fl_Widget*, void* object) {
    Menu* menu = (Menu*)object;
    menu->Save(menu->displayer);
    std::cout << "Html File saved\n";
}

void Menu::SaveAll_CB(Fl_Widget*, void* object) {
    Menu* menu = (Menu*)object;
    menu->Save(menu->editor);
    menu->Save(menu->displayer);
}

void Menu::Save(Editors* e) {
    int status = e->saveFile();
    if (status != 0) {
        fl_alert("Error: Could not save file");
    }
    else {
        fl_message("File Saved");
    }
}

void Menu::Quit_CB(Fl_Widget*, void*) {
    std::exit(0);
}