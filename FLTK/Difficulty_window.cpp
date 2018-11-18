//Difficulty_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct Difficulty_window : Graph_lib::Window {
    
    Difficulty_window(Point xy, int w, int h, const string& title) : // User chooses game difficulty in this window
        Window(xy,w,h,title),
		input_n(Point(400,200),50,20,"Please enter number of pancakes (2-9): "),
		input_d(Point(900,200),50,20,"Please enter difficulty (1-n): "),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        running(true)
    {
        attach(input_n);
        attach(input_d);
        attach(submit_button);
    }
    void wait_for_button(int &numOfPancakes, int &difficulty)
    {
        Text title(Point(400,100),"Choose Your Settings!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(40);
        attach(title);
        
        while(running) Fl::wait(0);
        hide();
        numOfPancakes = n;
		difficulty = d;
    }
    
private:
    int n, d;
	In_box input_n;
	In_box input_d;
	Button submit_button;
    bool running;
	
	
	static void cb_submit(Address, Address pw){reference_to<Difficulty_window>(pw).submit();}
    void submit(){
		n = input_n.get_int();
		d = input_d.get_int();

		if(n < 2 || n > 9 || d < 1 || d > n) {
			// Text invalid_input(Point(500,200),"INVALID INPUT!"); // Causes SEGV fault, need to figure out why.
            // attach(invalid_input);
			cout << "Invalid input!" << endl;
			running = true;
		}
		else	
			running = false;
	}
	
    // static void cb_easy(Address, Address pw){reference_to<Difficulty_window>(pw).easy();}
    // void easy(){difficulty = string("easy"); running = false;}

    // static void cb_medium(Address, Address pw){reference_to<Difficulty_window>(pw).medium();}
    // void medium(){difficulty = string("medium"); running = false;}

    // static void cb_hard(Address, Address pw){reference_to<Difficulty_window>(pw).hard();}
    // void hard(){difficulty = string("hard"); running = false;}

    // static void cb_extreme(Address, Address pw){reference_to<Difficulty_window>(pw).extreme();}
    // void extreme(){difficulty = string("extreme"); running = false;}

};