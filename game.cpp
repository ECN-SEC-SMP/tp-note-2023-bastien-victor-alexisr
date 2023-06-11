/**
 * @file game.cpp
 * @author Bastien, Victor, AlexisR ()
 * @brief Class for a game
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "game.h"

Game::Game(Board b, Player p[]){
    this->board = b;
    for(int i = 0; i < 4; i++){
        this->players[i] = &p[i];
    }
    this->timer = 0;
    this->movecount = 0;
}

Board Game::getBoard(){
    return this->board;
}

Tile Game::drawObjectiveTile(){
    //TODO
}

void Game::setBoard(Board b){
    this->board = b;
}

void Game::startTimer(){
    //TODO
}

void Game::stopTimer(){
    //TODO
}

int Game::getTimer(){
    return this->timer;
}

int Game::getMoveCount(){
    return this->movecount;
}

Tile Game::getObjectiveTile(){
    return this->objectiveTile;
}

void Game::selectPlayer(){
    //TODO
}

void Game::moveRobot(){
    //TODO
}

void Game::updateScore(){
    //TODO
}

void Game::nextRound(){
    //TODO
}