#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    // Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //Change Draw Color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear Display
    SDL_RenderClear(renderer);

    // Show render
    SDL_RenderPresent(renderer);

    // You have to poll the event 
    // queue for the application to run properly
    SDL_Event event;
    bool isRunning = true;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}