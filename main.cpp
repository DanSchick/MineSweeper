#include <iostream>
#include "MineSweeper.h"
#include "NumSquare.h"

using namespace std;

int main() {

    MineSweeper game = MineSweeper(8, 8, 5);
    game.printGrid();
    game.play();


    return 0;
}