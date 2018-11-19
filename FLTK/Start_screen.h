/////////////////////////////////
//		Start_screen.h		   //
//	for splash and instruction //
//			screens			   //
//							   //
//	Samantha Hay - 11/18/18	   //
/////////////////////////////////


#ifndef START_SCREEN_GUARD
#define START_SCREEN_GUARD 1


#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <vector>

using namespace Graph_lib;


struct Start_screen : Graph_lib::Window {
	Start_screen(Point xy, int w, int h, const string& title );
	void getSplashInput();//called from outside class to run screen
	void splashScreen();
	void instructionScreen();
	
	private:
	bool buttonClick;
	vector<Text*> text;
	
	//Splash Screen
	void titles();
	void members1();
	void members2();
	
	//Instructions Screen

	void instructionTitles();
	void goalStatment();
	void instructionStatements1();
	void instructionStatements2();
	void instructionStatements3();
	
	//Shared
	void run();
	static void button1(Address, Address);
	void change();
	
	
};
#endif
	