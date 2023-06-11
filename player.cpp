/**
 * @file player.cpp
 * @author Bastien, Victor, AlexisR ()
 * @brief Class for a player
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "player.h"

Player::Player(){
    this->name = "";
    this->score = 0;
    this->proposedMoves = 0;
}

Player::Player(string n, int s){
    this->name = n;
    this->score = s;
    this->proposedMoves = 0;
}

string Player::getName(){
    return this->name;
}

void Player::setProposedMoves(int m){
    this->proposedMoves = m;
}

int Player::getScore(){
    return this->score;
}

void Player::setName(string n){
    this->name = n;
}

void Player::setScore(int s){
    this->score = s;
}

void Player::incrementScore(){
    this->score++;
}