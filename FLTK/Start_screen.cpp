/////////////////////////////////
//		Start_screen.cpp	   //
//	for splash and instruction //
//			screens			   //
//							   //
//	Samantha Hay - 11/18/18	   //
/////////////////////////////////


#include "Start_screen.h"
#include <vector>

using namespace Graph_lib;

//creates window
Start_screen::Start_screen(Point xy, int w, int h, const string& title ): Window(xy,w,h,title), buttonClick(false){}

void Start_screen::getSplashInput(){
	//runs the two screens
	splashScreen();
	instructionScreen();
	
}
void Start_screen::splashScreen(){
//sets up the splash screen, runs it and then clears it.
	//adding background image and button
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
	
	titles();//writing text and running
	
	//detaching all text and buttons
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
}

void Start_screen::instructionScreen(){
//sets up the instructions screen, runs it and clears it
	//creating button
	Button second(Point(600, 600), 100, 60, "Continue",button1);
	attach(second);
	
	//adding text and running
	instructionTitles();
	
	//clearing screen
	for(int i = 0; i<(int) text.size();i++){
		detach(*text[i]);
	}
	detach(second);
	buttonClick = false;
	
}

void Start_screen::button1(Address,Address pw)
// call Start_screen::change() for the window located at pw
{  
	reference_to<Start_screen>(pw).change();
        
}

void Start_screen::change(){
//lets run function know that it is done
	buttonClick = true;
}

void Start_screen::titles(){
	//Game title
	Text title(Point(300,100),"Ultimate Pancake Flipper Simulator 2018");
	title.set_font(Graph_lib::Font::helvetica_bold);
	title.set_font_size(40);
	title.set_color(Color::black);
	text.push_back(&title);
	attach(title);
	
	//team title
	Text team(Point(850,200),"**** Team 13 ****");
	team.set_font(Graph_lib::Font::helvetica_bold);
	team.set_font_size(30);
	team.set_color(Color::black);
	text.push_back(&team);
	attach(team);
	
	//member title
	Text members(Point(900,300),"Members:");
	members.set_font(Graph_lib::Font::helvetica_bold);
	members.set_font_size(30);
	members.set_color(Color::black);
	text.push_back(&members);
	attach(members);
	
	//for name text
	members1();
	
}

void Start_screen::members1(){
//writes half the members names
	Text member4(Point(1050,450),"Hannah Hutton");
	member4.set_font(Graph_lib::Font::helvetica_bold);
	member4.set_font_size(25);
	member4.set_color(Color::black);
	text.push_back(&member4);
	attach(member4);
	
	Text member5(Point(750,500),"Jeevika Jarmarwala");
	member5.set_font(Graph_lib::Font::helvetica_bold);
	member5.set_font_size(25);
	member5.set_color(Color::black);
	text.push_back(&member5);
	attach(member5);

	Text member6(Point(1050,500),"McLain Johnson");
	member6.set_font(Graph_lib::Font::helvetica_bold);
	member6.set_font_size(25);
	member6.set_color(Color::black);
	text.push_back(&member6);
	attach(member6);
	
	//for other half of names
	members2();
}
void Start_screen::members2(){
//writes half the members names
	Text member1(Point(750,400),"Leuel Asnake");
	member1.set_font(Graph_lib::Font::helvetica_bold);
	member1.set_font_size(25);
	member1.set_color(Color::black);
	text.push_back(&member1);
	attach(member1);
	
	Text member2(Point(1050,400),"Samantha Hay");
	member2.set_font(Graph_lib::Font::helvetica_bold);
	member2.set_font_size(25);
	member2.set_color(Color::black);
	text.push_back(&member2);
	attach(member2);
	
	Text member3(Point(750,450),"Marshall Hobbs");
	member3.set_font(Graph_lib::Font::helvetica_bold);
	member3.set_font_size(25);
	member3.set_color(Color::black);
	text.push_back(&member3);
	attach(member3);
	
	//to run screen
	run();
}

void Start_screen::run(){
//shows screen and waits for the button to be clicked
	show();
	while (!buttonClick){Fl::wait();}
	Fl::redraw();
}

void Start_screen::instructionTitles(){
	//screen title
	Text title(Point(500,100),"Instructions");
	title.set_font(Graph_lib::Font::helvetica_bold);
	title.set_font_size(50);
	title.set_color(Color::black);
	text.push_back(&title);
	attach(title);
	
	//goals title
	Text goal(Point(50,200),"Goal:");
	goal.set_font(Graph_lib::Font::helvetica_bold);
	goal.set_font_size(30);
	goal.set_color(Color::black);
	text.push_back(&goal);
	attach(goal);
	
	//how to play title
	Text howToPlay(Point(50,350),"How To Play:");
	howToPlay.set_font(Graph_lib::Font::helvetica_bold);
	howToPlay.set_font_size(30);
	howToPlay.set_color(Color::black);
	text.push_back(&howToPlay);
	attach(howToPlay);
	
	//print the goal statment
	goalStatment();
	
	
}
void Start_screen::goalStatment(){
	//first line
	Text goalS(Point(150,200),"Your goal is to sort a stack of pancakes from top to bottom (meaning the ");
	goalS.set_font(Graph_lib::Font::helvetica);
	goalS.set_font_size(27);
	goalS.set_color(Color::black);
	text.push_back(&goalS);
	attach(goalS);
	//second line
	Text goalS2(Point(150,240),"smallest pancake will be on the top and the largest on the bottom) before");
	goalS2.set_font(Graph_lib::Font::helvetica);
	goalS2.set_font_size(27);
	goalS2.set_color(Color::black);
	text.push_back(&goalS2);
	attach(goalS2);
	//third line
	Text goalS3(Point(150,280),"the computer sorts a stack of pancakes identical to yours.");
	goalS3.set_font(Graph_lib::Font::helvetica);
	goalS3.set_font_size(27);
	goalS3.set_color(Color::black);
	text.push_back(&goalS3);
	attach(goalS3);
	
	//run screen
	run();
}