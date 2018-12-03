# makefile

all: main

Main: 
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fstack-clash-protection -g -fno-omit-frame-pointer main.cpp Player.cpp Node.cpp Game.cpp AI.cpp -lpython2.7
	mv a.out main
	
	
main: Main

	
clean:
	rm  main
