# makefile

all: main test

TestMain: 
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic  -fstack-clash-protection -g -fno-omit-frame-pointer TestMain.cpp Graph.cpp Window.cpp GUI.cpp Game.cpp Player.cpp AI.cpp Node.cpp -lfltk -lfltk_images -lX11 -ljpeg 
	mv a.out main
	
testCode:	
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic  -fstack-clash-protection -g -fno-omit-frame-pointer test.cpp Graph.cpp Window.cpp GUI.cpp Game.cpp Player.cpp AI.cpp Node.cpp Start_screen.cpp score_screen.cpp initials_screen.cpp -lfltk -lfltk_images -lX11 -ljpeg 
	mv a.out test
	
	
main: TestMain	
	
test:testCode

	
clean:
	rm  main test
