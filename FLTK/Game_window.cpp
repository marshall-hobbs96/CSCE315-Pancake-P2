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
		submit_button(Point(530,y_max()-55), 200, 50, "Submit", cb_submit),
        curr_game(game),
        running(true)
    {
		attach(submit_button);
    }
    bool wait_for_button()
    {
        Text title(Point(500,75),"Game Window!");
        title.set_font(Graph_lib::Font::helvetica_bold);
        title.set_font_size(30);
        attach(title);

        Text player_title(Point(300, 100), "Player Stack");
        Text ai_title(Point(800, 100), "AI Stack");
        player_title.set_font(Graph_lib::Font::helvetica_bold);
        player_title.set_font_size(20);
        ai_title.set_font(Graph_lib::Font::helvetica_bold);
        ai_title.set_font_size(20);
        attach(player_title);
        attach(ai_title);

        Ellipse** ellsHuman = new Ellipse*[9];
        Text** humanNums = new Text*[9];
        Ellipse** ellsAI = new Ellipse*[9];
        Text** AINums = new Text*[9];

        drawPancakes(curr_game->getHumanStack(), ellsHuman, humanNums, curr_game->getStackSize(), true, -1);
        drawPancakes(curr_game->getAIStack(), ellsAI, AINums, curr_game->getStackSize(), false, -1);
        int AI_selection = curr_game->getAIMove();
        int AIFlip = curr_game->getStackSize() - AI_selection;

        

        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsAI[j]);
            detach(*AINums[j]);
            delete ellsAI[j];
            delete AINums[j];

        }

        drawPancakes(curr_game->getAIStack(), ellsAI, AINums, curr_game->getStackSize(), false, AIFlip);
        curr_game->moveAI(AI_selection);



        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsAI[j]);
            detach(*AINums[j]);
            delete ellsAI[j];
            delete AINums[j];

        }

        drawPancakes(curr_game->getAIStack(), ellsAI, AINums, curr_game->getStackSize(), false, -1);

        while(running) Fl::wait(0);

        delete ellsHuman;
        delete ellsAI;
        delete humanNums;
        delete AINums;

        //add return win condition from curr_game++++++++++++++++++++++++++

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

    static void cb_wait(void* ){
        
        sleep(3);
        return;
    }

    void drawPancakes(int* input_stack, Ellipse** ells, Text** text, int stack_size, bool player, int blink_from){

        int* stack = new int[9];

        for(int j = 0; j < stack_size; j++){

            stack[j] = input_stack[stack_size - 1 - j];

        }

        if(player == true){             //drawing player stack
            for(int i = 0; i < stack_size; i++) {
                
                ells[i] = new Ellipse(Point(360, 160 + 56 * i), 17 * stack[i], 27);
                ells[i]->set_fill_color(Color::red);
                string str = to_string(stack[i]);
                text[i] = new Text(Point(356, 165 + 56 * i), str);
                text[i]->set_font(Graph_lib::Font::helvetica_bold);
                text[i]->set_font_size(15);

                if(i >= blink_from) {           //the point from which the player chose to flip from

                    ells[i]->set_fill_color(Color::yellow);

                }

                attach(*ells[i]);
                attach(*text[i]);


            }

        }

        else{           //drawing AI stack

            for(int i = 0; i < stack_size; i++) {

                ells[i] = new Ellipse(Point(860, 160 + 56 * i), 17 * stack[i], 27);
                ells[i]->set_fill_color(Color::red);
                string str = to_string(stack[i]);
                text[i] = new Text(Point(856, 165 + 56 * i), str);
                text[i]->set_font(Graph_lib::Font::helvetica_bold);
                text[i]->set_font_size(15);

                if(i >= blink_from) {           //the point from which the player chose to flip from

                    ells[i]->set_fill_color(Color::yellow);

                }

                attach(*ells[i]);
                attach(*text[i]);


            }

        }
            return;


    }

};