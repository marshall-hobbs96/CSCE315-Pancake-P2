//SetOrder_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct SetOrder_window : Graph_lib::Window {
    
    SetOrder_window(Point xy, int w, int h, const string& title) : // User chooses game difficulty in this window
        Window(xy,w,h,title),
		input_order(Point(400,200),120,20,"SET ORDER PalaceHolder: "),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        running(true)
    {
		attach(input_order);
		attach(submit_button);
    }
    void wait_for_button(int* humanStack, int* AIStack)
    {
        Text title(Point(400,100),"Choose Your Order!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(40);
        attach(title);
        
        while(running) Fl::wait(0);
        hide();
    }
    
private:

	Button submit_button;
	In_box input_order;
    bool running;
	
	
	static void cb_submit(Address, Address pw){reference_to<SetOrder_window>(pw).submit();}
    void submit(){
		running = false;
	}

};