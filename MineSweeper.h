//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include <vector>
#include "Square.h"

using namespace std;

class MineSweeper {
public:
    MineSweeper(int rows, int columns, int mines);

    void printGrid();


protected:
    int rows;
    int columns;

    vector<vector<Square*>> grid;
};


#endif //MINESWEEPER_MINESWEEPER_H
