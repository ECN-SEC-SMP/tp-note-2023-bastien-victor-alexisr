/**
 * @file board.cpp
 * @author Bastien, Victor, AlexisR ()
 * @brief Class for the board
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "board.h"
#include "log.h"
#include <vector>
#include <algorithm>
#include <set>

const string red("\033[1;41m");
const string green("\033[1;42m");
const string yellow("\033[1;43m");
const string cyan("\033[1;46m");
const string bold("\033[1m");
const string reset("\033[0m");

Board::Board(){
    for(int i = 0; i < X_SIZE; i++){
        for(int j = 0; j < Y_SIZE; j++){
            this->tiles[i][j] = new Tile();
        }
    }
    for(int i = 0; i < 4; i++){
        this->robots[i] = new Robot();
    }
}

Board::Board(Tile t[X_SIZE][Y_SIZE], Robot r[4]){
    for(int i = 0; i < X_SIZE; i++){
        for(int j = 0; j < Y_SIZE; j++){
            this->tiles[i][j] = &t[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        this->robots[i] = &r[i];
    }
}

Tile Board::getTile(int x, int y){
    return *this->tiles[x][y];
}

Robot Board::getRobot(int n){
    return *this->robots[n];
}

void Board::setTile(int x, int y, Tile t){
    this->tiles[x][y] = &t;
}

void Board::setRobot(int n, Robot r){
    this->robots[n] = &r;
}

void Board::initializeBoard(){
    this->placeWalls();
    this->placeTargets();
    this->placeRobots();
    // Print each tile's wall as log
    for(int x = 0; x < X_SIZE; x++){
        for(int y = 0; y < Y_SIZE; y++){
            char top = this->tiles[x][y]->checkHasTopWall() ? 'T' : '*';
            //Print the tile's position and its walls
            char right = this->tiles[x][y]->checkHasRightWall() ? 'R' : '*';
            char bottom = this->tiles[x][y]->checkHasBottomWall() ? 'B' : '*';
            char left = this->tiles[x][y]->checkHasLeftWall() ? 'L' : '*';
            // log(LogLevel::DEBUG, "Tile " + to_string(x) + "," + to_string(y) + " : " + top + right + bottom + left);
        }
    }
}

/**
 * @brief The placeWalls method will do the following:
 * - Place the board walls
 * - Place the central square walls
 * - Randomly place the outer walls on the board according to the rules of the game.
 * - Randomly place the inner corners on the board according to the rules of the game.
 * - Randomly place the last corner on the board according to the rules of the game.
 * 
 */
