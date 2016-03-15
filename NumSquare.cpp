//
// Created by Danny on 3/15/2016.
//

#include "NumSquare.h"

NumSquare::NumSquare(){
    mine = false;

}

void NumSquare::incrementCount() {
    neighbors += 1;
}

bool NumSquare::click() {
    if(neighbors != 0) {
        token = (char)neighbors;
    } else {
        token = '_';
    }
    return mine;
}
