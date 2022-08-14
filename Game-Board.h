#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include "Cell.h"
class GameBoard {
    public:
        GameBoard();
        ~GameBoard();

        void init(int w, int h);
        void update();
        void render(SDL_Renderer* render);
    private:
        int width;
        int height;
        Cell** board;
};

#endif