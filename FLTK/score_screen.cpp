//Score_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct score_screen : Graph_lib::Window {
    
    score_screen(Point xy, int w, int h, const string& title) : // User chooses game difficulty in this window
        Window(xy,w,h,title),
		restart_button(Point(int(x_max()/2)-250,y_max()-100), 200, 50, "Yes", cb_restart),
		end_button(Point(int(x_max()/2)+100,y_max()-100), 200, 50, "No", cb_end),
        screen(true)
    {
        attach(restart_button);
        attach(end_button);
    }
	bool show_scores(vector<string> scores, string winner) {
		Text title1(Point(500,175),"High Scores");
        title1.set_font(Graph_lib::Font::helvetica_bold);
        title1.set_font_size(50);
        attach(title1);
		
		Text title2(Point(375,550),"Do you want to play again?");
        title2.set_font(Graph_lib::Font::helvetica_bold);
        title2.set_font_size(40);
        attach(title2);
		
		Text title3(Point(475,100),winner);
        title3.set_font(Graph_lib::Font::helvetica_bold);
        title3.set_font_size(40);
        attach(title3);
		
		Text score1(Point(610,250),scores.at(0));
        score1.set_font(Graph_lib::Font::helvetica_bold);
        score1.set_font_size(35);
        attach(score1);
		Text score2(Point(610,300),scores.at(1));
        score2.set_font(Graph_lib::Font::helvetica_bold);
        score2.set_font_size(35);
        attach(score2);
		Text score3(Point(610,350),scores.at(2));
        score3.set_font(Graph_lib::Font::helvetica_bold);
        score3.set_font_size(35);
        attach(score3);
		Text score4(Point(610,400),scores.at(3));
        score4.set_font(Graph_lib::Font::helvetica_bold);
        score4.set_font_size(35);
        attach(score4);
		Text score5(Point(610,450),scores.at(4));
        score5.set_font(Graph_lib::Font::helvetica_bold);
        score5.set_font_size(35);
        attach(score5);
		
        while(screen) Fl::wait(0);
        hide();
		return running;
	}
    
private:
	Button restart_button;
	Button end_button;
    bool screen;
	bool running;
	
	
	static void cb_end(Address, Address pw){reference_to<score_screen>(pw).end();}
    void end(){
		screen = false;
		running = false;
	}
	
	static void cb_restart(Address, Address pw){reference_to<score_screen>(pw).restart();}
    void restart(){
		screen = false;
		running = true;
	}

};