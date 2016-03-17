//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include <vector>
#include <queue>
#include "Square.h"

using namespace std;

class MineSweeper {
public:
    /**
     * Creates a game object with specified number of rows columns and mines
     */
    MineSweeper(int rows, int columns, int mines);

    /**
     * Starts the main game loop
     */
    void play();

    /**
     * function that increments the number squares that neighbor bombs
     */
    void findBombs();

    /**
     * Prints the current game board
     */
    void printGrid();


    /**
     * If a blank square is clicked, the game uncovers every other non-bomb square recursively
     * Uses a Queue system to cascade for as long as needed
     * @param x x coord of square clicked
     * @param y y coord of square clicked
     */
    void cascade(int x, int y);



protected:
    // number of rows
    int rows;
    // number of columns
    int columns;

    // Two dimensional vector that represents the game grid
    // coordinate (1,3) for example is grid[1][3]
    vector<vector<Square*>> grid;
    // a queue used by cascade() that is looped over to uncover
    // squares until there's no more blank ones left to uncover
    queue<Square*> cascadeQueue;

};


#endif //MINESWEEPER_MINESWEEPER_H
