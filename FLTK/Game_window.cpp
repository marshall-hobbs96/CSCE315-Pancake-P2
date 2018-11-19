//Game_window.cpp

#include "GUI.h"
#include "Graph.h"
#include <vector>
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct Game_window : Graph_lib::Window {
    
    Game_window(Point xy, int w, int h, const string& title) :
        Window(xy,w,h,title),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        running(true)
    {
		attach(submit_button);
    }
    void wait_for_button(int* gameStack)
    {
        Text title(Point(450,75),"Game Window!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(30);
        attach(title);

        Ellipse el1(Point(200,200),40,40);
        el1.set_fill_color(Color::red);

        Ellipse el2(Point(300,200),40,40);
        el2.set_fill_color(Color::blue);
        
        Ellipse el3(Point(400,200),40,40);
        el3.set_fill_color(Color::green);

        attach(el1);
        attach(el2);
        attach(el3);

        drawPancakes(gameStack);
        
        while(running) Fl::wait(0);
        hide();
    }
    
private:

	Button submit_button;
    bool running;
	
	
	static void cb_submit(Address, Address pw){reference_to<Game_window>(pw).submit();}
    void submit(){
		running = false;
	}

    void drawPancakes(int* stack){
    }

};