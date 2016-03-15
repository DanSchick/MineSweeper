//
// Created by Danny on 3/15/2016.
//

#include "MineSweeper.h"
#include "Square.h"
#include "NumSquare.h"
#include "MineSquare.h"

#include <vector>
#include <iostream>

using namespace std;

MineSweeper::MineSweeper(int givRows, int givColumns, int mines) {

    // set fields to given info
    rows = givRows;
    columns = givColumns;
    //grid = vector<vector<Square*>>((unsigned)rows);
    grid = vector<vector<Square*>>(rows, vector<Square*>(columns));


    Square* sq;
    // We fill the grid with non-mine squares
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            sq = new NumSquare();
            grid[i][j] = sq ;
        }
    }
    // now we place mines randomly
    Square* mSq;
    while(mines > 0){
        int randRow = rand() % rows;
        int randColumn = rand() % columns;
        // if this location is not already a mine
        if(!grid[randRow][randColumn]->isMine()){
            mSq = new MineSquare();
            grid[randRow][randColumn] = mSq;
        }

        mines -=1;
    }
}

void MineSweeper::play() {
    bool gameOver = false;
    char operation;
    int x;
    int y;
    while(!gameOver){
        cout << "(u)ncover, (f)lag, or (q)uit: " << endl;
        cin >> operation;
        // GO THROUGH OPERATIONS
        if (operation == 'u'){
            // UNCOVER OPERATION *********************
            // get Coords
            cin >> x;
            cin >> y;
            if(x >= 0 && x < rows && y >= 0 && y < columns) {
                if (grid[y][x]->click()) {
                    // ITS A MINE
                    cout << "BOOM.... YOU LOSE" << endl;
                    gameOver = true;
                }
                printGrid();
            } else {
                cout << "INVALID COORDS. Please try again." << endl;
            }


        }


        else if (operation == 'f'){
            // FLAG OPERATION **************************
            // get Coords
            cin >> x;
            cin >> y;
            if(x >= 0 && x < rows && y >= 0 && y < columns) {
                grid[y][x]->flag();
                printGrid();
            } else {
                cout << "INVALID COORDS. Please try again" << endl;
            }
        }



    }

}


void MineSweeper::printGrid() {
    cout << "  0 1 2 3 4 5 6 7"<< endl;
    for(int i=0;i<rows;i++) {
        cout << i << " ";
        for (int j = 0; j < columns; j++) {
            cout << *grid[i][j];
        }
        cout << endl;
    }

}