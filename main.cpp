/**
 * @file main.cpp
 * @author Bastien, Victor, AlexisR
 * @brief Main file for the game
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "game.h"
#include "log.h"
#include <ncurses.h>

const LogLevel loggingLevel = LogLevel::WARNING;// Set the minimum log level to log

void drawBlankBoard()
{
    setlocale(LC_ALL, ""); 
    initscr();  // Initialize ncurses
    raw(); // Disable line buffering and enable immediate input
    keypad(stdscr, TRUE); // Enable the keypad to capture arrow keys
    noecho(); // Don't print input characters to the screen

    printw("   ");
    // Write the numbers on the top
    for (int i = 0; i < X_SIZE; i++) {
        if (i == 15) {
            printw("  %d\n", i);
            break;
        }
        if (i < 10)
            printw("  %d  ", i);
        else
            printw("  %d ", i);
    }
    // Write the top line
    printw("   ╔");
    for (int j = 0; j < X_SIZE; j++) {
        if (j == 15) {
            printw("════╗\n");
            break;
        }
        printw("════╤");
    }
    // Write the middle lines
    for (int y = 0; y < Y_SIZE; y++) {
        // Write the numbers on the left
        if (y < 10)
            printw(" %d ", y);
        else
            printw("%d ", y);

        printw("║");
        for (int x = 0; x < X_SIZE; x++) {
            if ((y == 7 || y == 8) && (x == 7 || x == 8)) {  // Write the central square
                printw("     ");
            } else if (x == 15) {
                printw("    ║\n");
                break;
            } else
                printw("    │");
        }
        if (y < 15) {
            printw("   ");
            printw("╟");
            for (int x = 0; x < X_SIZE; x++) {
                if ((y == 7) && (x == 7 || x == 8)) {  // Write the central square
                    printw("     ");
                } else if (x == 15) {
                    printw("────╢\n");
                    break;
                } else
                    printw("────┼");
            }
        }
    }
    // Write the bottom line
    printw("   ");
    printw("╚");
    for (int n = 0; n < X_SIZE; n++) {
        if (n == 15) {
            printw("════╝\n");
            break;
        }
        printw("════╧");
    }
    refresh();  // Refresh the screen
    int input;
    while (input != 27) {// 27 is the escape key
        input = getch();
    }
    endwin();   // End ncurses
}

int main()
{
    setMinLogLevel(loggingLevel);

    Board board = Board();
    board.initializeBoard();


    log(LogLevel::INFO, "Board initialized");


    board.drawBoard();


    log(LogLevel::INFO, "Board drawn");


    return 0;
}