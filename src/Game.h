#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include "Game-Board.h"


class Game {

    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;};
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

        GameBoard board;

};

#endif