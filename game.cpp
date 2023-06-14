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
#include "log.h"
#include <conio.h>
#include "robot.h"

Game::Game(Board* b, Player* p[4], Robot* r[4]){
    this->board = b;
    for(int i = 0; i < 4; i++){
        this->players[i] = p[i];
    }
    for(int i = 0; i < 4; i++){
        this->robots[i] = r[i];
    }
    this->timer = 0;
    this->movecount = 0;
}

Board* Game::getBoard(){
    return this->board;
}

Tile Game::drawObjectiveTile(){
    //TODO
}

/**
 * @brief The placeRobots method will place the robots on the board.
 * @details The robots will be placed randomly on the board. 
 * 
 */
void Game::placeRobots(){
    //choose a random tile for each robot
    for(int i = 0; i < 4; i++){
        int x = rand() % 16;
        int y = rand() % 16;
        //check if the tile is empty or if it is a center tile
        if(!this->board->getTile(x,y)->checkHasRobot() && !this->board->getTile(x,y)->checkIsCentralTile()){
            this->board->getTile(x,y)->setHasRobot(true);
            this->board->getTile(x,y)->setRobotColor(this->robots[i]->getColor());
            this->robots[i]->setPositionX(x);
            this->robots[i]->setPositionY(y);
            //print the placed robot
            log(LogLevel::DEBUG, "Robot " + to_string(i+1) + " placed at (" + to_string(x) + ", " + to_string(y) + ") with number " + to_string(this->robots[i]->getNumber()) + " and color " + string(1, this->robots[i]->getColor()));
        }
        else{
            //if the tile is not empty, choose another tile
            i--;
        }
    }
}

Robot* Game::getRobot(int i){
    return this->robots[i];
}

void Game::setRobot(int i, Robot* r){
    this->robots[i] = r;
}

void Game::setBoard(Board* b){
    this->board = b;
}

void Game::initGame(){
    log(LogLevel::INFO, "Initializing game");
    this->board->initializeBoard();
    this->placeRobots();
    this->board->drawBoard();
    this->getInputs();
}

string colorToString(char c){
    switch (c) {
        case 'R':
            return "red";
            break;
        case 'B':
            return "blue";
            break;
        case 'G':
            return "green";
            break;
        case 'Y':
            return "yellow";
            break;
        default:
            return "unknown";
            break;
    }
}

void Game::getInputs(){
    char input;
    int selectedRobot = 0;
    string color;
    while (true) {
        log(LogLevel::INFO, "Controls: z = up, s = down, q = left, d = right, n = next robot");
        log(LogLevel::INFO, "Current robot: " + colorToString(robots[selectedRobot]->getColor()));
        cin >> input;
        switch (input) {
            case 'z':
                log(LogLevel::INFO, "Robot " + colorToString(robots[selectedRobot]->getColor()) + " moved up");
                this->robots[selectedRobot]->moveRobot('N');
                this->board->drawBoard();
                break;
            case 's':
                log(LogLevel::INFO, "Robot " + colorToString(robots[selectedRobot]->getColor()) + " moved down");
                this->robots[selectedRobot]->moveRobot('S');
                this->board->drawBoard();
                break;
            case 'q':
                log(LogLevel::INFO, "Robot " + colorToString(robots[selectedRobot]->getColor()) + " moved left");
                this->robots[selectedRobot]->moveRobot('W');
                this->board->drawBoard();
                break;
            case 'd':
                log(LogLevel::INFO, "Robot " + colorToString(robots[selectedRobot]->getColor()) + " moved right");
                this->robots[selectedRobot]->moveRobot('E');
                this->board->drawBoard();
                break;
            case 'n':
                selectedRobot = (selectedRobot + 1) % 4;
                color = colorToString(robots[selectedRobot]->getColor());
                break;
            case 'e':
                log(LogLevel::INFO, "Exiting game");
                return;
                break;
            default:
                log(LogLevel::INFO, "Unknown input");
                break;
        }
    }
    return;
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

Tile* Game::getObjectiveTile(){
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