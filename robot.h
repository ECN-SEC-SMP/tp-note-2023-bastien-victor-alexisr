/**
 * @file robot.h
 * @author Bastien, Victor, AlexisR
 * @brief Class for a robot
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "tile.h"

/**
 * @brief The Robot class represents a single robot on the game board.
 * @details There are 4 robots in total, each with a different color. Each robot will have a position on the game board, which is represented by the tile that the robot is on.
 */
class Robot{
    private:
        char color;
        int number;
        int positionX;
        int positionY;
        Tile tile;

    public:
        Robot();
        Robot(char c, int n, int x, int y, Tile t);
        int getColor();
        int getNumber();
        int getPositionX();
        int getPositionY();
        Tile getTile();
        void setColor(char c);
        void setNumber(int n);
        void setPositionX(int x);
        void setPositionY(int y);
        void setTile(Tile t);
        void moveRobot();
        void checkWallCollision();
        void checkRobotCollision();
};

#endif // ROBOT_H