#ifndef CELL_H
#define CELL_H
#include <SDL.h>

class Cell {

    public:
        Cell(const int x, const int y, const int w, const int h);
        void setState(bool val);
        void render(SDL_Renderer* renderer);

    private:
        bool isAlive;
        SDL_Rect rect;
};

#endif