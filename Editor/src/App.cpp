#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Button.H>

#include <stdlib.h>
#include "Editors.h"
#include "MenuBar.h"

static void Click_CB(Fl_Widget*, void*) {
    fl_message("Button clicked");
}

static void OpenBrowser_CB(Fl_Widget*, void*) {
    fl_message("Open in Browser Button has Clicked\n");
}
int main() {
    Fl_Window* window = new Fl_Window(g_window_width, g_window_height, "Editor");

    Menu* menu = new Menu(g_menu_x, g_menu_y, g_menu_width, g_menu_height);
    

    Fl_Text_Buffer* buf = new Fl_Text_Buffer(g_initial_buffer_size);

    Editor* editor = new Editor(buf, g_editor_x, g_editor_y, g_editor_width, g_editor_height, "Text Editor");
    Displayer* editor2 = new Displayer(buf, g_displayer_x, g_displayer_y, g_displayer_width, g_displayer_height, "Displayer");

    Fl_Button* convert = new Fl_Button(g_editor_width - 60, g_window_height - 35, 70, 30, "Convert");
    convert->callback(Click_CB);

    Fl_Button* openBrowser = new Fl_Button(g_window_width - 130, g_window_height - 35, 120, 30, "Open in Browser");
    openBrowser->callback(OpenBrowser_CB);
    
    window->resizable(editor);
    window->end();
    window->show();
    return(Fl::run());
}