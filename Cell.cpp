#include <stdlib.h>
#include "Cell.h"
#include "Config.h"

Cell::Cell() {

    // Set State
    if (rand() % 2 == 0)
        isAlive = false;
    else 
        isAlive = true;

}

void Cell::init(const int x, const int y) {
    rect.x = x;
    rect.y = y;
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;
}

void Cell::setState(bool val) {
    isAlive = val;
}

void Cell::render(SDL_Renderer* renderer) {
    if (isAlive) {
        SDL_SetRenderDrawColor(renderer, BLACK, BLACK, BLACK, 255);
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_SetRenderDrawColor(renderer, WHITE, WHITE, WHITE, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
    
}