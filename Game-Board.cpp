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
            board[i][j].init(CELL_SIZE * j, CELL_SIZE * i);
        }
    }

}

void GameBoard::update() {
    // Create copy of board
    // Iterate through cells
    // Update board accordingly
}

void GameBoard::render(SDL_Renderer* render) {
    for (int i = 0; i < width; i ++) {
        for (int j = 0; j < height; j++) {
            board[i][j].render(render);
        }
    }
}