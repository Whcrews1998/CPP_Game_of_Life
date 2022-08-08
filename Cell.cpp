#include "Cell.h"

Cell::Cell(const int x, const int y, const int w, const int h) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Set State
    isAlive = true;

}

void Cell::setState(bool val) {
    isAlive = val;
}

void Cell::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}