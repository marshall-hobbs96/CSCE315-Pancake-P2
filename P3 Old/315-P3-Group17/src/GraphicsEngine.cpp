/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

GraphicsEngine.cpp - Implementations for Engine methods for running the game and
        drawing the state to the screen. Includes methods for drawing specific
        screens, getting input from those screens, and facilitation of the gameplay.
        Uses ncurses to draw to the terminal window.
*/

#include "GraphicsEngine.h"
#include <boost/algorithm/string.hpp>

/*****************************************************
 * PRIVATE / PROTECTED METHODS
 ****************************************************/

/* Helpers for drawing certain screens */

// to show the player how to play
void GraphicsEngine::drawInstructions() {
    //print screen title
    std::string mesg ="INSTRUCTIONS";
    screenPrompt(mesg,0);
    mesg = "You and an Artificial Intelligence player will be given two versions";
    screenPrompt(mesg,1);
    mesg = "of the same stack of pancakes. Your goal is to sort the pancakes";
    screenPrompt(mesg,2);
    mesg = "from top to bottom (meaning the smallest pancake will be on the top";
    screenPrompt(mesg,3);
    mesg = " and the largest on bottom).";
    screenPrompt(mesg,4);
    mesg = "To do this, you will insert a spatula under any of the pancakes";
    screenPrompt(mesg,6);
    mesg = "in the (left) stack and 'flip' the pancakes at and above that pancake.";
    screenPrompt(mesg,7);
    mesg = "The blinking pancake will indicate which pancake your curser is on,";
    screenPrompt(mesg,8);
    mesg = "and hitting ENTER will select the pancake and flip the pancakes at";
    screenPrompt(mesg,9);
    mesg = "and above that pancake after blinking for a few seconds.";
    screenPrompt(mesg,10);
    mesg = "Here is an example pancake of size 6:";
    screenPrompt(mesg,12);
    mesg = "+-----------+";
    screenPrompt(mesg,14);
    mesg = "|     6     |";
    screenPrompt(mesg,15);
    mesg = "+-----------+";
    screenPrompt(mesg,16);
}

void GraphicsEngine::screenPrompt(std::string text, int line)
{
	int row,col;
	getmaxyx(stdscr,row,col);
	mvprintw(row/2+line,(col-text.size())/2,"%s",text.c_str());
    //delete mesg1;
}

/* Facilitating gameplay in playGame */

void GraphicsEngine::drawStack(vector<std::string> stringStack, WINDOW* window, int blinkFrom) {

    int real_blinkFrom = curr_game->getStackSize() - blinkFrom;

    real_blinkFrom = ((real_blinkFrom + 1)*3) - 1;

    wclear(window);
    if (blinkFrom != -1)
        //attrset(A_BOLD);
        wattrset(window, A_BLINK);

    for(int i = 0; i < (int) stringStack.size(); i++ ){
        if (i == real_blinkFrom - 2) {
            wattroff(window, A_BLINK);
        }
        int rows, cols;
	    getmaxyx(window, rows, cols);
	    std::string the_string = stringStack.at(i);
        mvwprintw(window, i + 2 + (0*rows), cols / 4, "%s", the_string.c_str());

    }

    wrefresh(window);
    if (blinkFrom > -1) sleep(3);
            wattroff(window, A_BLINK);
            //attroff(A_BOLD);

    return;
}
/*
void GraphicsEngine::drawStack(std::string stringStack, int stackSize, WINDOW* window, int blinkFrom) {

    for(int i = stackSize - 1; i >= 0; i-- ){
        if (i == blinkFrom)
            attrset(A_BLINK | A_BOLD);
        mvwprintw(window, 0, 0, "%s", stringStack[i]);
    }
    attroff(A_BLINK);
    attroff(A_BOLD);
    return;
}  */

void GraphicsEngine::drawSelectionStack(WINDOW* stack_win, int highlight, int numChoices) {
    vector<std::string> choices;
    choices = stackToString(curr_game->getHumanStack(),curr_game->getStackSize());
    int x, y, i;

    getmaxyx(stack_win, y, x);

    x /= 4;
    y = choices.size() + 1;

	for(i = 3*numChoices - 1; i >= 0; i--, y--) { // draw stack from bottom up
        if(highlight == i/3 + 1) {
            wattron(stack_win, A_REVERSE);  // toggle highlight effect
            mvwprintw(stack_win, y, x, "%s", choices[i].c_str());
            wattroff(stack_win, A_REVERSE);
        } else {
            mvwprintw(stack_win, y, x, "%s", choices[i].c_str());
        }
	}
	wrefresh(stack_win);

}