void Board::placeWalls(){
    srand(time(NULL));
    //Place the board walls
    for(int x = 0; x < X_SIZE; x++){
        for(int y = 0; y < Y_SIZE; y++){
            //If the tile is on the left edge of the board
            if(x == 0){
                this->tiles[x][y]->setLeftWall(true);
            }
            //If the tile is on the right edge of the board
            if(x == X_SIZE - 1){
                this->tiles[x][y]->setRightWall(true);
            }
            //If the tile is on the top edge of the board
            if(y == 0){
                this->tiles[x][y]->setTopWall(true);
            }
            //If the tile is on the bottom edge of the board
            if(y == Y_SIZE - 1){
                this->tiles[x][y]->setBottomWall(true);
            }

            //Place the central square walls
            if(x == 7 && y == 7){
                this->tiles[x][y]->setTopWall(true);
                this->tiles[x][y]->setLeftWall(true);
                this->tiles[x-1][y]->setRightWall(true);
                this->tiles[x][y-1]->setBottomWall(true);
            }
            if(x == 7 && y == 8){
                this->tiles[x][y]->setBottomWall(true);
                this->tiles[x][y]->setLeftWall(true);
                this->tiles[x-1][y]->setRightWall(true);
                this->tiles[x][y+1]->setTopWall(true);
            }
            if(x == 8 && y == 7){
                this->tiles[x][y]->setTopWall(true);
                this->tiles[x][y]->setRightWall(true);
                this->tiles[x+1][y]->setLeftWall(true);
                this->tiles[x][y-1]->setBottomWall(true);
            }
            if(x == 8 && y == 8){
                this->tiles[x][y]->setBottomWall(true);
                this->tiles[x][y]->setRightWall(true);
                this->tiles[x+1][y]->setLeftWall(true);
                this->tiles[x][y+1]->setTopWall(true);
            }
        }
    }
    //Randomly place the outer walls on the board according to the rules of the game. On each quarter, there will be 2 outer walls linked with the outer edge of the board. One vertical and one horizontal.
    //First quarter
    int verticalWallQ1 = rand() % 8;
    this->tiles[verticalWallQ1][0]->setRightWall(true);
    this->tiles[verticalWallQ1+1][0]->setLeftWall(true);
    int horizontalWallQ1 = rand() % 8;
    //to make sure that the two walls won't make a corner
    if (verticalWallQ1 == 0){
        while(horizontalWallQ1 == 0){
            horizontalWallQ1 = rand() % 8;
        }
    }
    this->tiles[0][horizontalWallQ1]->setBottomWall(true);
    this->tiles[0][horizontalWallQ1+1]->setTopWall(true);
    //Second quarter
    int verticalWallQ2 = rand() % 8 + 8;
    while(verticalWallQ2 == verticalWallQ1 + 8){//If the vertical wall is in the same column as the vertical wall in the first quarter, we need to generate a new random number.
        verticalWallQ2 = rand() % 8 + 8;
    }
    this->tiles[verticalWallQ2][0]->setLeftWall(true);
    this->tiles[verticalWallQ2-1][0]->setRightWall(true);
    int horizontalWallQ2 = rand() % 8;
    //to make sure that the two walls won't make a corner
    if (verticalWallQ2 == 15){
        while(horizontalWallQ2 == 0){
            horizontalWallQ2 = rand() % 8;
        }
    }
    this->tiles[15][horizontalWallQ2]->setBottomWall(true);
    this->tiles[15][horizontalWallQ2+1]->setTopWall(true);
    //Third quarter
    int verticalWallQ3 = rand() % 8;
    this->tiles[verticalWallQ3][15]->setRightWall(true);
    this->tiles[verticalWallQ3+1][15]->setLeftWall(true);
    int horizontalWallQ3 = rand() % 8 + 8;
    while(horizontalWallQ3 == horizontalWallQ1 + 8){//If the horizontal wall is in the same row as the horizontal wall in the first quarter, we need to generate a new random number.
        horizontalWallQ3 = rand() % 8 + 8;
    }
    //to make sure that the two walls won't make a corner
    if (verticalWallQ3 == 0){
        while(horizontalWallQ3 == 15){
            horizontalWallQ3 = rand() % 8 + 8;
        }
    }
    this->tiles[0][horizontalWallQ3]->setTopWall(true);
    this->tiles[0][horizontalWallQ3-1]->setBottomWall(true);
    //Fourth quarter
    int verticalWallQ4 = rand() % 8 + 8;
    while(verticalWallQ4 == verticalWallQ3 + 8){//If the vertical wall is in the same column as the vertical wall in the third quarter, we need to generate a new random number.
        verticalWallQ4 = rand() % 8 + 8;
    }
    this->tiles[verticalWallQ4][15]->setLeftWall(true);
    this->tiles[verticalWallQ4-1][15]->setRightWall(true);
    int horizontalWallQ4 = rand() % 8 + 8;
    while(horizontalWallQ4 == horizontalWallQ2 + 8){//If the horizontal wall is in the same row as the horizontal wall in the second quarter, we need to generate a new random number.
        horizontalWallQ4 = rand() % 8 + 8;
    }
    //to make sure that the two walls won't make a corner
    if (verticalWallQ4 == 15){
        while(horizontalWallQ4 == 15){
            horizontalWallQ4 = rand() % 8 + 8;
        }
    }
    this->tiles[15][horizontalWallQ4]->setTopWall(true);
    this->tiles[15][horizontalWallQ4-1]->setBottomWall(true);

    
    // Place the corners on each quarter            
    for(int quarter = 1; quarter < 5; quarter++){
        for(int i = 1; i < 5; i++){
            placeCorner(quarter, i);
        }
    }

    // Place the last corner containing the multicolored target
    int corner = rand() % 4 + 1;
    placeCorner(corner, 0);

}

