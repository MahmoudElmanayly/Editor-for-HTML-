
#include "MenuBar.h"

Menu::Menu(unsigned menu_x, unsigned menu_y, unsigned menu_width, unsigned menu_height)
	:Fl_Menu_Bar(menu_x, menu_y, menu_width, menu_height)
{
    add("File/Load File");
    add("File/Save/New HTML Style File");
    add("File/Save/Normal HTML File");
    add("File/Save All");
    add("File/Quit");

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