int GraphicsEngine::keyPadInput(WINDOW* window, int highlight, int numChoices) {
    int c, choice = 0;
    
    while(1) {
        c = wgetch(window); //get keystroke
		switch(c) {
            case KEY_UP:        // up arrow  or w pressed
            case 119:
            highlight = (highlight == 1) ? numChoices : highlight - 1;
		        break;
			case KEY_DOWN:      // down arrow or s key pressed
            case 115:
                highlight = (highlight == numChoices) ? 1 : highlight + 1;
                break;
			case 10:            //  enter key pressed 
				choice = highlight; 
                break;
			default:
				mvprintw(31, 0, "Invalid character.");
				refresh(); 
                break;
		}
        drawSelectionStack(window, highlight, numChoices); // draw stack with updated highlighter position
        if(choice != 0) 
            break;
        wrefresh(window);
    }
    return highlight;
}

int GraphicsEngine::getFlipSelection(WINDOW* window, int testVal, int testStackSize) {
    int highlight = 1;
    if (testVal == -1) {
        vector<std::string> choices;
        choices = stackToString(curr_game->getHumanStack(),curr_game->getStackSize());
        int numChoices = (this->curr_game->getStackSize());
        noecho();
        cbreak();
        keypad(window, TRUE);

        mvprintw(30, 0, "Use the Arrow Keys (or WASD) to go up and down,");
        mvprintw(31, 0, "then Press Enter to select a Pancake to insert the spatula below to flip.");
        refresh();
        wrefresh(window);

        drawSelectionStack(window, highlight, numChoices); //Draw initial stack with highlighter at first position
        refresh();
        wrefresh(window);
        
        highlight = keyPadInput(window, highlight, numChoices); //Accept keypad entry
        mvprintw(33, 0, "You chose the Pancake at position %d\n",highlight);
        refresh();
        wrefresh(window);
        return curr_game->getStackSize() - highlight; //return the adjusted selection
    } else { // test case
        highlight = testVal;
        return testStackSize - highlight; //return the adjusted selection
    }
    //return curr_game->getStackSize() - highlight; //return the adjusted selection
}

/*
void GraphicsEngine::blinkPancakes(int p) {
    // Implementation
}
*/

/*****************************************************
 * PUBLIC METHODS
 ****************************************************/

/* Default Constructor creates a dummy game with the file name so it can get scores */
GraphicsEngine::GraphicsEngine() {
    curr_game = new Game(0, 1, "scores.txt", NULL);
}

GraphicsEngine::GraphicsEngine(Game* g) : curr_game(g) {}

GraphicsEngine::~GraphicsEngine() {
    delete curr_game;
}

/* For drawing various screens */

void GraphicsEngine::drawSplashScreen() {
    //print screen title
    std::string mesg ="Ultimate Pancake Flipper Simulator 2018";
    screenPrompt(mesg,0);
    mesg = "****** Team 17 ******";
    screenPrompt(mesg,2);
    mesg = "Members:";
    screenPrompt(mesg,4);
    mesg = "Abdul Campos, Troy Fulton, Marshall Hobbs, McLain Johnson";
    screenPrompt(mesg,5);
    mesg = "Press ENTER to Start: ";
    screenPrompt(mesg,8);
    //int wattron(WINDOW *win, int attr);
    attrset(A_BLINK | A_BOLD);
    addstr("ENTER\n");
    attroff(A_BLINK);
    attroff(A_BOLD);
}

void GraphicsEngine::drawDifficultyScreen() {
    // Implementation
}

void GraphicsEngine::drawOrderScreen() {
    // Implementation
}

void GraphicsEngine::drawScoresScreen() {
  echo();
  std::string scores = curr_game->getHighScores();
  replace(scores.begin(),scores.end(), '\n', ' ');
	//print screen title
  vector<string> splitScores;
  boost::split(splitScores, scores, [](char c){return c == ' ';});
	screenPrompt("Top 5 Scores", -10);

  for(int i=1, j=0; (unsigned)i<splitScores.size(); i+=2, j++)
  {
    string curScore = splitScores[i]+" "+splitScores[i+1];
    screenPrompt(curScore, -9+j);
  }
}

void GraphicsEngine::drawEndScreen() {
  //in game: username and score
  //print username and scores
  curr_game->writeScore();
  drawScoresScreen();
}

/* For getting input from various screens */

