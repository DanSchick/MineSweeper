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

bool NumSquare::isBlank() {
    if(neighbors == 0){
        return true;
    } else {
        return false;
    }
}

bool NumSquare::click() {
    if(neighbors != 0) {
        token = neighbors + '0';
    } else {
        token = '_';
    }
    return mine;
}
