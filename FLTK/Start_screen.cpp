
#include "Start_screen.h"
#include <vector>

using namespace Graph_lib;


Start_screen::Start_screen(Point xy, int w, int h, const string& title ): Window(xy,w,h,title), buttonClick(false){}

void Start_screen::getSplashInput(){
	Image pancakeFun(Point(0,0), "Pancake1.jpg");
	attach(pancakeFun);
	Image pancakeFun2(Point(895,0), "pancake2.jpg");
	attach(pancakeFun2);
	Image pancakeFun3(Point(1085,564), "Pancake3.jpg");
	attach(pancakeFun3);
	Image pancakeFun4(Point(895,643), "Pancake4.jpg");
	attach(pancakeFun4);
	Button first(Point(895, 564), 190, 79, "Start",button1);
	
	attach(first);
	
	titles();
	for(int i = 0; i<(int) text.size();i++){
		detach(*text[i]);
	}
	detach(pancakeFun);
	detach(pancakeFun2);
	detach(pancakeFun3);
	detach(pancakeFun4);
	detach(first);
	text.clear();
	buttonClick = false;
	Button second(Point(600, 600), 100, 60, "Continue",button1);
	attach(second);
	instructions();
	for(int i = 0; i<(int) text.size();i++){
		detach(*text[i]);
	}
	detach(second);
	buttonClick = false;
	
}
void Start_screen::button1(Address,Address pw)
// call Simple_window::next() for the window located at pw
{  
	reference_to<Start_screen>(pw).change();
        
}

void Start_screen::change(){
	buttonClick = true;
}

void Start_screen::titles(){
	Text title(Point(300,100),"Ultimate Pancake Flipper Simulator 2018");
	title.set_font(Graph_lib::Font::helvetica_bold);
	title.set_font_size(40);
	text.push_back(&title);
	attach(title);
	
	Text team(Point(850,200),"**** Team 13 ****");
	team.set_font(Graph_lib::Font::helvetica_bold);
	team.set_font_size(30);
	text.push_back(&team);
	attach(team);

	Text members(Point(900,300),"Members:");
	members.set_font(Graph_lib::Font::helvetica_bold);
	members.set_font_size(30);
	text.push_back(&members);
	attach(members);
	
	members1();
	
}

void Start_screen::members1(){
	Text member4(Point(1050,450),"Hannah Hutton");
	member4.set_font(Graph_lib::Font::helvetica_bold);
	member4.set_font_size(25);
	text.push_back(&member4);
	attach(member4);
	
	Text member5(Point(750,500),"Jevika Jarmarwala");
	member5.set_font(Graph_lib::Font::helvetica_bold);
	member5.set_font_size(25);
	text.push_back(&member5);
	attach(member5);

	Text member6(Point(1050,500),"McLain Johnson");
	member6.set_font(Graph_lib::Font::helvetica_bold);
	member6.set_font_size(25);
	text.push_back(&member6);
	attach(member6);
	
	members2();
}
void Start_screen::members2(){
	Text member1(Point(750,400),"Leuel Asnake");
	member1.set_font(Graph_lib::Font::helvetica_bold);
	member1.set_font_size(25);
	text.push_back(&member1);
	attach(member1);
	
	Text member2(Point(1050,400),"Samantha Hay");
	member2.set_font(Graph_lib::Font::helvetica_bold);
	member2.set_font_size(25);
	text.push_back(&member2);
	attach(member2);
	
	Text member3(Point(750,450),"Marshall Hobbs");
	member3.set_font(Graph_lib::Font::helvetica_bold);
	member3.set_font_size(25);
	text.push_back(&member3);
	attach(member3);
	
	run();
}

void Start_screen::run(){
	show();
	while (!buttonClick){Fl::wait();}
	Fl::redraw();
}

void Start_screen::instructions(){
	Text title(Point(500,100),"Instructions");
	title.set_font(Graph_lib::Font::helvetica_bold);
	title.set_font_size(50);
	text.push_back(&title);
	attach(title);
	
	Text goal(Point(50,200),"Goal:");
	goal.set_font(Graph_lib::Font::helvetica_bold);
	goal.set_font_size(30);
	text.push_back(&goal);
	attach(goal);
	
	
	Text howToPlay(Point(50,350),"How To Play:");
	howToPlay.set_font(Graph_lib::Font::helvetica_bold);
	howToPlay.set_font_size(30);
	text.push_back(&howToPlay);
	attach(howToPlay);
	
	goalStatment();
	
	
}
void Start_screen::goalStatment(){
	Text goalS(Point(150,200),"Your goal is to sort a stack of pancakes from top to bottom (meaning the ");
	goalS.set_font(Graph_lib::Font::helvetica);
	goalS.set_font_size(27);
	text.push_back(&goalS);
	attach(goalS);
	
	Text goalS2(Point(150,240),"samllest pancake will be on the top and the largest on the bottom) before");
	goalS2.set_font(Graph_lib::Font::helvetica);
	goalS2.set_font_size(27);
	text.push_back(&goalS2);
	attach(goalS2);
	
	Text goalS3(Point(150,280),"the computer sorts a stack of pancakes identical to yours.");
	goalS3.set_font(Graph_lib::Font::helvetica);
	goalS3.set_font_size(27);
	text.push_back(&goalS3);
	attach(goalS3);
	
	run();
}
	
	//private:
	//void titles();
	//void members1();
	//void members2();
	//void instructions();
	//void goalStatment();
	//void run();
	//static void button1();
	//bool buttonClick;
	//vector<Text*> text;