//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_NUMSQUARE_H
#define MINESWEEPER_NUMSQUARE_H


#include "Square.h"

class NumSquare: public Square {
public:
    NumSquare();

    void incrementCount();
    bool click();

protected:
    int neighbors = 0;

};


#endif //MINESWEEPER_NUMSQUARE_H
