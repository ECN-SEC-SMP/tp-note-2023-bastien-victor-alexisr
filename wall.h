/**
 * @file wall.h
 * @author Bastien, Victor, AlexisR
 * @brief Class for a wall
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef WALL_H
#define WALL_H

#include "tile.h"

class Wall{
    private:
        bool isHorizontal;
        bool isPlaced;
        int positionX;
        int positionY;
        Tile tile1;
        Tile tile2;

    public:
        Wall();
        Wall(bool h, bool p, int x, int y, Tile t1, Tile t2);
        bool isHorizontal();
        bool isPlaced();
        int getPositionX();
        int getPositionY();
        Tile getTile1();
        Tile getTile2();
        void setIsHorizontal(bool h);
        void setIsPlaced(bool p);
        void setPositionX(int x);
        void setPositionY(int y);
        void setTile1(Tile t1);
        void setTile2(Tile t2);
        void placeWall();
        void removeWall();
};

#endif // WALL_H