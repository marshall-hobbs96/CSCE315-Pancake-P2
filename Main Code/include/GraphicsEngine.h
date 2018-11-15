/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

GaphicsEngine.h - Interface for the Graphics Engine class
*/

#ifndef __GRAPHICS__        // For #including more than once
#define __GRAPHICS__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include "Game.h"

/************************************************
 * Main Class
 ***********************************************/

class GraphicsEngine {
private:
    Game* curr_game;

    // Helpers for drawing certain screens:
    void drawInstructions();      // to show the player how to play
	void screenPrompt(std::string text, int line);
    // void blinkPancakes(int p);    // blink pancakes at and above pancake p

public:

    // Constructor:
    GraphicsEngine(Game* g);
    GraphicsEngine();
    ~GraphicsEngine();
    void drawStack(vector<std::string> stringStack, WINDOW *window, int blinkFrom);
    void drawSelectionStack(WINDOW* stack_win, int highlight, int n_choices);
    int getFlipSelection(WINDOW* window, int testVal,int testStackSize);
    int keyPadInput(WINDOW* window, int highlight, int numChoices);
    int* generateStack(int stackSize, std::string stackState);
    // For drawing various screens:
    void drawSplashScreen();
    void drawDifficultyScreen();
    void drawOrderScreen();
    void drawScoresScreen();
    void drawEndScreen();

    // For getting input from various screens:
    bool getSplashInput();
    bool isWithinRange(char arg, int a, int b);
    int* getDifficultyInput();  
    int* getDifficultyInput(char testA, char testB);      // overloaded for test
                                    // so size of next array is determined...
    int* getOrderInput(int stackSize);
    std::string getScoresInput();
    bool getEndInput();

    // Facilitating gameplay:
    bool playGame(WINDOW* player_window, WINDOW* ai_window);
    void startGame(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order);
    int* gen_rand_stack(int* stack, int stackSize);
    vector<std::string> stackToString(int* stack, int stackSize);

    std::string getString();
};



#endif