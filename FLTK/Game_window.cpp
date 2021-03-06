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
        curr_game(game), curr_selection(-1),
        running(true), p_selected(false)
    {
		attach(submit_button);
    }
    bool wait_for_button()
    {

        vector<Button*>cake_buttons;

        Button* p1 = new Button(Point(150, 120), 60, 40, "-->",button1);
        Button* p2 = new Button(Point(150, 180), 60, 40, "-->",button2);
        Button* p3 = new Button(Point(150, 240), 60, 40, "-->",button3);
        Button* p4 = new Button(Point(150, 300), 60, 40, "-->",button4);
        Button* p5 = new Button(Point(150, 360), 60, 40, "-->",button5);
        Button* p6 = new Button(Point(150, 420), 60, 40, "-->",button6);
        Button* p7 = new Button(Point(150, 480), 60, 40, "-->",button7);
        Button* p8 = new Button(Point(150, 540), 60, 40, "-->",button8);
        Button* p9 = new Button(Point(150, 600), 60, 40, "-->",button9);

        cake_buttons.push_back(p1);
        cake_buttons.push_back(p2);
        cake_buttons.push_back(p3);
        cake_buttons.push_back(p4);
        cake_buttons.push_back(p5);
        cake_buttons.push_back(p6);
        cake_buttons.push_back(p7);
        cake_buttons.push_back(p8);
        cake_buttons.push_back(p9);
        
        for (int i = 0; i < curr_game->getStackSize(); i++) {
            attach(*cake_buttons[i]);
        }

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
        int human_selection = -1;
        show();
        while(!p_selected) {
            //cout << "in loop" << endl;
            Fl::wait();
        }

        human_selection = curr_selection - 1;

        cout << "curr selection: " << curr_selection << endl;
        //Fl::wait();
        p_selected = true;
        Fl::redraw();

        int humanFlip = curr_game->getStackSize() - human_selection;

        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsHuman[j]);
            detach(*humanNums[j]);
            delete ellsHuman[j];
            delete humanNums[j];

        }

        drawPancakes(curr_game->getHumanStack(), ellsHuman, humanNums, curr_game->getStackSize(), true, humanFlip);
        curr_game->moveHuman(humanFlip - 1);

        cout << "Human selection: " << human_selection << endl;

        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsHuman[j]);
            detach(*humanNums[j]);
            delete ellsHuman[j];
            delete humanNums[j];

        }
        cout << "before" << endl;
        int* temp_stack = curr_game->getHumanStack();
        for(int k = 0; k < curr_game->getStackSize(); k ++) {

            cout << temp_stack[k] << endl;

        }

        drawPancakes(curr_game->getHumanStack(), ellsHuman, humanNums, curr_game->getStackSize(), true, -1);
        
        cout << "after" << endl;


        int AI_selection = curr_game->getAIMove();
        int AIFlip = curr_game->getStackSize() - AI_selection;

        

        for(int j = 0; j < curr_game->getStackSize(); j++){

            detach(*ellsAI[j]);
            detach(*AINums[j]);
            delete ellsAI[j];
            delete AINums[j];

        }

        drawPancakes(curr_game->getAIStack(), ellsAI, AINums, curr_game->getStackSize(), false, AIFlip);
        curr_game->moveAI(AIFlip - 1);



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
        for (int i = 0; i < 9; i++) {
            delete cake_buttons[i];
        }

        //add return win condition from curr_game++++++++++++++++++++++++++
        bool win = curr_game->checkWin();
        hide();
        return win;
    }
    
private:

	Button submit_button;
    bool running;
    Game* curr_game;
    int curr_selection;
    bool p_selected;
	
	
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

    static void button1(Address,Address pw){reference_to<Game_window>(pw).change1();}
    static void button2(Address,Address pw){reference_to<Game_window>(pw).change2();}
    static void button3(Address,Address pw){reference_to<Game_window>(pw).change3();}
    static void button4(Address,Address pw){reference_to<Game_window>(pw).change4();}
    static void button5(Address,Address pw){reference_to<Game_window>(pw).change5();}
    static void button6(Address,Address pw){reference_to<Game_window>(pw).change6();}
    static void button7(Address,Address pw){reference_to<Game_window>(pw).change7();}
    static void button8(Address,Address pw){reference_to<Game_window>(pw).change8();}
    static void button9(Address,Address pw){reference_to<Game_window>(pw).change9();}

    void change1() {curr_selection = 1; p_selected = true;}
    void change2() {curr_selection = 2; p_selected = true;}
    void change3() {curr_selection = 3; p_selected = true;}
    void change4() {curr_selection = 4; p_selected = true;}
    void change5() {curr_selection = 5; p_selected = true;}
    void change6() {curr_selection = 6; p_selected = true;}
    void change7() {curr_selection = 7; p_selected = true;}
    void change8() {curr_selection = 8; p_selected = true;}
    void change9() {curr_selection = 9; p_selected = true;}



};