
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
    add("File/Save All", FL_CTRL+'s', SaveAll_CB, (void*)this);
    add("File/Quit", FL_CTRL+'q', Quit_CB, (void*)this);

    add("Edit/Find", FL_CTRL + 'f', Find_CB, (void*)this);
    add("Edit/Delete/Editor", FL_CTRL + 'd', Delete_CB, (void*)this);
    
    
    add("View/Show Shortcuts");

   /* add("Run/Generate Normal Html", FL_CTRL + 'r', Run_CB, (void*)this);
    add("Run/Open Normal HTML File in a Browser", FL_CTRL + 'o', OpenBrowser_CB, (void*)this);
    */
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

void Menu::Find_CB(Fl_Widget* w, void* object) {

    Fl_Window* findWindow     = new Fl_Window(310, 105, "Find and Replace");
    Fl_Input* WordInput       = new Fl_Input(70, 10, 210, 25, "Find");
    Fl_Input* replaceInput    = new Fl_Input(70, 40, 210, 25, "Replace");
    Fl_Button* findBtn        = new Fl_Button(10, 70, 90, 25, "Find");
    Fl_Button* replaceAllBtn  = new Fl_Button(105, 70, 90, 25, "Replace All");
    Fl_Button* replaceNextBtn = new Fl_Button(200, 70, 100, 25, "Replace Next");

    findWindow->show();

    findBtn->callback(FindBtn_CB, object);
    replaceAllBtn->callback(ReplaceAllBtn_CB, object);
    replaceNextBtn->callback(ReplaceNextBtn_CB, object);
}

void Menu::FindBtn_CB(Fl_Widget* input, void* object) {
    auto* input1 = (Fl_Input*)input->parent()->child(0);
    const char* word = input1->value();
    if (word[0] == '\0') {
        fl_alert("The word is blank!");
        return;
    }

    Menu* menu = (Menu*)object;
    menu->editor->FindWord(word);
}

void Menu::ReplaceAllBtn_CB(Fl_Widget* input, void* object) {
    Fl_Input* input1 = (Fl_Input*)input->parent()->child(0);
    Fl_Input* input2 = (Fl_Input*)input->parent()->child(1);
    
    const char* word = input1->value();
    const char* neWord = input2->value();
    
    if (word[0] == '\0' ) {
        fl_alert("You should enter a word to be replaced.");
        return;
    }

    Menu* menu = (Menu*)object;
    menu->editor->ReplaceAllWords(word, neWord);
}

void Menu::ReplaceNextBtn_CB(Fl_Widget* input, void* object) {
    Fl_Input* input1 = (Fl_Input*)input->parent()->child(0);
    Fl_Input* input2 = (Fl_Input*)input->parent()->child(1);
    
    const char* word = input1->value();
    const char* neWord = input2->value();

    if (word[0] == '\0') {
        fl_alert("You should enter a word to be replaced.");
        return;
    }

    Menu* menu = (Menu*)object;
    menu->editor->ReplaceNextWord(word, neWord);
}

void Menu::Delete_CB(Fl_Widget*, void* object) {
    Menu* menu = (Menu*)object;
    menu->editor->Delete();
    menu->displayer->Delete();
}

