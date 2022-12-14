#include "Game.h"
#include "Cell.h"
#include "Config.h"
#include <iostream>

Game::Game() {
    return;
}

Game::~Game() {
    return;
}

void Game::init(const char* title, int xpos, int ypos, bool fullscreen) {

    int width = CELL_SIZE * CELL_COLUMN_SIZE;
    int height = CELL_SIZE * CELL_ROW_SIZE;

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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Render created successfully!" << std::endl;
        } else 
            std::cout << "Failed to create renderer" << std::endl;

        isRunning = true;
    } else {
        isRunning = false;
    }

    board.init(CELL_COLUMN_SIZE, CELL_ROW_SIZE);
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
    board.update();
    return;
}

void Game::render() {
    
    // Set Background Color
    SDL_SetRenderDrawColor(renderer, BLACK, BLACK, BLACK, 255);
    SDL_RenderClear(renderer);

    // Draw Cell
    board.render(renderer);

    // Present
    SDL_RenderPresent(renderer);


    return;
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game terminated." << std::endl;
    return;
}