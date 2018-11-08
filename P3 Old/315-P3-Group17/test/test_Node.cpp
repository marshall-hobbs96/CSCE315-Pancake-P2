/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Node.cpp - Minimax Tree Node Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Node.h"

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "Node Test eval 1", "[single-file]" ) {
    // Testing one level deep with min root
    
    // Set up tester and solution
    vector<Node*> empty_kids, kids;
    vector<int> nums;

    // Max leaves
    nums.push_back(0);
    Node* node1 = new Node(empty_kids, true, 1, nums);
    nums.pop_back();
    kids.push_back(node1);
    nums.push_back(1);
    Node* node2 = new Node(empty_kids, true, 2, nums);
    nums.pop_back();
    kids.push_back(node2);
    nums.push_back(2);
    Node* node3 = new Node(empty_kids, true, 3, nums);
    nums.pop_back();
    kids.push_back(node3);

    // Min root
    // nums is empty
    Node root(kids, true, 0, nums);

    int value = root.eval()->getValue();

    CHECK(value == 1);
    
    // No Cleanup necessary
    REQUIRE(true);
}

TEST_CASE( "Node Test eval 2", "[single-file]" ) {
    // Testing two levels deep with min root

    // Tree is:
    // []
    //      [1]
    //      [2]
    //          [0]
    //      [3]
    // Value should be 1 (smallest within shortest range)
    
    // Set up tester and solution
    vector<Node*> empty_kids, kids;
    vector<int> nums;

    // Max leaves
    nums.push_back(0);
    Node* node1 = new Node(empty_kids, true, 1, nums);
    nums.pop_back();
    kids.push_back(node1);

    // Make kids for node2:
    nums.push_back(1);
    nums.push_back(0);
    vector<Node*> node2_kids;
    node2_kids.push_back(new Node(empty_kids, true, 0, nums));
    nums.pop_back();
    nums.pop_back();
    
    // Make Node 2
    nums.push_back(1);
    Node* node2 = new Node(node2_kids, true, 2, nums);
    nums.pop_back();
    kids.push_back(node2);
    
    // Make Node 3
    nums.push_back(2);
    Node* node3 = new Node(empty_kids, true, 3, nums);
    nums.pop_back();
    kids.push_back(node3);

    // Min root
    // nums is empty
    Node root(kids, false, 0, nums);

    int value = root.eval()->getValue();

    CHECK(value == 1);
    
    // No Cleanup necessary
    REQUIRE(true);
}