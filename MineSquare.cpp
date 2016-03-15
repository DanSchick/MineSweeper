//
// Created by Danny on 3/15/2016.
//

#include "MineSquare.h"

MineSquare::MineSquare() {
    mine = true;
}

bool MineSquare::click() {
    return mine;
}