bool GraphicsEngine::getSplashInput() {
    // Clear the screen
    clear();
    drawSplashScreen();
    getch();

    // Show instructions and wait for another "ENTER"
    clear();
    drawInstructions();
    getch();

    return true;
}

bool GraphicsEngine::isWithinRange(char arg, int a, int b) {
    int intArg = arg - '0';
    if (intArg >= a && intArg <= b)
        return true;
    return false;
}
int* GraphicsEngine::getDifficultyInput() {
    clear();
    noecho();
    refresh();

    char c;
    printw("Enter a number of pancakes from 2 to 9: ");
    while(!isWithinRange((c = getch()),2,9)) { // get num pancakes from keyboard
        printw("%c\n",c);
        clear();
        printw("Enter a number of pancakes from 2 to 9: ");
    }
    int numCakes = c - '0';
    clear();
    printw("Enter a number of pancakes from 2 to 9: %d",numCakes);
    printw("\nEnter a difficulty level from 1 to %d: ",numCakes);

    while(!isWithinRange((c = getch()),1,numCakes)) { // get difficulty from keyboard
        clear();
        printw("Enter a number of pancakes from 2 to 9: %d",numCakes);
        printw("\nEnter a difficulty level from 1 to %d: ",numCakes);
    }
    int diff = c - '0';
    int* result = new int[2]{numCakes,diff};
    printw("\nYou selected %d Pancakes at Difficulty %d. Press any key to continue.",numCakes,diff);
    getch();
    return result;


   return NULL;


}

int* GraphicsEngine::getDifficultyInput(char testA, char testB) { //overloaded for test

    clear();
    noecho();
    refresh();

    if (isWithinRange(testA,2,9) && isWithinRange(testB,1,(testA - '0'))) {
        int* result = new int[2]{(testA - '0'), (testB - '0')};
        return result;
    } else {
        return NULL;
    }
}

int* GraphicsEngine::generateStack(int stackSize, std::string stackState) {

    int* finalStack = new int[stackSize];
    int numbers[9] = {0,0,0,0,0,0,0,0,0};
    //std::string stackState = getString();       //string for getting user input

    if(stackState.size() == 0){                 //if user just puts enter...generate random order

        for(int i = 0; i < stackSize; i++){

            finalStack[i] = i + 1;              //fill with 1 - n for shuffle

        }

        finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random

    }

    else {
        int finalStackIterator = 0;                             //for iterating through the string, pulling ints
        for(int i = 0; i < (int) stackState.size(); i++){              //iterate through the user input string

            int temp = stackState.at(i) - '0';

            if((temp >= 0) && (temp <= 9)) {                    //if the input is an int, put it into final stack order

                finalStack[finalStackIterator] = temp;
                finalStackIterator++;
                numbers[temp - 1] += 1;

                if(numbers[temp - 1] > 1){

                    for(int i = 0; i < stackSize; i++){

                    finalStack[i] = i + 1;              //fill with 1 - n for shuffle

                    }

                    finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random
                    return finalStack;
                }

                else if(temp > stackSize) {

                    for(int i = 0; i < stackSize; i++){

                        finalStack[i] = i + 1;              //fill with 1 - n for shuffle

                    }

                    finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random
                    return finalStack;

                }

            }
        }

        if (finalStackIterator != (stackSize)) {            //stacksize is 5 and user put 1 2 3 4 or something like that

            for(int i = 0; i < stackSize; i++){

                finalStack[i] = i + 1;              //fill with 1 - n for shuffle

            }

            finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random

        }

    }

   return finalStack;

}

int* GraphicsEngine::getOrderInput(int stackSize) {
    clear();
    printw("Please specify initial stack order, i.e. 1, 2, 3, 4,.., n. Press enter for random order\n");
    std::string stackState = getString();       //string for getting user input
    int* finalStack = generateStack(stackSize, stackState);
    return finalStack;

}

int* GraphicsEngine::gen_rand_stack(int* stack, int stackSize) {

    bool not_shuffled = true;
     int* resultStack = stack; 
    while(not_shuffled){
        std::default_random_engine randomEngine(std::time(nullptr));            //random engine for running shuffle function
        std::shuffle(&stack[0], &stack[stackSize], randomEngine);               //shuffle the stack

	    for(int i =0; i<stackSize; i++)
	    {
		    if(stack[i]!=(stackSize-i)){
			    not_shuffled = true;
            }

            else{

                not_shuffled = false; 

            }
	    }

    }

    return resultStack;

}

