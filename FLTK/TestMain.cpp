//#include "Start_window.h"
#include <FL/Fl_Text_Display.H>
#include "Difficulty_window.cpp"
#include "SetOrder_window.cpp"
//#include "Game_window.cpp"
//#include "InputName_window.cpp"
//#include "GameOver_window.cpp"

// vector<string> getScores(string &difficulty);
// void writeScores(vector<string>&, string);
int numOfPancakes, difficulty;
void start(bool&);

int main()
{
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
   
    //Start splash window
    //Start_window window(Point(200, 200), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
    //window.wait_for_button();
    
	bool run = true;
	start(run);
	
	// bool playagain = false;
	// do{
		// start(playagain);
	// }while(playagain);

    // return 0;
}
void start(bool &playagain)
{
	const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
	
	// select difficulty
	Difficulty_window diff_window(Point(200, 200), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	diff_window.wait_for_button(numOfPancakes, difficulty);
	int playerStack[numOfPancakes];
	int AIStack[numOfPancakes];
	
	SetOrder_window set_window(Point(200, 200), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	set_window.wait_for_button(playerStack, AIStack);

	// //Select difficulty window and store in string difficulty
    // string difficulty = "";
    // Difficulty_window diff_window(Point(200, 200), WINDOW_WIDTH, WINDOW_HEIGHT, "POOZLE!");
    // diff_window.wait_for_button(difficulty);
    // cout << ":: " << difficulty << endl;

	// //Receive name window and store in player_name
    // string player_name = "Anonymous";
	// InputName_window name_window(Point(200,200), WINDOW_WIDTH, WINDOW_HEIGHT, "POOZLE!");
	// name_window.wait_for_button(player_name);
	// cout << ":: " << player_name << endl;

	// //Prepare input file for game window
	// vector<string> scores = getScores(difficulty); 
	// //Game window
	// Game_window game_window(Point(200,200), WINDOW_WIDTH, WINDOW_HEIGHT, "POOZLE!", difficulty, scores, player_name);
    // game_window.wait_for_button();

	// //Game over window
	// GameOver_window gameover_window(Point(200,200), WINDOW_WIDTH, WINDOW_HEIGHT, "POOZLE!", scores, playagain);
	// gameover_window.wait_for_button();

	//writeScores(scores, difficulty);
	
	cout << "numOfPancakes = " << numOfPancakes << endl;
	cout << "difficulty = " << difficulty << endl;
}