void Board::placeCorner(int quarter, int corner){
    int minX, maxX, minY, maxY; 
    // cout << "Placing corner " << corner << " in quarter " << quarter << endl;
    switch(quarter){
        case 1:
            //First quarter
            minX = 1; maxX = 7; minY = 1; maxY = 7;
            break;
        case 2:
            //Second quarter
            minX = 8; maxX = 14; minY = 1; maxY = 7;
            break;
        case 3:
            //Third quarter
            minX = 1; maxX = 7; minY = 8; maxY = 14;
            break;
        case 4:
            //Fourth quarter
            minX = 8; maxX = 14; minY = 8; maxY = 14;
            break;
        default:
            log(LogLevel::ERROR, "quarter " + to_string(quarter) + " does not exist.");
            return;
    }

    int cornerX = rand() % (maxX - minX + 1) + minX;
    int cornerY = rand() % (maxY - minY + 1) + minY;
    //check that there is no wall on that tile and that it is not adjacent to the center
    while(this->tiles[cornerX][cornerY]->checkHasWall() ||
        (cornerX >= 6 && cornerX <= 9) && (cornerY >= 6 && cornerY <= 9) && !(cornerX == 6 && cornerY == 6) && !(cornerX == 9 && cornerY == 6) && !(cornerX == 6 && cornerY == 9) && !(cornerX == 9 && cornerY == 9))
    {
        cornerX = rand() % (maxX - minX + 1) + minX;
        cornerY = rand() % (maxY - minY + 1) + minY;
    }
    //choose a side for the first corner
    //sides : 0 = top, 1 = right, 2 = bottom, 3 = left
    int side1 = rand() % 4;
    //choose a side for the second corner (needs to be adjacent to the first corner)
    int side2 = rand() % 4;
    while(side2 == side1 || side2 == (side1 + 2) % 4){
        side2 = rand() % 4;
    }
    //print all the corners generated
    if (corner == 0){
        log(LogLevel::DEBUG, "Last corner is at (" + to_string(cornerX) + ", " + to_string(cornerY) + ")" + " with sides " + to_string(side1) + " and " + to_string(side2) + " and contains the multicolored target");
    }
    else{
        log(LogLevel::DEBUG, "Corner " + to_string(corner) + " of quarter " + to_string(quarter) + " is at (" + to_string(cornerX) + ", " + to_string(cornerY) + ")" + " with sides " + to_string(side1) + " and " + to_string(side2));
    }
    
    //check if one of the wall is adjacent to another wall by checking the 2 diagonally adjacent tiles touching the side
    bool isValid = true;
    // Check diagonal tiles adjacent to the top side
    if (this->tiles[cornerX - 1][cornerY - 1]->checkHasRightWall() ||
        this->tiles[cornerX - 1][cornerY - 1]->checkHasBottomWall() ||
        this->tiles[cornerX + 1][cornerY - 1]->checkHasLeftWall() ||
        this->tiles[cornerX + 1][cornerY - 1]->checkHasBottomWall()) {
        if (side1 == 0 || side2 == 0) {//if one of the side is the top side
            isValid = false;
        }
    }

    // Check diagonal tiles adjacent to the right side
    if (this->tiles[cornerX + 1][cornerY - 1]->checkHasLeftWall() ||
        this->tiles[cornerX + 1][cornerY - 1]->checkHasBottomWall() ||
        this->tiles[cornerX + 1][cornerY + 1]->checkHasLeftWall() ||
        this->tiles[cornerX + 1][cornerY + 1]->checkHasTopWall()) {
        if (side1 == 1 || side2 == 1) {//if one of the side is the right side
            isValid = false;
        }
    }

    // Check diagonal tiles adjacent to the bottom side
    if (this->tiles[cornerX + 1][cornerY + 1]->checkHasLeftWall() ||
        this->tiles[cornerX + 1][cornerY + 1]->checkHasTopWall() ||
        this->tiles[cornerX - 1][cornerY + 1]->checkHasRightWall() ||
        this->tiles[cornerX - 1][cornerY + 1]->checkHasTopWall()) {
        if (side1 == 2 || side2 == 2) {//if one of the side is the bottom side
            isValid = false;
        }
    }

    // Check diagonal tiles adjacent to the left side
    if (this->tiles[cornerX - 1][cornerY + 1]->checkHasRightWall() ||
        this->tiles[cornerX - 1][cornerY + 1]->checkHasTopWall() ||
        this->tiles[cornerX - 1][cornerY - 1]->checkHasRightWall() ||
        this->tiles[cornerX - 1][cornerY - 1]->checkHasBottomWall()) {
        if (side1 == 3 || side2 == 3) {//if one of the side is the left side
            isValid = false;
        }
    }

    if (!isValid) {
        //Generate a new corner
        log(LogLevel::DEBUG, "Invalid corner, generating new corner");
        placeCorner(quarter, corner);
        return; 
    }else{
        //set the walls on the tiles
        switch(side1){
            case 0:
                this->tiles[cornerX][cornerY]->setTopWall(true);
                this->tiles[cornerX][cornerY-1]->setBottomWall(true);
                break;
            case 1:
                this->tiles[cornerX][cornerY]->setRightWall(true);
                this->tiles[cornerX+1][cornerY]->setLeftWall(true);
                break;
            case 2:
                this->tiles[cornerX][cornerY]->setBottomWall(true);
                this->tiles[cornerX][cornerY+1]->setTopWall(true);
                break;
            case 3:
                this->tiles[cornerX][cornerY]->setLeftWall(true);
                this->tiles[cornerX-1][cornerY]->setRightWall(true);
                break;
            default:
                log(LogLevel::ERROR, "Unexpected side value: " + to_string(side1));
                break;
        }

        switch(side2){
            case 0:
                this->tiles[cornerX][cornerY]->setTopWall(true);
                this->tiles[cornerX][cornerY-1]->setBottomWall(true);
                break;
            case 1:
                this->tiles[cornerX][cornerY]->setRightWall(true);
                this->tiles[cornerX+1][cornerY]->setLeftWall(true);
                break;
            case 2:
                this->tiles[cornerX][cornerY]->setBottomWall(true);
                this->tiles[cornerX][cornerY+1]->setTopWall(true);
                break;
            case 3:
                this->tiles[cornerX][cornerY]->setLeftWall(true);
                this->tiles[cornerX-1][cornerY]->setRightWall(true);
                break;
            default: 
                log(LogLevel::ERROR, "Unexpected side value: " + to_string(side2));
                break;
        }

        //set the corner
        if(corner == 0){
            this->tiles[cornerX][cornerY]->setHasSpecialCorner(true);
        }else{
            this->tiles[cornerX][cornerY]->setHasCorner(true);
        }
    }
    
}

