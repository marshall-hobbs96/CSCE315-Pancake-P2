//initials_screen.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct Initial_window : Graph_lib::Window {
    
    Initial_window(Point xy, int w, int h, const string& title) : // User chooses game difficulty in this window
        Window(xy,w,h,title),
		input_initials(Point(665,200),50,20,"Please enter 2 initials: "),
		submit_button(Point(int(x_max()/2)-200,y_max()-300), 400, 100, "Submit", cb_submit),
		end_button(Point(int(x_max()/2)-100,y_max()-250), 400, 100, "End", cb_submit),
		running(true)
    {
        attach(input_initials);
        attach(submit_button);
    }
    string wait_for_button(int score)
    {
		running = true;
        Text title1(Point(450,100),"Your score is: ");
        title1.set_font(Graph_lib::Font::helvetica_bold);
        title1.set_font_size(40);
        attach(title1);
		
		Text title2(Point(800,100),to_string(score));
        title2.set_font(Graph_lib::Font::helvetica_bold);
        title2.set_font_size(40);
        attach(title2);
        while(running) Fl::wait(0);
        hide();
		running = true;
		return initials;
    }
    
private:
	In_box input_initials;
	Button submit_button;
	Button end_button;
	string initials;
    bool running;
	
	
	static void cb_submit(Address, Address pw){reference_to<Initial_window>(pw).submit();}
    void submit(){
		initials = input_initials.get_string();

		if(initials.size() != 2) {
			cout << "Invalid input!" << endl;
			running = true;
		}
		else	
			running = false;
	}

};