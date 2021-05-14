#pragma once

//############### Includes #####################
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_ask.H>

//############# End Includes ###################




//############# Variables  ##################

const unsigned g_line_number_width = 30;
const unsigned g_window_width = 1200;
const unsigned g_window_height = 600;

const unsigned g_menu_x = 0;
const unsigned g_menu_y = 0;
const unsigned g_menu_width = g_window_width;
const unsigned g_menu_height = 25;

const unsigned g_editor_x = 10;
const unsigned g_editor_y = g_menu_height + 20;
const unsigned g_editor_width = (g_window_width / 2) - 15;
const unsigned g_editor_height = g_window_height - g_menu_height - 60;

const unsigned g_displayer_x = g_editor_width + 20;
const unsigned g_displayer_y = g_editor_y;
const unsigned g_displayer_width = g_editor_width;
const unsigned g_displayer_height = g_editor_height;


const unsigned g_initial_buffer_size = 200;

//########## End variables ##################

//############# RGB Colors ##################

#define FL_SELECTION_COLOR fl_rgb_color(0, 122, 204)

#define FL_EDITOR_BG_COLOR fl_rgb_color(41, 51, 60)
#define FL_EDITOR_TXT_COLOR fl_rgb_color(255, 255, 255)
#define FL_EDITOR_KEYWORD_COLOR fl_rgb_color(0, 122, 204)
#define FL_EDITOR_STRING_COLOR fl_rgb_color(37, 205, 135)
#define FL_EDITOR_CURSOR_COLOR fl_rgb_color(200, 200, 200)

#define FL_DISPLAYER_BG_COLOR fl_rgb_color(255, 255, 255)
#define FL_DISPLAYER_TXT_COLOR fl_rgb_color(41, 51, 60)
#define FL_DISPLAYER_KEYWORD_COLOR fl_rgb_color(0, 122, 204)
#define FL_DISPLAYER_STRING_COLOR fl_rgb_color(37, 205, 135)
#define FL_DISPLAYER_CURSOR_COLOR fl_rgb_color(70, 70, 70)

//############ End RGB Colors ###############

//######### functions fo menu bar ###########

static void Change_CB(Fl_Widget* w, void*) {
    fl_message("In the Call Back");
}


//####### end functions fo menu bar #########