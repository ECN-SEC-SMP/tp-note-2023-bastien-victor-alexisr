/**
 * @file tile.cpp
 * @author Bastien, Victor, AlexisR
 * @brief Class for Tile (Implementation File)
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "tile.h"

Tile::Tile(){
    this->topWall = false;
    this->bottomWall = false;
    this->leftWall = false;
    this->rightWall = false;
    this->hasTarget = false;
    this->hasCorner = false;
    this->hasSpecialCorner = false;
    this->hasRobot = false;
    this->isCentralTile = false;
    this->targetColor = ' ';
    this->targetSymbol = ' ';
    this->robotColor = ' ';
}

Tile::Tile(bool t, bool b, bool l, bool r, bool hasT, bool hasC, bool hasSC, bool hasR, bool isCentral, char tColor, char tSymbol, char rColor){
    this->topWall = t;
    this->bottomWall = b;
    this->leftWall = l;
    this->rightWall = r;
    this->hasTarget = hasT;
    this->hasCorner = hasC;
    this->hasSpecialCorner = hasSC;
    this->hasRobot = hasR;
    this->isCentralTile = isCentral;
    this->targetColor = tColor;
    this->targetSymbol = tSymbol;
    this->robotColor = rColor;
}

bool Tile::checkHasWall(){
    return (this->topWall || this->bottomWall || this->leftWall || this->rightWall);
}

bool Tile::checkHasTopWall(){
    return this->topWall;
}

bool Tile::checkHasBottomWall(){
    return this->bottomWall;
}

bool Tile::checkHasLeftWall(){
    return this->leftWall;
}

bool Tile::checkHasRightWall(){
    return this->rightWall;
}

bool Tile::checkHasTarget(){
    return this->hasTarget;
}

bool Tile::checkHasCorner(){
    return this->hasCorner;
}

bool Tile::checkHasSpecialCorner(){
    return this->hasSpecialCorner;
}

bool Tile::checkHasRobot(){
    return this->hasRobot;
}

bool Tile::checkIsCentralTile(){
    return this->isCentralTile;
}

char Tile::getTargetColor(){
    return this->targetColor;
}

char Tile::getTargetSymbol(){
    return this->targetSymbol;
}

char Tile::getRobotColor(){
    return this->robotColor;
}

void Tile::setTopWall(bool t){
    this->topWall = t;
}

void Tile::setBottomWall(bool b){
    this->bottomWall = b;
}

void Tile::setLeftWall(bool l){
    this->leftWall = l;
}

void Tile::setRightWall(bool r){
    this->rightWall = r;
}

void Tile::setHasTarget(bool t){
    this->hasTarget = t;
}

void Tile::setHasCorner(bool c){
    this->hasCorner = c;
}

void Tile::setHasSpecialCorner(bool sc){
    this->hasSpecialCorner = sc;
}

void Tile::setHasRobot(bool r){
    this->hasRobot = r;
}

void Tile::setIsCentralTile(bool c){
    this->isCentralTile = c;
}

void Tile::setTargetColor(char c){
    this->targetColor = c;
}

void Tile::setTargetSymbol(char s){
    this->targetSymbol = s;
}

void Tile::setRobotColor(char c){
    this->robotColor = c;
}

