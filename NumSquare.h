//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_NUMSQUARE_H
#define MINESWEEPER_NUMSQUARE_H


#include "Square.h"

class NumSquare: public Square {
public:

    /**
     * Default constructor.
     */
    NumSquare();

    /**
     * Constructor for the 'buffer' squares on outside of board
     */
    NumSquare(char extra);

    bool isBlank();
    void incrementCount();
    bool click();
    // number of neighbors that are bombs
    int neighbors = 0;


};


#endif //MINESWEEPER_NUMSQUARE_H
