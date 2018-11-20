#include "Start_screen.h"
#include "Game.h"
#include "score_screen.cpp"
#include "initials_screen.cpp"
#include "Difficulty_window.cpp"
#include "SetOrder_window.cpp"
#include "Game_window.cpp"
#include <iostream>
#include <string>

using namespace std;

void SplashTest(){
	Start_screen window(Point(200, 200), 1280, 720, "Pancake!");
	cout<<"When screen appears look at if there is an image of pancakes, a start button, and all the names of the team members.\nPress the start button."<<endl<<endl;
	
	string response1 = "n";
	string response2 = "n";
	string response3 = "n";
	window.splashScreen();
	window.hide();
	
	cout<<"Was the image present? (y/n): ";
	cin>>response1;
	cout<<"Was the start Button present? (y/n): ";
	cin>>response2;
	cout<<"Were the names present? (y/n): ";
	cin>>response3;
	
	cout<<endl;
	cout<<"Splash Screen tests: \n"<<"test 1: ";
	if(response1 == "y"){cout<<"PASS\ntest 2: ";}
	else{cout<<"FAIL\ntest 2: ";}
	if(response2 == "y"){cout<<"PASS\ntest 3: ";}
	else{cout<<"FAIL\ntest 2: ";}
	if(response3 == "y"){cout<<"PASS"<<endl<<endl;}
	else{cout<<"FAIL"<<endl<<endl;}
	window.hide();
}
void InstructionTest(){
	Start_screen window(Point(200, 200), 1280, 720, "Pancake!");
	cout<<"When screen appears look to see if there is \"Instructions\" writen at the top, a goals section and a how to play section.\nPress the continue button."<<endl<<endl;
	
	string response1 = "n";
	string response2 = "n";
	string response3 = "n";
	window.instructionScreen();
	window.hide();
	
	cout<<"Was the \"Instructions\" writen at the top? (y/n): ";
	cin>>response1;
	cout<<"Was there a goals section that was filled in? (y/n): ";
	cin>>response2;
	cout<<"Was there a how to play section what was filled in? (y/n): ";
	cin>>response3;
	
	cout<<endl;
	cout<<"Instruction Screen tests: \n"<<"test 1: ";
	if(response1 == "y"){cout<<"PASS\ntest 2: ";}
	else{cout<<"FAIL\ntest 2: ";}
	if(response2 == "y"){cout<<"PASS\ntest 3: ";}
	else{cout<<"FAIL\ntest 2: ";}
	if(response3 == "y"){cout<<"PASS"<<endl<<endl;}
	else{cout<<"FAIL"<<endl<<endl;}
	window.hide();
}
void getDifficultyTest(){
	int n, d;
	int *gameStack;
	
	string statement1 = "Enter invalid number of pancakes such as 12 and click submit\n";
	string statement2 = "Then enter another invalid combo such as 5 pancakes and difficulty 7\n";
	string statement3 = "Finally enter valid values such as 6 pancakes and difficulty 4\n";
	string question = "\nDid 2 error messages pop up and the valid values get printed to the terminal? (y/n) ";
	string answer = "n";
	
	cout << statement1 << statement2 << statement3;
	Difficulty_window window(Point(200, 200), 1280, 720, "Pancake!");
	window.wait_for_button(n, d);
	
	cout << "Number of pancakes: " << n << endl;
	cout << "Difficulty: " << d << endl;
	
	cout << question ;
	cin >> answer;
	
	cout<<"Get Difficulty Screen Test: ";
	if(answer == "y"){cout<<"PASS";}
	else{cout<<"FAIL!";}
	
	cout << endl << endl;
	
	window.hide();

	
}

void setOrderTest(){
	
	const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
	int *gameStack;
	int numOfPancakes;
	cout << "Enter the number of pancakes: ";
	cin >> numOfPancakes;
	
	string statements[3] = {"Enter the wrong number of pancakes like 4321 for 5 number of pancakes", "Enter the duplicate number of pancakes like 4421 for 5 number of pancakes", "Press random"};
	string questions[3] = {"Was there an alert message that popped up? (y/n) ", "Was there an alert message that popped up? (y/n) ", "Did it print a random stack on the terminal? (y/n) "};
	string answers[3] = {"n","n","n"};
	for (int i = 0; i < 3; i++)
	{
		cout << statements[i] << endl;
		SetOrder_window set_window(Point(200, 200), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
		gameStack = set_window.wait_for_button(numOfPancakes);
		if (i == 2)
		{
			for (int i = 0; i < numOfPancakes; i++)
			{
				cout << gameStack[i];
			}
			cout << endl;
			cout << questions[i] ;
			cin >> answers[i];
			break;
		}
		cout << questions[i] ;
		cin >> answers[i];
		set_window.hide();
	}
	
	cout<<endl;
	cout<<"Set Order Screen tests: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Test " << i+1 << ": ";
		if (answers[i] == "y")
			cout << "PASS" << endl;
		else 
			cout << "FAIL" << endl;
	}
	
}

void scoreTest() {
	const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
	vector<string> scores;
	string winner = "Sorry, the AI won!";
	
	for (int i = 0; i<5; i++) {
		scores.push_back("AA 00");
	}
	int num = 5;
	int* num1 = &num;
	Game * currGame = new Game(5,5,"testscores.txt",num1);
	
	//initials and score windows
	Initial_window initials_window(Point(150, 50), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	string initials = initials_window.wait_for_button(currGame->getScore());
	currGame->username = initials;
	currGame->writeScore();
	
	string resp1;
	string resp2;
	
	cout << "Were you able to write your initials? (y/n) ";
	cin >> resp1;
	if (resp1 == "y") { cout << "test1: PASS" << endl; }
	else { cout << "test1: FAIL" << endl; }
	
	score_screen score_window(Point(150, 50), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	bool playagain = score_window.show_scores(currGame->getHighScores(),"Game Over");
	
	cout << "Were you able to see your initials and score? (y/n) ";
	cin >> resp2;
	if (resp2 == "y") { cout << "test2: PASS" << endl << endl; }
	else { cout << "test2: FAIL" << endl << endl; }
	
	cout << "Initials: " << initials << endl;
	cout << "Continue: " << playagain << endl;	
}


void gameWindowTest() {
	const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
	int testArr[5]= {2,1,3,4,5};
	Game * currGame = new Game(5,3,"testScores.txt",testArr);
	bool game_won = false;
	while(game_won == false){
		Game_window game_window(Point(50, 50), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!", currGame);
		game_won = game_window.wait_for_button();
	}

	string statement1 = "Play game as normal to win. Flip using arrow buttons.\n";
	string question = "\nDid the pancakes flip as expected, and did the game quit when expected? (y/n) ";
	string answer = "n";
	
	cout << statement1;
	
	cout << question ;
	cin >> answer;
	
	cout<<"Game window Screen Test: ";
	if(answer == "y"){cout<<"PASS";}
	else{cout<<"FAIL!";}
	
	cout << endl << endl;
	

	
}


int main(){
	SplashTest();
	InstructionTest();
	getDifficultyTest();
	setOrderTest();
	scoreTest();
	gameWindowTest();
	
}
