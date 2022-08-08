#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[]) {
    Game* game = nullptr;
    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}