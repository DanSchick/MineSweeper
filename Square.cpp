//
// Created by Danny on 3/15/2016.
//

#include <ostream>
#include <iostream>
#include "Square.h"
using namespace std;

void Square::flag() {
    // verify that square can be flagged
    if(token != 'f' && token != 'x'){
        // we cannot flag this square as it's already uncovered
        cout << "ERROR: Cannot flag uncovered square" << endl;
    } else {
        // we can flag the covered square
        flagged = !flagged; // flips the bool value
        if (flagged) {
            token = 'f';
        } else {
            token = 'x';
        }
    }
}

bool Square::isFlagged() {
    return flagged;
}

bool Square::isMine() {
    return mine;
}

ostream & operator<<(ostream & os, const Square & c) {
    os << c.token << ' ';
    return os;
}