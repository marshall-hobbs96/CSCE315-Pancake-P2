//Game_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct Game_window : Graph_lib::Window {
    
    Game_window(Point xy, int w, int h, const string& title) :
        Window(xy,w,h,title),
		input_order(Point(400,400),50,20,"SET ORDER: "),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        running(true)
    {
		attach(input_order);
		attach(submit_button);
    }
    void wait_for_button(int* humanStack, int* AIStack)
    {
        while(running) Fl::wait(0);
        hide();
    }
    
private:

	Button submit_button;
	In_box input_order;
    bool running;
	
	
	static void cb_submit(Address, Address pw){reference_to<Game_window>(pw).submit();}
    void submit(){
		running = false;
	}

};