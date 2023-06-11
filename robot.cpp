/**
 * @file robot.cpp
 * @author Bastien, Victor, AlexisR 
 * @brief Class for a robot
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "robot.h"

Robot::Robot(){
    this->color = 0;
    this->number = 0;
    this->positionX = 0;
    this->positionY = 0;
    this->tile = Tile();
}

Robot::Robot(int c, int n, int x, int y, Tile t){
    this->color = c;
    this->number = n;
    this->positionX = x;
    this->positionY = y;
    this->tile = t;
}

int Robot::getColor(){
    return this->color;
}

int Robot::getNumber(){
    return this->number;
}

int Robot::getPositionX(){
    return this->positionX;
}

int Robot::getPositionY(){
    return this->positionY;
}

Tile Robot::getTile(){
    return this->tile;
}

void Robot::setColor(int c){
    this->color = c;
}

void Robot::setNumber(int n){
    this->number = n;
}

void Robot::setPositionX(int x){
    this->positionX = x;
}

void Robot::setPositionY(int y){
    this->positionY = y;
}

void Robot::setTile(Tile t){
    this->tile = t;
}

void Robot::moveRobot(){
    //TODO
}

void Robot::checkWallCollision(){
    //TODO
}

void Robot::checkRobotCollision(){
    //TODO
}