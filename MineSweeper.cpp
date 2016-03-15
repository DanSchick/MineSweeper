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


void MineSweeper::printGrid() {
    for(int i=0;i<rows;i++) {
        for (int j = 0; j < columns; j++) {
            cout << *grid[i][j];
        }
        cout << endl;
    }

}