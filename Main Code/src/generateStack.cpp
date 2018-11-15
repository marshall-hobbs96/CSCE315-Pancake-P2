#include <iostream>
#include "Game.h"
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock



int* GraphicsEngine::getOrderInput(int stackSize) {
    

    int* getOrder(int stackSize) {
    

    printw("Please specify initial stack order, i.e. 1, 2, 3, 4,.., n. Press enter for random order\n");
    
        int* finalStack = new int[stackSize];
        std::string stackState = getString();       //string for getting user input

        if(stackState.size() == 0){                 //if user just puts enter...generate random order

            printw("initializing random initial stack\n");

            for(int i = 0; i < stackSize; i++){

                finalStack[i] = i + 1;              //fill with 1 - n for shuffle

            }

            finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random

        }

        else {
            printw("initializing predefined stack\n");
            int finalStackIterator = 0;                             //for iterating through the string, pulling ints
            for(int i = 0; i < stackState.size(); i++){              //iterate through the user input string

                int temp = stackState.at(i) - '0';
                
                if((temp >= 0) && (temp <= 9)) {                    //if the input is an int, put it into final stack order

                    finalStack[finalStackIterator] = temp;
                    finalStackIterator++;

                }
            }

            if (finalStackIterator != (stackSize)) {            //stacksize is 5 and user put 1 2 3 4 or something like that

                printw("Error, invalid number of arguments\n");
                return NULL; 

            }

        }
    

    return finalStack;

}


std::string getString() {

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

int* gen_rand_stack(int* stack, int stackSize) {

    std::default_random_engine randomEngine(std::time(nullptr));            //random engine for running shuffle function
    int* resultStack = new int[stackSize];                                  
    resultStack = stack;
    std::shuffle(&stack[0], &stack[stackSize], randomEngine);               //shuffle the stack 
    return resultStack;

}