std::string GraphicsEngine::getScoresInput() {
  drawScoresScreen();
  //replace for requesting user input
  std::string initials;
  do {
    int row,col;
  	getmaxyx(stdscr,row,col);
    move(row/2+6, 0);          // move to begining of line
    clrtoeol();
    screenPrompt("Enter your intials ", 6);
    char str[80];
    getstr(str);
     initials = std::string(str);
  } while(initials.size()>3||initials=="");

  curr_game->username = initials;
  screenPrompt(initials+": 0",2);
  return initials;
}

bool GraphicsEngine::getEndInput() {
    // Implementation
    clear();
    screenPrompt("Score: "+ curr_game->username + " " + to_string(curr_game->getScore()),0);
    screenPrompt("Press any key to continue",1);
    getch();
    clear();
    drawEndScreen();
    string cont;
    while(true){
      int row,col;
    	getmaxyx(stdscr,row,col);
      move(row/2+5, 0);          // move to begining of line
      clrtoeol();
      screenPrompt("Would you like to play again? (Y/N)",5);
      char str[80];
      getstr(str);
      cont = std::string(str);
      if(cont=="Y"||cont=="N")
        break;
    }
    clear();
    return cont=="Y"? true:false;
}


/* Facilitating gameplay */


bool GraphicsEngine::playGame(WINDOW* player_window, WINDOW* ai_window) {

    while (!curr_game->checkWin()) {
        // Player's move
        int player_selection = getFlipSelection(player_window,-1,-1);
        wprintw(player_window, "%i", player_selection);
        drawStack(stackToString(curr_game->getHumanStack(), curr_game->getStackSize()), player_window, player_selection);
        curr_game->moveHuman(player_selection);
        drawStack(stackToString(curr_game->getHumanStack(), curr_game->getStackSize()), player_window, -1);

        // AI's Move
        int AI_selection = curr_game->getAIMove();
        drawStack(stackToString(curr_game->getAIStack(), curr_game->getStackSize()), ai_window, AI_selection);
        curr_game->moveAI(AI_selection);
        drawStack(stackToString(curr_game->getAIStack(), curr_game->getStackSize()), ai_window, -1);
    }

    return getEndInput();
}

void GraphicsEngine::startGame(int num_pancakes, int ai_difficulty, std::string fn, int* starting_order) {
    Game* temp = curr_game;
    curr_game = new Game(num_pancakes, ai_difficulty, fn, starting_order);
    delete temp;
}

std::string GraphicsEngine::getString() {

   std::string input;

   nocbreak();
   echo();
   int ch = getch();

   while ( ch != '\n' )
   {
       input.push_back( ch );
       ch = getch();
   }

   return input;

}

vector<std::string> GraphicsEngine::stackToString(int* stack, int stackSize) {

    vector<std::string> stringStack;

    for(int i = stackSize - 1; i >= 0; i--){

	std::string pancakeString;

		for(int k = 0; k < 9 - stack[i]; k ++) {

			pancakeString = pancakeString + " ";

		}

        int pancakeSize = stack[i];
        pancakeString = pancakeString + "+";
        for(int k = 0; k < (2*pancakeSize - 1); k++) {

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+";

		for(int k = 0; k < 9 - stack[i]; k++){

			pancakeString = pancakeString + " ";

		}

        stringStack.push_back(pancakeString);
		pancakeString = "";

		for(int k = 0; k < 9 - stack[i]; k ++) {

			pancakeString = pancakeString + " ";

		}

        pancakeString = pancakeString + "|";

        for(int k = 0; k < ((pancakeSize - 1)); k++) {

            pancakeString = pancakeString + " ";

        }

        char number = stack[i] + '0';
        pancakeString = pancakeString + number;


        for(int k = 0; k < ((pancakeSize - 1)); k++) {

            pancakeString = pancakeString + " ";

        }

        pancakeString = pancakeString + "|";

		for(int k = 0; k < 9 - stack[i]; k ++) {

			pancakeString = pancakeString + " ";

		}

        stringStack.push_back(pancakeString);
		pancakeString = "";

		for(int k = 0; k < 9 - stack[i]; k ++) {

			pancakeString = pancakeString + " ";

		}

        pancakeString = pancakeString + "+";

        for(int k = 0; k < (2*pancakeSize - 1); k++){

            pancakeString = pancakeString + "-";

        }

        pancakeString = pancakeString + "+";

		for(int k = 0; k < 9 - stack[i]; k ++) {

			pancakeString = pancakeString + " ";

		}

        stringStack.push_back(pancakeString);
        pancakeString = "";

    }

    return stringStack;

}
