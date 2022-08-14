#ifndef CELL_H
#define CELL_H
#include <SDL.h>

class Cell {

    public:
        Cell();
        void init(const int x, const int y);
        void setState(bool val);
        void render(SDL_Renderer* renderer);

    private:
        bool isAlive;
        SDL_Rect rect;
};

#endif