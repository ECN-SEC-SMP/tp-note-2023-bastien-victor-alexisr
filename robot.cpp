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
#include "board.h"
#include "log.h"

Robot::Robot(){
    this->color = ' ';
    this->number = 0;
    this->positionX = 0;
    this->positionY = 0;
    this->tile = new Tile();
    this->board = new Board();
}

Robot::Robot(char c, int n, int x, int y, Tile* t, Board* b){
    this->color = c;
    this->number = n;
    this->positionX = x;
    this->positionY = y;
    this->tile = t;
    this->board = b;
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

Tile* Robot::getTile(){
    return this->tile;
}

Board* Robot::getBoard(){
    return this->board;
}

void Robot::setColor(char c){
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

void Robot::setTile(Tile* t){
    this->tile = t;
}

void Robot::setBoard(Board* b){
    this->board = b;
}

//TODO: Fix collision with another robot when there is no tile between them 
//TODO: Fix robot color not being displayed on the board when moving robot
void Robot::moveRobot(char direction){ 
    int currentX = this->positionX;
    int currentY = this->positionY;
    if(direction == 'N'){
        if(this->positionY == 0)return;
        for(int i = this->positionY; i >= 0; i--){
            if(this->board->getTile(this->positionX, i)->checkHasTopWall() || this->board->getTile(this->positionX, i-1)->checkHasRobot()){
                this->positionY = i;
                this->board->getTile(this->positionX, i)->setHasRobot(true);
                this->board->getTile(currentX, currentY)->setHasRobot(false);
                log(LogLevel::INFO, "Robot moved to tile: " + std::to_string(this->positionX) + ", " + std::to_string(this->positionY));
                break;             
            }
        }
    }else if(direction == 'S'){
        if(this->positionY == 15)return;
        for(int i = this->positionY; i < 16; i++){
            if(this->board->getTile(this->positionX, i)->checkHasBottomWall() || this->board->getTile(this->positionX, i+1)->checkHasRobot()){
                this->positionY = i;
                this->board->getTile(this->positionX, i)->setHasRobot(true);
                this->board->getTile(currentX, currentY)->setHasRobot(false);
                log(LogLevel::INFO, "Robot moved to tile: " + std::to_string(this->positionX) + ", " + std::to_string(this->positionY));
                break;             
            }
        }
    }else if(direction == 'E'){
        if(this->positionX == 15)return;
        for(int i = this->positionX; i < 16; i++){
            if(this->board->getTile(i, this->positionY)->checkHasRightWall() || this->board->getTile(i+1, this->positionY)->checkHasRobot()){
                this->positionX = i;
                this->board->getTile(i, this->positionY)->setHasRobot(true);
                this->board->getTile(currentX, currentY)->setHasRobot(false);
                log(LogLevel::INFO, "Robot moved to tile: " + std::to_string(this->positionX) + ", " + std::to_string(this->positionY));
                break;             
            }
        }
    }else if(direction == 'W'){
        if(this->positionX == 0)return;
        for(int i = this->positionX; i >= 0; i--){
            if(this->board->getTile(i, this->positionY)->checkHasLeftWall() || this->board->getTile(i-1, this->positionY)->checkHasRobot()){
                this->positionX = i;
                this->board->getTile(i, this->positionY)->setHasRobot(true);
                this->board->getTile(currentX, currentY)->setHasRobot(false);
                log(LogLevel::INFO, "Robot moved to tile: " + std::to_string(this->positionX) + ", " + std::to_string(this->positionY));
                break;             
            }
        }
    }
}