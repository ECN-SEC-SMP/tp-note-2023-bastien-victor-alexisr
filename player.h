/**
 * @file player.h
 * @author Bastien, Victor, AlexisR
 * @brief Class for a player
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player{
    private:
        string name;
        int score;
        int proposedMoves;

    public:
        Player();
        Player(string n, int s);
        string getName();
        void setProposedMoves(int m);
        int getScore();
        void setName(string n);
        void setScore(int s);
        void incrementScore();
};

#endif //PLAYER_H