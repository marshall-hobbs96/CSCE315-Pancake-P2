
#include "includecatch2.cpp"
#include "../include/AI.h"     // because main is in includecatch2.cpp
#include "../include/Player.h"     // because main is in includecatch2.cpp
#include "../include/Game.h"     // because main is in includecatch2.cpp
#include "../include/GraphicsEngine.h"     // because main is in includecatch2.cpp

TEST_CASE( "AI Test calculateMove 1", "[single-file]" ) {
    //int* stack = new int[4]{1, 2, 4, 3};
    AI tester(4, NULL, 1);
    int* solution = new int[4]{1, 2, 3, 4};
    int AImove = tester.calculateMove();
    CHECK( AImove == 2 );
    tester.makeMove(AImove);
    REQUIRE( tester.getStack()[2] == solution[2] );
}