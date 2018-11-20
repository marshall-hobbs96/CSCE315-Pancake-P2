//Game_window.cpp

#include "GUI.h"
#include "Graph.h"
#include "Game.h"
#include <vector>
#include "FL/Fl_JPEG_Image.H"
#include "std_lib_facilities_5.h"

using namespace Graph_lib;

struct Game_window : Graph_lib::Window {
    
    Game_window(Point xy, int w, int h, const string& title, Game* game) :
        Window(xy,w,h,title),
		submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
        curr_game(game),
        running(true)
    {
		attach(submit_button);
    }
    bool wait_for_button()
    {
        Text title(Point(450,75),"Game Window!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(30);
        attach(title);

        Ellipse** ellsHuman = new Ellipse*[9];
        Ellipse** ellsAI = new Ellipse*[9];

        drawPancakes(curr_game->getHumanStack(), ellsHuman, curr_game->getStackSize(), true, -1);
        drawPancakes(curr_game->getAIStack(), ellsAI, curr_game->getStackSize(), false, -1);
        int AI_selection = curr_game->getAIMove();
        int AIFlip = curr_game->getStackSize() - AI_selection;

        

        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsAI[j]);
            delete ellsAI[j];

        }
        drawPancakes(curr_game->getAIStack(), ellsAI, curr_game->getStackSize(), false, AIFlip);
        curr_game->moveAI(AI_selection);



        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsAI[j]);
            delete ellsAI[j];

        }

        drawPancakes(curr_game->getAIStack(), ellsAI, curr_game->getStackSize(), false, -1);

        while(running) Fl::wait(0);

        delete ellsHuman;
        delete ellsAI;
        hide();
    }
    
private:

	Button submit_button;
    bool running;
    Game* curr_game;
	
	
	static void cb_submit(Address, Address pw){reference_to<Game_window>(pw).submit();}
    void submit(){
		running = false;
	}

    void drawPancakes(int* stack, Ellipse** ells, int stack_size, bool player, int blink_from){

        if(player == true){             //drawing player stack
            for(int i = 0; i < stack_size; i++) {

                ells[i] = new Ellipse(Point(100, 200 + 20 * i), 15 * stack[i], 10);
                ells[i]->set_fill_color(Color::red);

                if(i >= blink_from) {           //the point from which the player chose to flip from

                    ells[i]->set_fill_color(Color::blue);

                }

                attach(*ells[i]);


            }

        }

        else{           //drawing AI stack

            for(int i = 0; i < stack_size; i++) {

                ells[i] = new Ellipse(Point(500, 200 + 20 * i), 15 * stack[i], 10);
                ells[i]->set_fill_color(Color::red);

                if(i >= blink_from) {           //the point from which the player chose to flip from

                    ells[i]->set_fill_color(Color::blue);

                }

                attach(*ells[i]);


            }

        }
            return;


    }

};