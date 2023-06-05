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

class Game{
    private:
        Board board;
        Tile objectiveTile;
        int timer;
        int movecount;
        Player *players;

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