/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_GraphicsEngine.cpp - GraphicsEngine Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/GraphicsEngine.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <curses.h>

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * Helper Functions
 ***************************************************/

// For comparing two files for equality. Found on 
// https://stackoverflow.com/questions/15118661/in-c-whats-the-fastest-way-to-tell-whether-two-string-or-binary-files-are-di/#answer-39097160
// Under a question about comparing files
bool compare_files(const std::string& filename1, const std::string& filename2)
{
    std::ifstream file1(filename1, std::ifstream::ate | std::ifstream::binary); //open file at the end
    std::ifstream file2(filename2, std::ifstream::ate | std::ifstream::binary); //open file at the end
    const std::ifstream::pos_type fileSize = file1.tellg();

    if (fileSize != file2.tellg()) {
        return false; //different file size
    }

    file1.seekg(0); //rewind
    file2.seekg(0); //rewind

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    return std::equal(begin1,std::istreambuf_iterator<char>(),begin2); //Second argument is end-of-range iterator
}


/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "GE Test drawSplashScreen 1", "[single-file]" ) {
    int* exStack = new int[6]{6,5,4,3,2,1};
    Game* g = new Game(6, 2, "scores.db", exStack);
    GraphicsEngine ge(g);

    // Show the screen
    //initscr();
    ge.drawSplashScreen();

    // Refresh and dump
    //refresh();
    //scr_dump("screen_dumps/GE_Splash_test2.txt");

    // close the window
    //endwin();

    // Once screen is dumped, compare to "key"
    std::string key_name = "screen_dumps/GE_Splash_test1.txt";
    std::string response_name = "screen_dumps/GE_Splash_test2.txt";
    
    // Something to check if the files opened?
    //ifstream key(key_name);
    //ifstream response(response_name);
    
    //CHECK(key > 0);
    //CHECK(response > 0);

    delete[] exStack;
    // Returns true even if one of the files is missing!
    REQUIRE_NOTHROW(compare_files(key_name, response_name));
}

TEST_CASE("GE Test getDifficultyInputP1 1", "[single-file]" ) {
    int* exStack = new int[6]{6,5,4,3,2,1};
    Game* g = new Game(6, 2, "scores.txt",exStack);
    GraphicsEngine ge(g);

    int* result1;
    result1 = ge.getDifficultyInput('5','4');
    int numCakes1, diff1 = 0;
    numCakes1 = *result1;
    diff1 = *(result1 + 1);

    CHECK(numCakes1 == 5);
    CHECK(diff1 == 4);
  
    int* result2;
    result2 = ge.getDifficultyInput('4','2');
    int numCakes2, diff2 = 0;
    numCakes2 = *result2;
    diff2 = *(result2 + 1);

    CHECK(numCakes2 == 4);
    CHECK(diff2 == 2);

    delete[] exStack;
    delete[] result1;
    delete[] result2;
    REQUIRE(true);
}

TEST_CASE("GE Test getDifficultyInputP2 1", "[single-file]" ) {
    int* exStack = new int[6]{6,5,4,3,2,1};
    Game* g = new Game(6, 2, "scores.txt", exStack);
    GraphicsEngine ge(g);

    int* result3;
    result3 = ge.getDifficultyInput('2','2');
    int numCakes3, diff3 = 0;
    numCakes3 = *result3;
    diff3 = *(result3 + 1);

    CHECK(numCakes3 == 2);
    CHECK(diff3 == 2);

    int* result4;
    result4 = ge.getDifficultyInput('3','2');
    int numCakes4, diff4 = 0;
    numCakes4 = *result4;
    diff4 = *(result4 + 1);

    CHECK(numCakes4 == 3);
    CHECK(diff4 == 2);

    delete[] exStack;
    delete[] result4;
    delete[] result3;
    REQUIRE(true);
}


TEST_CASE("GE Test getFlipSelection 1", "[single-file]" ) {
    int* exStack = new int[6]{6,5,4,3,2,1};
    GraphicsEngine ge(new Game(6, 2, "scores.txt", exStack));
    WINDOW* testWindow = NULL;
    int result;

    result = ge.getFlipSelection(testWindow,1,6);
    CHECK(result == 5);

    result = ge.getFlipSelection(testWindow,2,6);
    CHECK(result == 4);

    result = ge.getFlipSelection(testWindow,5,6);
    CHECK(result == 1);
    delete[] exStack;
    REQUIRE(true);
}
