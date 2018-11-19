#include "Start_screen.h"
#include "score_screen.cpp"
#include "initials_screen.cpp"
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

void scoreTest() {
	const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
	vector<string> scores;
	int newscore = 0;
	string winner = "Sorry, the AI won!";
	
	for (int i = 0; i<5; i++) {
		scores.push_back("AA 00");
	}
	
	
	Game * currGame = new Game(numOfPancakes,difficulty,"scores.txt",gameStack);
	
	//initials and score windows
	Initial_window initials_window(Point(150, 50), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	string initials = initials_window.wait_for_button(currGame->getScore());
	currGame->username = initials;
	currGame->writeScore();
	
	Score_window score_window(Point(150, 50), WINDOW_WIDTH, WINDOW_HEIGHT, "Pancake!");
	playagain = score_window.show_scores(currGame->getHighScores(),"Sorry, the AI won!");
	
	cout << "Initials: " << initials << endl;
	cout << "Continue: " << cont << endl;	
}

int main(){
	SplashTest();
	InstructionTest();
	scoreTest();
}