//
// Created by Danny on 3/15/2016.
//

#include "MineSweeper.h"
#include "NumSquare.h"
#include "MineSquare.h"

#include <string>
#include <iostream>
#include <time.h>

using namespace std;

MineSweeper::MineSweeper(int givRows, int givColumns, int mines) {

    // set fields to given info
    rows = givRows;
    columns = givColumns;
    // intialize grid as a vector of vectors of squares that initializes to include extra buffer squares
    /*
     * |||||
     * |xxx| a 2x3 grid looks like this with buffer squares. '|' represents these buffer sqaures
     * |xxx|
     * |||||
     */
    grid = vector<vector<Square*>>(rows+2, vector<Square*>(columns+2));


    Square* sq;
    // We fill the grid with non-mine squares to start
    for(int i=0;i<rows+2;i++){
        for(int j=0;j<columns+2;j++){
            // check if coordinate should be an extra buffer square
            if(i==0 || i == rows+1 || j == 0 || j == columns + 1 ){
                // extra
                sq = new NumSquare('e');
            } else {
                // not extra
                sq = new NumSquare();
            }

            grid[i][j] = sq ;
            sq->x = i;
            sq->y = j;
        }
    }
    // now we place mines randomly
    Square* mSq;
    // seed our random number generator
    srand((unsigned)time(0));
    int rowL = rows + 1;
    int colL = columns + 1;
    while(mines > 0){
        int x = rand() % rowL + 1;
        int y = rand() % colL + 1;
        // if this location is not already a mine
        // replace the NumSquare with a MineSquare
        if(!grid[x][y]->isMine() && !grid[x][y]->isExtra){
            mSq = new MineSquare();
            grid[x][y] = mSq;
            mSq->x = x;
            mSq->y = y;
            mines -=1;
        }

    }

    findBombs();
}

void MineSweeper::findBombs() {
    printGrid();
    // loop through grid
    for(int x=1;x<columns+1;x++){
        for(int y=1;y<rows+1;y++){
            // if square is a mine, increment the count of every adjacent square
            if(grid[x][y]->isMine()){
                grid[x-1][y-1]->incrementCount();
                grid[x-1][y]->incrementCount();
                grid[x-1][y+1]->incrementCount();

                grid[x][y-1]->incrementCount();
                grid[x][y+1]->incrementCount();

                grid[x+1][y-1]->incrementCount();
                grid[x+1][y]->incrementCount();
                grid[x+1][y+1]->incrementCount();
            }

            }

        }
    }

void MineSweeper::cascade(int x, int y) {

    // uncover the given square and add it to the Queue
    if(!grid[x][y]->isMine()){
        grid[x][y]->click();
        cascadeQueue.push(grid[x][y]);
    }
    Square* sq;

    // Algorithm for uncovering and cascading squares
    /*
     * - if clicked square is not mine, uncover and add to queue
     * - take off a square from queue
     * - count adjacent mines
     * - if count is 0, uncover all adjacent square and add them to the queue
     * - go to step 2 if queue not empty
     */

    // while there's still squares to uncover
    while(!cascadeQueue.empty()){
        system("cls"); // this clears the console, making a pretty animation
        printGrid();

        sq = cascadeQueue.front();
        if(!sq->isMine()) {
            sq->click();
        }
        cascadeQueue.pop();
        cout << "x: " << sq->x << " Y: " << sq->y << endl;
        // if the square has no bomb neighors and is not extra, we have to uncover it's neighbors
        if(sq->isBlank() && !sq->isExtra){
            // Each if statement is for a neighbor square of the one being cleared
            // Validate that it's still covered and is not an extra
            // then add it to the queue and uncover it
            if(grid[sq->x-1][sq->y-1]->token == 'x' && !grid[sq->x-1][sq->y-1]->isExtra ) {
                cascadeQueue.push(grid[sq->x - 1][sq->y - 1]);
                grid[sq->x - 1][sq->y-1]->click();

            } if(grid[sq->x-1][sq->y]->token == 'x' && !grid[sq->x-1][sq->y]->isExtra) {
                cascadeQueue.push(grid[sq->x - 1][sq->y]);
                grid[sq->x - 1][sq->y]->click();

            } if(grid[sq->x-1][sq->y+1]->token == 'x' && !grid[sq->x-1][sq->y+1]->isExtra) {
                cascadeQueue.push(grid[sq->x - 1][sq->y + 1]);
                grid[sq->x - 1][sq->y+1]->click();

            } if(grid[sq->x][sq->y-1]->token == 'x' && !grid[sq->x][sq->y-1]->isExtra) {
                cascadeQueue.push(grid[sq->x][sq->y - 1]);
                grid[sq->x][sq->y-1]->click();

            } if(grid[sq->x][sq->y+1]->token == 'x' && !grid[sq->x][sq->y+1]->isExtra) {
                cascadeQueue.push(grid[sq->x][sq->y + 1]);
                grid[sq->x][sq->y+1]->click();

            } if(grid[sq->x+1][sq->y-1]->token == 'x' && !grid[sq->x+1][sq->y-1]->isExtra) {
                cascadeQueue.push(grid[sq->x + 1][sq->y - 1]);
                grid[sq->x+1][sq->y-1]->click();

            } if(grid[sq->x+1][sq->y]->token == 'x' && !grid[sq->x+1][sq->y]->isExtra) {
                cascadeQueue.push(grid[sq->x + 1][sq->y]);
                grid[sq->x+1][sq->y]->click();

            } if(grid[sq->x+1][sq->y+1]->token == 'x' && !grid[sq->x+1][sq->y+1]->isExtra) {
                cascadeQueue.push(grid[sq -> x + 1][sq->y + 1]);
                grid[sq->x+1][sq->y+1]->click();

            }
        }
    }

}

