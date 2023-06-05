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

class Robot{
    private:
        int color;
        int number;
        int positionX;
        int positionY;
        Tile tile;

    public:
        Robot();
        Robot(int c, int n, int x, int y, Tile t);
        int getColor();
        int getNumber();
        int getPositionX();
        int getPositionY();
        Tile getTile();
        void setColor(int c);
        void setNumber(int n);
        void setPositionX(int x);
        void setPositionY(int y);
        void setTile(Tile t);
        void moveRobot();
        void checkWallCollision();
        void checkRobotCollision();
};

#endif // ROBOT_H