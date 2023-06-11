/**
 * @file game.h
 * @author Bastien, Victor, AlexisR
 * @brief Class for a game
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tile.h"
#include "player.h"

/**
 * @brief The Game class represents the game
 * @details In each round, one of the players flips over an objective tile. The goal is to move the robot with the color matching the tile to the objective square with the same symbol as the tile. If the multicolored tile is drawn, the objective is to move any robot to the multicolored square on the grid.
The players play simultaneously, each contemplating how to move the robot using the movement rules. When one of them believes to have found a solution, they announce the number of moves they plan to make to achieve the objective, and then they flip the hourglass.
The other players have until the end of the hourglass to propose better solutions using fewer moves.
After the hourglass runs out, the player with the solution requiring the fewest moves presents their solution and wins the tile. If they fail in their demonstration, the player who proposed the immediately higher number of moves presents their solution, and so on until a valid solution is found.
*/
class Game{
    private:
        Board board;
        Tile objectiveTile;
        int timer;
        int movecount;
        Player *players[];

    public:
        Game(Board b, Player p[]);
        Board getBoard();
        Tile drawObjectiveTile();
        void setBoard(Board b);
        void startTimer();
        void stopTimer();
        int getTimer();
        int getMoveCount();
        Tile getObjectiveTile();
        void selectPlayer();
        void moveRobot();
        void updateScore();
        void nextRound();
};

#endif // GAME_H