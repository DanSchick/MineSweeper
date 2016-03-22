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
    /**
     * Never used, only use derived classes constructor
     */
    Square() {}
    /**
     * Returns true if no bomb neighbors
     */
    virtual bool isBlank() = 0;
    /**
     * Uncovers square. returns true if bomb, and the game is lost.
     * returns false if not a bomb <-- helps in the game loop
     */
    virtual bool click() = 0;
    /**
     * For uncovered squares, increments the number of bomb squares by 1
     */
    virtual void incrementCount() = 0;
    /**
     * @return true if mine, false if not
     */
    bool isMine();
    /**
     * @return true if flagged
     */
    bool isFlagged();
    /**
     * toggle between flagged or not flagged
     */
    void flag();

    /**
     * Prints out the current token
     */
    friend ostream & operator<<(ostream &os, const Square & c);
    // represents the token showed on board
    char token = 'x';
    // The board is surrounded by a layer of 'buffer' squares to make validation easier
    bool isExtra = false;
    // x coordinate of the square
    int x;
    // y coordinate of the square
    int y;

protected:
    // represents if the square is flagged
    bool flagged = false;
    // true if it's a mine, false otherwise
    bool mine;

};


#endif //MINESWEEPER_SQUARE_H
