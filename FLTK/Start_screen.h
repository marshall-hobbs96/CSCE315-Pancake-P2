#ifndef START_SCREEN_GUARD
#define START_SCREEN_GUARD 1


#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <vector>

using namespace Graph_lib;


struct Start_screen : Graph_lib::Window {
	Start_screen(Point xy, int w, int h, const string& title );
	void getSplashInput();
	
	private:
	void titles();
	void members1();
	void members2();
	void instructions();
	void goalStatment();
	void run();
	static void button1(Address, Address);
	void change();
	bool buttonClick;
	vector<Text*> text;
};
#endif
	