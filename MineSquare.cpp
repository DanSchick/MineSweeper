//
// Created by Danny on 3/15/2016.
//

#include "MineSquare.h"

MineSquare::MineSquare() {
    mine = true;
    token = 'B';
}

bool MineSquare::isBlank() {
    return false;
}

bool MineSquare::click() {
    token = 'B';
    return mine;
}

void MineSquare::incrementCount() {
    mine = true;

}