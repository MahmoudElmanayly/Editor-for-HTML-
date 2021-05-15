#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Button.H>

#include <stdlib.h>
#include "Editors.h"
#include "MenuBar.h"

int main() {
    Fl_Window* window = new Fl_Window(g_window_width, g_window_height, "Editor");

    

    Menu* menu = new Menu(g_menu_x, g_menu_y, g_menu_width, g_menu_height);

    Fl_Button* convert = new Fl_Button(g_editor_width - 60, g_window_height - 35, 70, 30, "Convert");
    convert->callback(Editor::ConvertBtn_CB);

    Fl_Button* openBrowser = new Fl_Button(g_window_width - 130, g_window_height - 35, 120, 30, "Open in Browser");

    window->end();
    window->show();
    return(Fl::run());
}