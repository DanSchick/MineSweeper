#include <iostream>
#include "MineSweeper.h"
#include "NumSquare.h"

using namespace std;

int main() {
    // Start out by asking the user what the difficulty level
    cout << "Welcome to Minesweeper. What Difficulty? (b)eginner, (i)ntermediate, or (e)xpert?: " << endl;
    string arg;
    MineSweeper* game;
    while(true){ // loop through in case the user gives a bad input
        cin >> arg;
        cin.clear();
        cin.ignore(10000,'\n');
        if(arg == "b" || arg == "B"){
            game = new MineSweeper(8,8,10);
            break;
        } if (arg == "i" || arg == "I"){
            game = new MineSweeper(16,16,40);
            break;
        } if(arg == "e" || arg == "E"){
            game = new MineSweeper(16,30,99);
            break;
        }

        cout << "Invalid option. Must be b, i, or e." << endl;
    }
    game->play();


    return 0;
}