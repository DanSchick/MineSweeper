//
// Created by Danny on 3/15/2016.
//

#ifndef MINESWEEPER_MINESQUARE_H
#define MINESWEEPER_MINESQUARE_H


#include "Square.h"

class MineSquare: public Square {
public:
    MineSquare();
    void incrementCount();
    bool isBlank();
    bool click();

};


#endif //MINESWEEPER_MINESQUARE_H
