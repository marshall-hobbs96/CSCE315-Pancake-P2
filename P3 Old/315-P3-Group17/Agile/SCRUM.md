## SCRUM Practices

For this project, we will follow the SCRUM Practices presented by Dr. Daugherty in class.
This includes writing a product backlog and burn-down chart, dividing the project into sprints,
and setting up SCRUM meetings. This document (created 10/20/2018) will keep track of all four
of these items as the project progresses.

### Backlog

based loosely on [this](https://www.scrum-institute.org/The_Scrum_Product_Backlog.php) (item priority is totally based on sprint number)

| ID | Item                                                                                                          | Sprint | Assignee            |
|----|---------------------------------------------------------------------------------------------------------------|--------|---------------------|
| 1  | Write a concise purpose statement for the project                                                             | 1      | Troy                |
| 2  | Decide on a set of high-level entities, and describe their relationships                                      | 1      | Everyone            |
| 3  | Create an interaction Diagram to describe the interactions of the high-level entities                         | 1      | Everyone            |
| 4  | Describe the interactions in that diagram with descriptions and UML                                           | 1      | Troy, McLain, Abdul |
| 5  | Establish the risks, benefits, and assumptions of the project                                                 | 1      | Marshall            |
| 6  | Set up framework code based on the UML diagram to allow team members to fill in implementations               | 2      | Troy                |
| 7  | Splash screen appears when program begins                                                                     | 2      | Troy                |
| 8  | Splash screen includes a (somewhat working) blinking "ENTER" button                                           | 2      | Troy                |
| 9  | Splash screen displays instructions upon being entered on a new screen                                        | 2      | Troy                |
| 10 | Next screen allows user to choose how many pancakes to stack                                                  | 2      | McLain              |
| 11 | Same screen allows user to set the difficulty of their opponent                                               | 2      | McLain              |
| 12 | Handle incorrect difficulty input                                                                             | 2      | McLain              |
| 13 | Allow user to choose an order for the pancake stacks before the game or choose a random order                 | 2      | Marshall            |
| 14 | Validate user order or use C++ STL to shuffle the pancakes                                                    | 2      | Marshall            |
| 15 | Allow player to enter their initials on the next screen                                                       | 2      | Abdul               |
| 16 | Allow player to see the high scores loaded from the file on that same screen                                  | 2      | Abdul               |
| 17 | Draw one pancake                                                                                              | 3      | Marshall            |
| 18 | Draw a stack of pancakes in its own window                                                                    | 3      | Marshall            |
| 19 | Draw another stack of pancakes in a separate window without affecting the other stack                         | 3      | Marshall            |
| 20 | Allow user to make a selection using arrow keys                                                               | 3      | McLain              |
| 21 | Access a data structure containing the pancake draw instructions for each pancake and print them individually | 3      | McLain              |
| 22 | Blink those pancakes above and including the selected pancake for 3 seconds                                   | 3      | McLain              |
| 23 | Print the updated user stack to reflect changes                                                               | 3      | McLain              |
| 24 | Calculate the AI's move by performing a minimax tree depth search                                             | 3      | Troy                |
| 25 | Blink the pancakes at and above the AI's choice for the player                                                | 3      | Troy                |
| 26 | Execute the AI's move by flipping the pancakes above that choice and redraw the AI's stack                    | 3      | Troy                |
| 27 | When the game is over, calculate the user's score                                                             | 3      | Abdul               |
| 28 | Generate a new screen to show the user their score                                                            | 3      | Abdul               |
| 29 | On the same screen, display the previous scores read from the file, with all 6 scores sorted                  | 3      | Abdul               |
| 30 | Write the scores to the file, and ask the user if they would like to play again or quit                       | 3      | Abdul               |
| 31 | Make sure the user cannot mess up the first splash screen or instructions screen                              | 4      | Troy                |
| 32 | Handle illegal pancake selections                                                                             | 4      | McLain              |
| 33 | Show the user their difficulty before leaving second screen                                                   | 4      | McLain              |
| 34 | Handle incorrect pancake stack orders                                                                         | 4      | Marshall            |
| 35 | Show pancake stack order when leaving third screen                                                            | 4      | Marshall            |
| 36 | Cleanly display results on  scores screen                                                                     | 4      | Abdul               |
| 37 | Display only 5 results plus user's 0 score on same screen                                                     | 4      | Abdul               |
| 38 | Fix any issues that arise when users try our game                                                             | 5      | Everyone            |

### Burn-Down Chart

![burn](https://github.tamu.edu/storage/user/5293/files/c145d502-da0c-11e8-8989-b3f4a07b6443)

### Sprints

**Sprint 1: 10/11 - 10/18** 
Design Documents and Project Framework

For week 1, we should focus on gaining a clear picture of the project as a whole and preparing to practice SCRUM. We should set up this document as well as a document for our test-driven development. We will also finish and submit a set of design documents. This way, our customers can see that we have a functioning plan for how to execute the game.

**Sprint 2: 10/18 - 10/23** 
Framework Code

For week 2, we will focus on making the first few screens in the game appear without failure. We will make sure that all product backlog items marked priority 2 are complete so that the game player can see a splash screen as well as screens that allow them to customize the game and enter their username before starting. We will need to configure the first 4 tasks mentioned in the instructions for this project. When these screens are done, the screen will show everything received from the user and print that the game is over.

**Sprint 3: 10/23 - 10/31** 
Functioning Game

By the end of this sprint, we should have a fully functional game that allows the user to play until the game is over and repeat as necessary. The game does not have to be as robust as possible, but tests should be written (and sometimes failing) for edge cases. The game should run to completion if the user does everything they are supposed to, even if the screen does not look very pretty and easy to use for people without computer experience. Someone else in our CSCE315 class should be able to play.

**Sprint 4: 10/31 - 11/3**
Quality Game

Focus for this sprint is on designing the game to produce quality (blinking, etc.) screens that make the UI simple and straightforward. At the end of the sprint, anyone should be able to play intuitively without the program crashing. No extra functionality should be added yet.

**Sprint 5: 11/3 - 11/5**
Quality Testing

This weekend will be for handing the game off to someone who does not have a computer background to see if they can easily play or crash the program. If we manage to finish this early, we can think about adding mor functionality to the game.

### SCRUM Meetings

15 Minute meeetings to review priorities mentioned (should mostly come from the Product backlog). Will be filled in and added to as we go.


| Date   | Time  | Master   | Members Present | Items Due          | Items Completed                         | Items Due Count (running total) | Completed Count (running total) |
|--------|-------|----------|-----------------|--------------------|-----------------------------------------|---------------------------------|---------------------------------|
| 15-Oct | 4:10  | Troy     | Everyone        | 1, 2               | 1, 2                                    | 2                               | 2                               |
| 17-Oct | 4:10  | Troy     | Everyone        | 3                  | 3                                       | 3                               | 3                               |
| 18-Oct | 5:00  | Troy     | Everyone        | 4, 5               | 4, 5                                    | 5                               | 5                               |
| 21-Oct | 5:00  | Troy     | Everyone        | 6, 7, 10           | 6                                       | 8                               | 6                               |
| 22-Oct | 4:10  | Troy     | Everyone        | 8, 11, 13, 15      | 10, 11, 13, 15                          | 12                              | 10                              |
| 23-Oct | 12:35 | Abdul    | Everyone        | 9, 12, 14, 16      | 7, 8, 9, 12, 14, 16                     | 16                              | 16                              |
| 29-Oct | 4:10  | Marshall | Everyone        | 18, 20, 28, 17     | 27, 20                                  | 20                              | 18                              |
| 30-Oct | 12:35 | Marshall | Everyone        | 19, 21, 22, 25, 24 | 28, 21                                  | 25                              | 20                              |
| 31-Oct | 4:10  | McLain   | Everyone        | 23, 26, 29, 30, 27 | 22, 23, 24                              | 30                              | 23                              |
| 1-Nov  | 12:35 | McLain   | Everyone        | 31, 32, 34, 36     | 17, 18                                  | 34                              | 25                              |
| 3-Nov  | TBA   | McLain   | Everyone        | 33, 35             | 19, 25                                  | 36                              | 27                              |
| 4-Nov  | TBA   | Troy     | Everyone        | 37                 | 26, 29, 30, 31, 32, 33, 34, 35, 36, 37  | 37                              | 37                              |
| 5-Nov  | 4:10  | Troy     | Everyone        | 38                 | 38                                      | 38                              | 38                              |

### 
