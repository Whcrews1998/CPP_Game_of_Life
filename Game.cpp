#include "Game.h"
#include <iostream>

Game::Game() {
    return;
}

Game::~Game() {
    return;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flag = 0;
    if (fullscreen) 
        flag = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING)  == 0) {
        std::cout << "SDL Initialized!" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);

        if (window) 
            std::cout << "Window created successfully" << std::endl;
        else 
            std::cout << "Faield to create window" << std::endl;
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            std::cout << "Render created successfully!" << std::endl;
        } else 
            std::cout << "Failed to create renderer" << std::endl;

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }

    return;
}

void Game::update() {
    return;
}

void Game::render() {
    SDL_RenderClear(renderer);

    return;
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game terminated." << std::endl;
    return;
}