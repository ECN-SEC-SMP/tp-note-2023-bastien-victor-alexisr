/**
 * @file tile.h
 * @author Bastien, Victor, AlexisR
 * @brief Class for a tile
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TILE_H
#define TILE_H

#include <iostream>
using namespace std;

class Tile{
    private: 
        bool topWall, bottomWall, leftWall, rightWall;
        bool hasTarget;
        bool hasRobot;
        bool isCentralTile;
        int targetColor;
        int targetSymbol;
        int robotColor;
        int robotNumber;

    public:
        Tile();
        Tile(bool t, bool b, bool l, bool r, bool hasT, bool hasR, bool isCentral, int tColor, int tSymbol, int rColor, int rNumber);
        bool checkHasTopWall();
        bool checkHasBottomWall();
        bool checkHasLeftWall();
        bool checkHasRightWall();
        bool checkHasTarget();
        bool checkHasRobot();
        bool checkIsCentralTile();
        int getTargetColor();
        int getTargetSymbol();
        int getRobotColor();
        int getRobotNumber();
        void setTopWall(bool t);
        void setBottomWall(bool b);
        void setLeftWall(bool l);
        void setRightWall(bool r);
        void setHasTarget(bool t);
        void setHasRobot(bool r);
        void setIsCentralTile(bool c);
        void setTargetColor(int c);
        void setTargetSymbol(int s);
        void setRobotColor(int c);
        void setRobotNumber(int n);
};

#endif // TILE_H