void MineSweeper::play() {
    // define variables we'll need in the game loop
    bool gameOver = false;
    bool errors = false;
    bool won;
    char operation;
    int x;
    int y;
    bool inRange;
    while(!gameOver) {
        // first, we check if the user won the game
        // initialize win to true, if we find a square that's not a mine and still covered
        // set won to false and keep playing
        won = true;
        for (vector<Square *> vec : grid) {
            for (Square *chkSq : vec) {
                if (!chkSq->isMine() && chkSq->token != 'x') {
                    won = false;
                    break;
                }

            }
            if(won){
                break;
            }
        }
        if(won) {
            cout << "YOU WIN!" << endl;
            gameOver = true;

        } else {
            // ***********************************************************
            // The user hasn't won. So we keep playing.
            errors = false;
            cout << "(u)ncover, (f)lag, or (q)uit: " << endl;
            cin >> operation;

            // validate input
            if(operation != 'f' && operation != 'q' && operation != 'u'){
                cout << "ERROR: Invalid operation" << endl;
                errors = true;
                cin.clear();
                cin.ignore(256, '\n');
            } else if(!(cin >> y)){
                cout << "ERROR: Bad coordinates given" << endl;
                errors = true;
                cin.clear();
                cin.ignore(256,'\n');
            } else if(!(cin >> x)){
                cout << "ERROR: Bad coordinates given" << endl;
                errors = true;
                cin.clear();
                cin.ignore(256, '\n');
            }


            // GO THROUGH OPERATIONS IF NO ERRORS
            if(!errors) {
                // quit
                if (operation == 'q') { gameOver = true; }

                    // UNCOVER OPERATION *********************
                else if (operation == 'u') {
                    // get Coords
                    // verify square is within range
                    inRange = x >= 0 && x < rows + 1 && y >= 0 && y < columns + 1;

                    if (!inRange) {
                        // if square isn't valid
                        cout << "INVALID COORDS. Please try again." << endl;
                    } else {
                        // square is valid
                        // Attempt to uncover square
                        if (!grid[x][y]->isFlagged()) {
                            if (grid[x][y]->click()) {
                                // ITS A MINE
                                cout << "BOOM.... YOU LOSE" << endl;
                                gameOver = true;
                            } else {
                                // execute function that uncovers the square(s)
                                cascade(x, y);
                            }
                        } else {
                            // if square is flagged
                            cout << "ERROR: Square is flagged" << endl;
                        }
                    }
                }

                    // FLAG OPERATION **************************
                else if (operation == 'f') {
                    // get Coords
                    cin >> y;
                    cin >> x;
                    if (x >= 0 && x < rows + 1 && y >= 0 && y < columns + 1) {
                        grid[x][y]->flag();
                        printGrid();
                    } else {
                        cout << "INVALID COORDS. Please try again" << endl;
                    }
                }
            }
        }


    }


}


void MineSweeper::printGrid() {
    cout << " ";
    for(int k=1;k<columns+1;k++){
        cout << k << " ";
    }
    cout << endl;
    for(int i=1;i<rows+1;i++) {
        cout << i << " ";
        for (int j = 1; j < columns+1; j++) {
            cout << *grid[i][j];
        }
        cout << endl;
    }

}