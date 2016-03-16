//
// Created by Danny on 3/15/2016.
//

#include "MineSweeper.h"
#include "Square.h"
#include "NumSquare.h"
#include "MineSquare.h"

#include <vector>
#include <iostream>
#include <time.h>

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
    srand((unsigned)time(NULL));
    while(mines > 0){
        int y = rand() % rows;
        int x = rand() % columns;
        cout << x << y << endl;
        // if this location is not already a mine
        if(!grid[x][y]->isMine()){
            mSq = new MineSquare();
            grid[x][y] = mSq;
            mines -=1;
        }

    }

    findBombs();
    //TODO: find the neighbor count of each NumSquare
}

void MineSweeper::findBombs() {
    printGrid();
    for(int x=0;x<columns;x++){
        for(int y=0;y<rows;y++){
            if(grid[x][y]->isMine()){
                if(x-1 >= 0){
                    grid.at(x - 1).at(y)->incrementCount();
                    if(y-1>=0){
                        grid.at(x - 1).at(y - 1)->incrementCount();
                        grid.at(x).at(y - 1)->incrementCount();
                    } if(y+1<=rows-1){
                        grid.at(x - 1).at(y + 1)->incrementCount();
                        grid.at(x).at(y + 1)->incrementCount();
                    }
                }
                if(x+1 <= columns -1){
                    grid.at(x + 1).at(y)->incrementCount();
                    if(y-1 >= 0){
                        grid.at(x + 1).at(y - 1)->incrementCount();
                    } if(y+1 <= rows-1){
                        grid.at(x + 1).at(y + 1)->incrementCount();
                    }
                }
                }
            }

        }
    }

void MineSweeper::cascade(int x, int y) {
    if(x-1 >= 0){
        if(grid.at(x - 1).at(y)->isBlank()){
            grid.at(x - 1).at(y)->click();
        }
        if(y-1>=0){
            if(grid.at(x - 1).at(y - 1)->isBlank()){
                grid.at(x - 1).at(y - 1)->click();
            }
            if(grid.at(x).at(y - 1)->isBlank()){
                grid.at(x).at(y - 1)->click();
            }
        } if(y+1<=rows-1){
            if(grid.at(x - 1).at(y + 1)->isBlank()){
                grid.at(x - 1).at(y + 1)->click();
            }
            if(grid.at(x).at(y + 1)->isBlank()){
                grid.at(x).at(y + 1)->click();
            }
        }
    }
    if(x+1 <= columns -1){
        if(grid.at(x + 1).at(y)->isBlank()){
            grid.at(x + 1).at(y)->click();
        }
        if(y-1 >= 0){
            if(grid.at(x + 1).at(y - 1)->isBlank()){
                grid.at(x + 1).at(y - 1)->click();
            }
        } if(y+1 <= rows-1){
            if(grid.at(x + 1).at(y + 1)->isBlank()){
                grid.at(x + 1).at(y + 1)->click();
            }
        }
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
                } else {
                    if(grid[y][x]->isBlank()){
                        cascade(y, x);
                    }
                    printGrid();
                }
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
    cout << "  ";
    for(int k=0;k<columns;k++){
        cout << k << " ";
    }
    cout << endl;
    for(int i=0;i<rows;i++) {
        cout << i << " ";
        for (int j = 0; j < columns; j++) {
            cout << *grid[i][j];
        }
        cout << endl;
    }

}