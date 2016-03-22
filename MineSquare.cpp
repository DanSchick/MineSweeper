//
// Created by Danny on 3/15/2016.
//

#include "MineSquare.h"

MineSquare::MineSquare() {
    mine = true;
    token = 'x';
}

bool MineSquare::isBlank() {
    return false;
}

bool MineSquare::click() {
    token = 'B';
    return mine;
}

void MineSquare::incrementCount() {
    // this does nothing, but we must implement it as it's derived from Square.h
}