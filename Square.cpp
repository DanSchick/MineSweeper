//
// Created by Danny on 3/15/2016.
//

#include <ostream>
#include "Square.h"
using namespace std;

void Square::flag() {
    flagged = !flagged;
    if(flagged){
        token = 'f';
    } else {
        token = 'x';
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