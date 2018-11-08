# makefile

all: main

AI.o: Player.o
	# AI...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/AI.cpp

Node.o:
	# Node...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Node.cpp

Player.o: 
	# Player...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Player.cpp

Game.o: Player.o AI.o
	# Game...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Game.cpp

GraphicsEngine.o: Game.o
	# Graphics Engine...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses1 -I include -c src/GraphicsEngine.cpp

# Tests:

test: test_AI test_Game test_Node test_Player test_GraphicsEngine
	# ... finished making tests

test_AI: AI.o Player.o Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I $(CATCH_SINGLE_INCLUDE):include -o bin/test_AI AI.o Player.o Node.o test/test_AI.cpp 

test_GraphicsEngine: GraphicsEngine.o Game.o AI.o Player.o Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o bin/test_GraphicsEngine AI.o Player.o Game.o GraphicsEngine.o Node.o test/test_GraphicsEngine.cpp 

test_Player: Player.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o bin/test_Player Player.o test/test_Player.cpp 

test_Node: Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o bin/test_Node Node.o test/test_Node.cpp 

test_Game: Player.o AI.o Node.o Game.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o bin/test_Game Player.o AI.o Node.o Game.o test/test_Game.cpp 

# Main:

main: GraphicsEngine.o Game.o AI.o Node.o Player.o
	# Main...
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include Node.o AI.o Player.o Game.o GraphicsEngine.o -o bin/main src/main.cpp 

clean:
	rm -r bin/main bin/test_* *.o 