/**
 * @brief The placeTargets method will place the targets on the board.
 * @details The targets will be placed on tiles which have corners. On each quarter of the board, there will be 4 targets with the following symbols/colors:
 * - target "&", target "#", target "%" and target "$"
 * - color "R", color "G", color "B" and color "Y"    
 */
void Board::placeTargets(){
    vector<char> symbols = {'&', '#', '%', '$'};
    vector<char> colors = {'R', 'G', 'B', 'Y'};
    vector<pair<char, char>> combinations;
    vector<pair<char, char>> unasignedCombinations;

    for (const auto& symbol : symbols) {
        for (const auto& color : colors) {
            combinations.push_back(make_pair(symbol, color));
        }
    }

    // Shuffle the combinations randomly
    srand(time(0));
    random_shuffle(combinations.begin(), combinations.end());

    vector<vector<pair<char, char>>> vectors(4); // Store the four separate vectors

    for (const pair<char, char>& combination : combinations) {
    bool assigned = false; // Flag to indicate if the combination has been assigned

    // Iterate over the vectors to find a suitable one for the current combination
    for (int i = 0; i < 4; i++) {
        bool valid = true;

        // Check if the symbol or color already exists in the current vector
        for (const pair<char, char>& pair : vectors[i]) {
            if (pair.first == combination.first || pair.second == combination.second) {
                // Print the two pairs that are the same
                log(LogLevel::DEBUG, "Pair (" + string(1, pair.first) + ", " + string(1, pair.second) + ") is as a duplicate color and/or symbol of (" + string(1, combination.first) + ", " + string(1, combination.second) + ")");
                valid = false;
                break;
            }
        }

        // If the combination satisfies the conditions, add it to the current vector and update the flag
        if (valid) {
            vectors[i].push_back(combination);
            assigned = true;
            break;
        }
    }

    // If the combination couldn't be assigned to any vector, print a warning
    if (!assigned) {
        log(LogLevel::WARNING, "Combination (" + string(1, combination.first) + ", " + string(1, combination.second) + ") could not be assigned to any vector");
        unasignedCombinations.push_back(combination);
    }
    }


    //TODO: fix the unasigned combinations


    //print the size of the vectors
    for(int i = 0; i < 4; i++){
        log(LogLevel::DEBUG, "Vector " + to_string(i) + " size: " + to_string(vectors[i].size()));
    }


    // Print the four separate vectors
    for (int i = 0; i < 4; i++) {
        log(LogLevel::DEBUG, "Vector " + to_string(i) + ":");
        for (const auto& pair : vectors[i]) {
            log(LogLevel::DEBUG, "(" + string(1, pair.first) + ", " + string(1, pair.second) + ")");
        }
    }

    //place the targets on the board
    for(int quarter = 0; quarter < 4; quarter++){
        int minX = (quarter == 1 || quarter == 3) ? 0 : 8;
        int maxX = (quarter == 1 || quarter == 3) ? 8 : 16;
        int minY = (quarter == 1 || quarter == 2) ? 0 : 8;
        int maxY = (quarter == 1 || quarter == 2) ? 8 : 16;

        //go through all the tiles in the quarter
        for (auto combination : vectors[quarter]) {
            bool targetPlaced = false;  // flag to track successful placement
            for (int y = minY; y < maxY; y++) {
                for (int x = minX; x < maxX; x++) {
                    // check if the tile has a corner
                    if (this->tiles[x][y]->checkHasCorner()) {
                        // check if the tile has a target
                        if (!this->tiles[x][y]->checkHasTarget()) {
                            this->tiles[x][y]->setHasTarget(true);
                            this->tiles[x][y]->setTargetSymbol(combination.first);
                            this->tiles[x][y]->setTargetColor(combination.second);
                            targetPlaced = true;  // mark target as placed
                            //print the placed target
                            log(LogLevel::DEBUG, "Target of quarter " + to_string(quarter+1) +  " placed at (" + to_string(x) + ", " + to_string(y) + ") with symbol " + string(1, combination.first) + " and color " + string(1, combination.second));
                            break;
                        }
                    }
                }
                if (targetPlaced) {
                    break;  // no need to continue looping if target is placed
                }
            }
        }

    }

}

