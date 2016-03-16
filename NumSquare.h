//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_NUMSQUARE_H
#define MINESWEEPER_NUMSQUARE_H


#include "Square.h"

class NumSquare: public Square {
public:
    NumSquare();

    // this represents a number square that's the board padding
    NumSquare(char extra);

    bool isBlank();
    void incrementCount();
    bool click();
    int neighbors = 0;


};


#endif //MINESWEEPER_NUMSQUARE_H
