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

/**
 * @brief The Tile class represents a single tile on the game board. 
 * @details Since the game board is a 16x16 grid, there are 256 tiles in total. Each tile can have walls on one or more of its sides, a target and/or a robot.
 */
class Tile{
    private: 
        bool topWall, bottomWall, leftWall, rightWall;
        bool hasTarget;
        bool hasCorner;
        bool hasSpecialCorner;
        bool hasRobot;
        bool isCentralTile;
        char targetColor;
        char targetSymbol;
        char robotColor;

    public:
        Tile();
        Tile(bool t, bool b, bool l, bool r, bool hasT, bool hasC, bool hasSC, bool hasR, bool isCentral, char tColor, char tSymbol, char rColor);
        bool checkHasWall();
        bool checkHasTopWall();
        bool checkHasBottomWall();
        bool checkHasLeftWall();
        bool checkHasRightWall();
        bool checkHasTarget();
        bool checkHasCorner();
        bool checkHasSpecialCorner();   
        bool checkHasRobot();
        bool checkIsCentralTile();
        char getTargetColor();
        char getTargetSymbol();
        char getRobotColor();
        void setTopWall(bool t);
        void setBottomWall(bool b);
        void setLeftWall(bool l);
        void setRightWall(bool r);
        void setHasTarget(bool t);
        void setHasCorner(bool c);
        void setHasSpecialCorner(bool sc);
        void setHasRobot(bool r);
        void setIsCentralTile(bool c);
        void setTargetColor(char c);
        void setTargetSymbol(char s);
        void setRobotColor(char c);
};

#endif // TILE_H