void Board::placeRobots(){
    //TODO
}

/**
 * @brief The drawBoard method will draw the board on the screen.
 * @details The board will be drawn using the tiles in the board.
 * 
 */
void Board::drawBoard(){
    // setlocale(LC_ALL, ""); 
    // initscr();  // Initialize ncurses
    // cbreak();
    // noecho();
    cout << "   ";

    // Write the numbers on the top
    for (int i = 0; i < X_SIZE; i++) {
        if (i == 15) {
            cout << " " << i << "  " << endl;
            break;
        }
        if (i < 10)
            cout << "  " << i << "  ";
        else
            cout << " " << i << "  ";
    }

    // Write the board
    // We go through all the tiles on the board
    for (int y = 0; y < Y_SIZE; y++) {
        // Write the top border
        if (y == 0) {
            for (int x = 0; x < X_SIZE; x++) {
                if (x == 0) {
                    cout << "   ╔════";
                } else {
                    if (this->tiles[x][y]->checkHasLeftWall()) {
                        cout << "╦════";
                    } else {
                        cout << "╤════";
                    }
                }
                if (x == 15) {
                    cout << "╗" << endl;
                }
            }
            for (int x = 0; x < X_SIZE; x++) {
                // Write the left border of the first line's tiles
                if (x == 0) {
                    cout << " " << y << " ║    ";
                } else {
                    if (this->tiles[x][y]->checkHasLeftWall()) {
                        cout << "║    ";
                    } else {
                        cout << "│    ";
                    }
                }
                if (x == 15) {
                    cout << "║" << endl;
                }
            }

        }
        // Write the rest of the board
        else {
            // Write the top side of the tiles
            for (int x = 0; x < X_SIZE; x++) {
                if (x == 0) {
                    if (this->tiles[x][y]->checkHasTopWall()) {
                        cout << "   ╠════";
                    } else {
                        cout << "   ╟────";
                    }
                } else {
                    if (this->tiles[x][y]->checkHasTopWall()) {
                        if (this->tiles[x][y]->checkHasLeftWall()) {
                            cout << "╔════";
                        } else if (this->tiles[x][y - 1]->checkHasLeftWall()) {
                            cout << "╚════";
                        } else {
                            if ((x == 8 && y == 7) || (x == 8 && y == 9)) {
                                if (y == 7) {
                                    cout << "╧";
                                } else if (y == 9) {
                                    cout << "╤";
                                }
                                cout << "════";
                            } else {
                                cout << "┤════";
                            }
                        }
                    } else if (this->tiles[x - 1][y]->checkHasTopWall()) {
                        if (this->tiles[x][y]->checkHasLeftWall()) {
                            cout << "╗────";
                        } else if (this->tiles[x][y - 1]->checkHasLeftWall()) {
                            cout << "╝────";
                        } else {
                            cout << "├────";
                        }
                    } else if (this->tiles[x][y]->checkHasLeftWall()) {
                        if (x == 7 && y == 8 || x == 9 && y == 8) {
                            if (x == 9) {
                                cout << "╟────";
                            } else if (x == 7) {
                                cout << "╢    ";
                            }
                        } else {
                            cout << "┴────";
                        }
                    } else if (this->tiles[x][y - 1]->checkHasLeftWall()) {
                        cout << "┬────";
                    } else {
                        if (x == 8 && y == 8) {
                            cout << "     ";
                        } else {
                            cout << "┼────";
                        }
                    }
                }
                if (x == 15) {
                    if (this->tiles[x][y]->checkHasTopWall()) {
                        cout << "╣" << endl;
                    } else {
                        cout << "╢" << endl;
                    }
                }
            }
            // Write the left border
            for (int x = 0; x < X_SIZE; x++) {
                // Write the numbers on the left
                if (x == 0) {
                    if (y < 10)
                        cout << " " << y;
                    else
                        cout << y;
                    cout << " ║    ";
                } else {
                    if (this->tiles[x][y]->checkHasLeftWall()) {
                        if (this->tiles[x][y]->checkHasSpecialCorner()) {
                            cout << "║" << red << " " << green << " " << cyan << " " << yellow << " ";
                            cout << reset;
                        }else if (this->tiles[x][y]->checkHasTarget()) {
                            string color;
                            if (this->tiles[x][y]->getTargetColor() == 'R') {
                                color = red;
                            } else if (this->tiles[x][y]->getTargetColor() == 'G') {
                                color = green;
                            } else if (this->tiles[x][y]->getTargetColor() == 'B') {
                                color = cyan;
                            } else if (this->tiles[x][y]->getTargetColor() == 'Y') {
                                color = yellow;
                            }
                            cout << "║" << bold << color << " " << this->tiles[x][y]->getTargetSymbol()  << this->tiles[x][y]->getTargetSymbol() << " ";
                            //reset color
                            cout << reset;
                        } else {
                            cout << "║    ";
                        }
                    } else {
                        if ((x == 8 && y == 7) || (x == 8 && y == 8)) {
                            cout << "     ";
                        } else {
                            if (this->tiles[x][y]->checkHasSpecialCorner()) {
                                cout << "│" <<red << " " << green << " " << cyan << " " << yellow << " ";
                                cout << reset;
                            }else if (this->tiles[x][y]->checkHasTarget()) {
                                string color;
                            if (this->tiles[x][y]->getTargetColor() == 'R') {
                                color = red;
                            } else if (this->tiles[x][y]->getTargetColor() == 'G') {
                                color = green;
                            } else if (this->tiles[x][y]->getTargetColor() == 'B') {
                                color = cyan;
                            } else if (this->tiles[x][y]->getTargetColor() == 'Y') {
                                color = yellow;
                            }
                            cout << "│" << bold << color << " " << this->tiles[x][y]->getTargetSymbol()  << this->tiles[x][y]->getTargetSymbol()<< " ";
                            //reset color
                            cout << reset;
                            } else {
                                cout << "│    ";
                            }
                        }
                    }
                }
                if (x == 15) {
                    cout << "║" << endl;
                }
            }
        }

        // Write the bottom border
        if (y == 15) {
            for (int x = 0; x < X_SIZE; x++) {
                if (x == 0) {
                    cout << "   ╚════";
                } else {
                    if (this->tiles[x][y]->checkHasLeftWall()) {
                        cout << "╩════";
                    } else {
                        cout << "╧════";
                    }
                }
                if (x == 15) {
                    cout << "╝" << endl;
                }
            }
        }
    }
    // refresh();  // Refresh the screen
    // int input;
    // while (input != 27) {// 27 is the escape key
    //     input = getch();
    // }
    // endwin();   // End ncurses
    
}
