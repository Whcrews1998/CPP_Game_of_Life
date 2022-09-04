#include <iostream>
#include <cstring>
#include "Game-Board.h"
#include "Cell.h"
#include "Config.h"

GameBoard::GameBoard() {
    return;
}

GameBoard::~GameBoard() {

}

void GameBoard::init(int w, int h) {
    width = w;
    height = h;

    board = new Cell*[w];
    for (int i = 0; i < w; i++) {
        board[i] = new Cell[h];
    }

    for (int i = 0; i < w; i ++) {
        for (int j = 0; j < h; j++) {
            board[i][j].init(CELL_SIZE * i, CELL_SIZE * j);
        }
    }

}

int GameBoard::getNeighborCount(int x, int y) {
    int count = 0;

    // This formula gives the correct value of % of negative value in C++
    // (a % b + b) % b
    int up = ((y - 1) % CELL_ROW_SIZE + CELL_ROW_SIZE) % CELL_ROW_SIZE;
    int down = (y + 1) % CELL_ROW_SIZE;
    int left = ((x - 1) % CELL_COLUMN_SIZE + CELL_COLUMN_SIZE) % CELL_COLUMN_SIZE;
    int right = (x + 1) % CELL_COLUMN_SIZE;

    // Top Left
    if (board[left][up].getState() == true) {
        count++;
    }

    // Top
    if (board[x][up].getState() == true) {
        count++;
    }

    // Top Right
    if (board[right][up].getState() == true) {
        count++;
    }

    // Right
    if (board[right][y].getState() == true) {
        count++;
    }

    // Bottom Right
    if (board[right][down].getState() == true) {
        count++;
    }

    // Bottom
    if (board[x][down].getState() == true) {
        count++;
    }

    // Bottom Left
    if (board[left][down].getState() == true) {
        count++;
    }

    // Left
    if (board[left][y].getState() == true) {
        count++;
    }

    

    return count;
}

void GameBoard::update() {
    // Create copy of board
    Cell** boardCopy = new Cell*[width];
    for (int i = 0; i < width; i++) {
        boardCopy[i] = new Cell[height];
    }

    for (int i = 0; i < width; i ++) {
        for (int j = 0; j < height; j++) {
            
            // Set Pos
            boardCopy[i][j].init(board[i][j].rect.x, board[i][j].rect.y);
            
            // Get number of live neighbors
            int neighborCount = getNeighborCount(i, j);

            // Update cells according to rules
            if (board[i][j].getState() == true && (neighborCount == 2 || neighborCount == 3)) {
                boardCopy[i][j].setState(true);
            } else if (board[i][j].getState() == false && neighborCount == 3) {
                boardCopy[i][j].setState(true);
            } else {
                boardCopy[i][j].setState(false);
            }
            
        }
    }

    // Delete board 
    for (int i = 0; i < width; i++) {
        delete[] board[i];
    }
    delete[] board;

    // Assign board to copy
    board = boardCopy;
    
}

void GameBoard::render(SDL_Renderer* render) {
    for (int i = 0; i < width; i ++) {
        for (int j = 0; j < height; j++) {
            board[i][j].render(render);
        }
    }
}