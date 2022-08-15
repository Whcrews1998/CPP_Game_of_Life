#ifndef CELL_H
#define CELL_H
#include <SDL.h>

class Cell {

    public:
        Cell();
        void init(const int x, const int y);
        void render(SDL_Renderer* renderer);

        void setState(bool val);
        bool getState() {return isAlive;};

        SDL_Rect rect;
    private:
        bool isAlive;
        
};

#endif