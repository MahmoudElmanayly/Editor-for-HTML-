#pragma once

#include "Globals.h"

class Menu : public Fl_Menu_Bar {

public:
	Menu(unsigned menu_x, unsigned menu_y, unsigned menu_width, unsigned menu_height);
	~Menu();
};
