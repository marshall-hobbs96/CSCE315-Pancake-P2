	//SetOrder_window.cpp

	#include "GUI.h"
	#include "Graph.h"
	#include "FL/Fl_JPEG_Image.H"
	#include "FL/fl_ask.H"
	#include "std_lib_facilities_5.h"
	#include <array>
	#include <vector>
	#include <string>

	using namespace Graph_lib;

	struct SetOrder_window : Graph_lib::Window {
		
		SetOrder_window(Point xy, int w, int h, const string& title) : // User chooses order in this window
			Window(xy,w,h,title),
			input_order(Point(550,200),120,20,"Order of Pancakes: "),
			submit_button(Point(int(x_max()/2)-200,y_max()-200), 400, 100, "Submit", cb_submit),
			random_button(Point(750,200), 120, 20, "Random", cb_random),
			running(true),
			ran(false)
		{
			attach(input_order);
			attach(submit_button);
			attach(random_button);
		}
		
		int * wait_for_button(int n)
		{
			int* gameStack;
			while(running) Fl::wait(0);
			if (ran)
			{				
				int* finalStack = new int[n];
				for(int i = 0; i < n; i++){
					finalStack[i] = i + 1; 				//fill with 1 - n for shuffle
				}
				gameStack = gen_rand_stack(finalStack, n); //shuffle the stack, i.e. random
			}
			else{
				gameStack = generateStack(n, order);
			}
			hide();
			return gameStack;
		}
		
		int* generateStack(int stackSize, string stackState) {
		int* finalStack = new int[stackSize];
		int numbers[9] = {0,0,0,0,0,0,0,0,0};
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
						fl_alert("Since the order entered has duplicate numbers, the game is going to create a random stack");
						finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random
						return finalStack;
					}
					else if(temp > stackSize) {
						for(int i = 0; i < stackSize; i++){
							finalStack[i] = i + 1;              //fill with 1 - n for shuffle
						}
						fl_alert("Since you entered a number higher than the size of the stack, the game is going to create a random stack");
						finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random
						return finalStack;
					}
				}
			}
			if (finalStackIterator != (stackSize)) {            //stacksize is 5 and user put 1 2 3 4 or something like that
				for(int i = 0; i < stackSize; i++){
					finalStack[i] = i + 1;              //fill with 1 - n for shuffle
				}
				fl_alert("Since the wrong number of inputs were entered, the game is going to create a random stack");
				finalStack = gen_rand_stack(finalStack, stackSize);     //shuffle the stack, i.e. random
			}
	   return finalStack;
	}

		int* gen_rand_stack(int* stack, int stackSize) {
			bool not_shuffled = true;
			int* resultStack = stack; 
			while(not_shuffled){
				std::default_random_engine randomEngine(std::time(nullptr));            //random engine for running shuffle function
				std::shuffle(&stack[0], &stack[stackSize], randomEngine);               //shuffle the stack
				for(int i = 0; i< stackSize; i++)
				{
					if(stack[i]==(stackSize-i)){
						not_shuffled = true;
					}
					else{
						not_shuffled = false; 
					}
				}
			}
			return resultStack;
		}
		
	private:

		In_box input_order;
		Button submit_button;
		Button random_button;
		bool running;
		string order;
		bool ran = false;
		
		static void cb_submit(Address, Address pw){reference_to<SetOrder_window>(pw).submit();}
		void submit(){
			order = input_order.get_string();
			ran = false;
			running = false;
		}
		
		static void cb_random(Address, Address pw){reference_to<SetOrder_window>(pw).random();}
		void random(){
			ran = true;
			running = false;
		}
		
		

	};