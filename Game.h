#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>

class Game {

    public:
        Game();
        ~Game();

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running();
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

};

#endif