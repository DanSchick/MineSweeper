//
// Created by Danny on 3/15/2016.
//

#include <stdlib.h>
#include <iosfwd>

#ifndef MINESWEEPER_SQUARE_H
#define MINESWEEPER_SQUARE_H

using namespace std;

class Square {
public:
    Square() {}
    // returns true if not a bomb and has no bomb neighbors
    virtual bool isBlank() = 0;
    virtual bool click() = 0;
    virtual void incrementCount() = 0;
    bool isMine();
    bool isFlagged();
    bool flag();

    friend ostream & operator<<(ostream &os, const Square & c);
    char token = 'x';
    bool isExtra = false;
    int x;
    int y;

protected:
    bool flagged = false;
    bool mine;

};


#endif //MINESWEEPER_SQUARE_H
