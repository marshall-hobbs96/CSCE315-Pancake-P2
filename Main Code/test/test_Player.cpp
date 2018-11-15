/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Player.cpp - Player Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Player.h"

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "Player Test makeMove 1", "[single-file]" ) {
    // Testing odd number size stack
    
    // Set up tester and solution
    int* stack = new int[5]{1, 2, 4, 3, 5};
    int* solution = new int[5]{1, 2, 5, 3, 4};
    Player tester(5, stack);
    int move = 2;

    // Get original size, make move, and get new stack
    int original_size = tester.getStackSize();
    tester.makeMove(move);
    int new_size = tester.getStackSize();
    int* new_stack = tester.getStack();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    for (int i = 0; i < new_size; i++) {
        CHECK(new_stack[i] == solution[i]);
    }
    
    // Cleanup
    delete[] stack;
    delete[] solution;
    REQUIRE(true);
}

TEST_CASE( "Player Test makeMove 2", "[single-file]" ) {
    // Testing even number size stack
    
    // Set up tester and solution
    int* stack = new int[6]{1, 2, 6, 3, 4, 5};
    int* solution = new int[6]{1, 2, 5, 4, 3, 6};
    Player tester(6, stack);
    int move = 2;

    // Get original size, make move, and get new stack
    int original_size = tester.getStackSize();
    tester.makeMove(move);
    int new_size = tester.getStackSize();
    int* new_stack = tester.getStack();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    for (int i = 0; i < new_size; i++) {
        CHECK(new_stack[i] == solution[i]);
    }
    
    // Cleanup
    delete[] stack;
    delete[] solution;
    REQUIRE(true);
}

TEST_CASE( "Player Test makeMove 3", "[single-file]" ) {
    // Testing stack size 2
    
    // Set up tester and solution
    int* stack = new int[2]{1, 2};
    int* solution = new int[2]{2, 1};
    Player tester(2, stack);
    int move = 0;

    // Get original size, make move, and get new stack
    int original_size = tester.getStackSize();
    tester.makeMove(move);
    int new_size = tester.getStackSize();
    int* new_stack = tester.getStack();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    for (int i = 0; i < new_size; i++) {
        CHECK(new_stack[i] == solution[i]);
    }
    
    // Cleanup
    delete[] stack;
    delete[] solution;
    REQUIRE(true);
}

TEST_CASE( "Player Test makeMove 4", "[single-file]" ) {
    // Testing stack size 9
    
    // Set up tester and solution
    int* stack = new int[9]{1, 2, 3, 4, 9, 8, 7, 6, 5};
    int* solution = new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    Player tester(9, stack);
    int move = 4;

    // Get original size, make move, and get new stack
    int original_size = tester.getStackSize();
    tester.makeMove(move);
    int new_size = tester.getStackSize();
    int* new_stack = tester.getStack();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    for (int i = 0; i < new_size; i++) {
        CHECK(new_stack[i] == solution[i]);
    }
    
    // Cleanup
    delete[] stack;
    delete[] solution;
    REQUIRE(true);
}

TEST_CASE( "Player Test getSortedness 1", "[single-file]" ) {
    // Testing stack in reverse order
    
    // Set up tester and solution
    int* stack = new int[6]{6, 5, 4, 3, 2, 1};
    int solution = 0;
    Player tester(6, stack);

    // Check that the size has not changed
    int original_size = tester.getStackSize();
    int sortedness = tester.getSortedness();
    int new_size = tester.getStackSize();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    CHECK(sortedness == solution);
    
    // Cleanup
    delete[] stack;
    REQUIRE(true);
}

TEST_CASE( "Player Test getSortedness 2", "[single-file]" ) {
    // Testing stack in random order
    
    // Set up tester and solution
    int* stack = new int[7]{7, 2, 4, 3, 1, 6, 5};
    int solution = 4;
    Player tester(7, stack);

    // Check that the size has not changed
    int original_size = tester.getStackSize();
    int sortedness = tester.getSortedness();
    int new_size = tester.getStackSize();
    CHECK(original_size == new_size);

    // Validate that the solution matches
    CHECK(sortedness == solution);
    
    // Cleanup
    delete[] stack;
    REQUIRE(true);
}