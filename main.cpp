/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "game.h"

const string red("\033[1;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string cyan("\033[1;36m");
const string bold("\033[1m");
const string reset("\033[0m");

void drawBlankBoard()
{
    cout << bold << "   ";
    //Write the numbers on the top
    for(int i = 0; i < X_SIZE; i++){
        if(i == 15){
            cout << "  " << i << " " << endl;
            break;
        }
        if(i < 10)
            cout << "  " << i << "  ";
        else
            cout << "  " << i << " ";
    }
    //Write the top line
    cout << "   ╔";
    for(int j = 0; j < X_SIZE; j++){
        if(j == 15){
            cout << "════╗" << endl;
            break;
        }
        cout << "════╤";
    }
    //Write the middle lines
    for(int y = 0; y < Y_SIZE; y++){
        //Write the numbers on the left
        if(y < 10)
            cout << " " << y << " ";
        else
            cout << y << " ";
        
        cout << "║";
        for(int x = 0; x < X_SIZE; x++){
            if((y == 7 || y == 8) && (x == 7 || x == 8)){//Write the central square
                cout << "     ";
            }
            else if(x == 15){
                cout << "    ║" << endl;
                break;
            }
            else cout << "    │";
        }
        if(y<15){
            cout << "   ";  
            cout << "╟";
            for(int x = 0; x < X_SIZE; x++){
                if((y == 7) && (x == 7 || x == 8)){//Write the central square
                    cout << "     ";
                }
                else if(x == 15){
                    cout << "────╢" << endl;
                    break;
                }
                else cout << "────┼";
            }
        }
    }
    //Write the bottom line
    cout << "   ";
    cout << "╚";
    for(int n = 0; n < X_SIZE; n++){
        if(n == 15){
            cout << "════╝" << endl;
            break;
        }
        cout << "════╧";
    }
    cout << endl;
}

int main()
{
    drawBlankBoard();
    return 0;
}