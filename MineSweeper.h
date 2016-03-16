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
    MineSweeper(int rows, int columns, int mines);

    void play();

    void findBombs();

    void printGrid();


    void cascade(int x, int y);


protected:
    int rows;
    int columns;

    vector<vector<Square*>> grid;
    queue<Square*> cascadeQueue;

};


#endif //MINESWEEPER_MINESWEEPER_H
