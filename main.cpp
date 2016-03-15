#include <iostream>
#include "MineSweeper.h"
#include "NumSquare.h"

using namespace std;

int main() {
    cout << "flag" << endl;

    MineSweeper game = MineSweeper(8, 8, 5);
    game.printGrid();

//    Square* sq;
//    sq = new NumSquare();
//    cout << *sq << endl;
//
//    vector<Square*> vec;
//    vec.insert(vec.begin(), sq);
//
//    cout << *vec[0] << endl;

    return 0;
}