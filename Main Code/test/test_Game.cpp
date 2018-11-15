/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Game.cpp - Game Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Game.h"
#include <iostream>
#include <array>

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE("Case1: Test AI Sorted & User stack not sorted")
{
	int difficulty = 4;
	int n = 5;
	int* ai= new int[5]{5,4,3,2,1};
	int* user = new int[5]{1,3,4,5,2};
	Game g(n, difficulty, "scores.txt", ai);

	CHECK(g.computeScore(difficulty, n, user, ai)==n);
	delete[] ai;
	delete[] user;
	REQUIRE(true);
}
TEST_CASE("Case2: Test AI Sorted & User stack sorted")
{
  int difficulty = 4;
  int n = 5;
  int* ai1 = new int[n]{5,4,3,2,1};
  int* user1 = new int[n]{5,4,3,2,1};
  Game g(n, difficulty, "scores.txt", ai1);

  CHECK(g.computeScore(difficulty,n ,user1, ai1)==(n*(difficulty+1)));
	delete[] ai1;
	delete[] user1;
	REQUIRE(true);
}

TEST_CASE("Case3: Test AI not Sorted & User stack sorted")
{
  int difficulty = 4;
  int n = 5;
  int* ai2 = new int[n]{5,3,4,2,1};
  int* user2 = new int[n]{5,4,3,2,1};
  Game g(n, difficulty, "scores.txt", ai2);
  CHECK(g.computeScore(difficulty,n ,user2, ai2)==(2*n*(difficulty+1)));
	delete[] ai2;
	delete[] user2;
	REQUIRE(true);
}

TEST_CASE("Case4: Test AI not Sorted & User stack not sorted"){
  int difficulty = 4;
  int n = 5;
  int* ai3 = new int[n]{5,3,4,2,1};
  int* user3 = new int[n]{5,4,3,1,2};
  Game g(n, difficulty, "scores.txt", ai3);
  CHECK(g.computeScore(difficulty,n ,user3, ai3)==-1);
	delete[] ai3;
	delete[] user3;
	REQUIRE(true);
}

/*
TEST_CASE("Testing whether pancakeStack in int form converts to string successfully. stackToString"){

    int stackSize = 9;
    int* stack = new int[stackSize]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::string stringStack = stackToString(stack, stackSize);
    correctStack = "+-+/n|1|/n+-+/n+---+/n| 2 |/n+---+/n+-----+/n|  3  |/n+-----+/n+-------+/n|   4   |/n+-------+/n+---------+/n|    5    |/n+---------+/n+-----------+/n|     6     |/n+-----------+/n+-------------+/n|      7      |/n+-------------+/n+---------------+/n|       8       |/n+---------------+/n+-----------------+/n|        9        |/n+---------------+/n";

    CHECK(stringStack == correctStack);

    delete stack;

}
*/
