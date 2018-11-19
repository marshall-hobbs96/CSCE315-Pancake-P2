//Difficulty_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"
#include ".. /Main\ Code/include/Game.h"

using namespace Graph_lib;

struct Game_play_window : Graph_lib::Window {
    
    Game_play_window(Point xy, int w, int h, const string& title, Game* g) : // User chooses game difficulty in this window
        Window(xy,w,h,title),
        Game* curr_game = g,
		input_n(Point(400,200),50,20,"Please enter number of pancakes (2-9): "),
		input_d(Point(900,200),50,20,"Please enter difficulty (1-n): "),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        running(true)
    {
        attach(input_n);
        attach(input_d);
        attach(submit_button);
    }
    void wait_for_button(int &selection) // need to convert this to wait until 
    {
        Text title(Point(400,100),"Choose Your Settings!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(40);
        attach(title);
        
        while(running) Fl::wait(0);
        hide();
        draw_stack(curr_game->getStack(), false, -1); // false = human stack, true = AI stack
        selection = make_flip_selection();
        draw_stack(curr_game->getStack(), false, selection); // change color of cakes to be flipped temporarily
        curr_game->moveHuman(selection);
        draw_stack(curr_game->getStack(), false, -1); // draw updated stack
    }

    void draw_stack(int* stack, bool player, int flipFrom) { // ****************************

        //1280 x 720
        vector<Ellipse> ells; 

        if (player) { // sets cursor to draw User or AI stack
            // setdrawing cursor

            for (int i = 0; i < curr_game->getStackSize(); i++) {

                Ellipse* ell = new Ellipse(point(150, (i * 15) + 10 ), stack[(curr_game->getStackSize() - 1) - i] * 10, 10);
                ells.push_back(ell);
                attach(ells.at(i));
                ells.at(i).set_color(Color::red);


            // draw each pancake 
                if (i >= flipFrom) {
                    //draw pancake with different color
                    ells.at(i).set_color(Color::blue);
            }
        }


        }

        else {

            for (int i = 0; i < curr_game->getStackSize(); i++) {

                Ellipse* ell = new Ellipse(point(150, (i * 15) + 10 ), stack[(curr_game->getStackSize() - 1) - i] * 10, 10);
                ells.push_back(ell);
                attach(ells.at(i));
                ells.at(i).set_color(Color::red);


            // draw each pancake 
                if (i >= flipFrom) {
                    //draw pancake with different color
                    ells.at(i).set_color(Color::blue);
            }

        }
    }

    int make_flip_selection() {
        // draw arrow at top selection
        int selection = 0;
        bool selectionMade = false;

        while (!selectionMade) {
            // allow for keyboard input to update arrow position
            // if the enter key is pressed, set selection to the value and set selectionMade to true
        }

        return selection;
    }
    
    private:
        Game* curr_game;
        Button submit_button;
        bool running;
        
        
        static void cb_submit(Address, Address pw){reference_to<Game_play_window>(pw).submit();}
        void submit(){                                             //************************** need to convert to update selection value   ********          
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

};