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

const LogLevel loggingLevel = LogLevel::WARNING;// Set the minimum log level to log

void drawBlankBoard()
{
    printf("   ");
    // Write the numbers on the top
    for (int i = 0; i < X_SIZE; i++) {
        if (i == 15) {
            printf("  %d\n", i);
            break;
        }
        if (i < 10)
            printf("  %d  ", i);
        else
            printf("  %d ", i);
    }
    // Write the top line
    printf("   ╔");
    for (int j = 0; j < X_SIZE; j++) {
        if (j == 15) {
            printf("════╗\n");
            break;
        }
        printf("════╤");
    }
    // Write the middle lines
    for (int y = 0; y < Y_SIZE; y++) {
        // Write the numbers on the left
        if (y < 10)
            printf(" %d ", y);
        else
            printf("%d ", y);

        printf("║");
        for (int x = 0; x < X_SIZE; x++) {
            if ((y == 7 || y == 8) && (x == 7 || x == 8)) {  // Write the central square
                printf("     ");
            } else if (x == 15) {
                printf("    ║\n");
                break;
            } else
                printf("    │");
        }
        if (y < 15) {
            printf("   ");
            printf("╟");
            for (int x = 0; x < X_SIZE; x++) {
                if ((y == 7) && (x == 7 || x == 8)) {  // Write the central square
                    printf("     ");
                } else if (x == 15) {
                    printf("────╢\n");
                    break;
                } else
                    printf("────┼");
            }
        }
    }
    // Write the bottom line
    printf("   ");
    printf("╚");
    for (int n = 0; n < X_SIZE; n++) {
        if (n == 15) {
            printf("════╝\n");
            break;
        }
        printf("════╧");
    }
}

int main()
{
    setMinLogLevel(loggingLevel);

    Board* board = new Board();
    Player* players[4];
    for(int i = 0; i < 4; i++){
        players[i] = new Player("Player " + to_string(i), i);
    }
    Robot* robots[4];
    for(int i = 0; i < 4; i++){
        robots[i] = new Robot();
    }
    char colors[4] = {'R', 'B', 'G', 'Y'};
    for(int i = 0; i < 4; i++){
        robots[i]->setColor(colors[i]);
        robots[i]->setNumber(i);
        robots[i]->setBoard(board);
    }
    Game game = Game(board, players, robots);
    game.initGame();

    return 0;
}