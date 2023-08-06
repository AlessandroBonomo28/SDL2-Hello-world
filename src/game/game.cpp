#include "game.hpp"
#include <iostream>
Game::Game(const char *title, int x, int y, int w,int h, Uint32 flags){
    isRunning = false;
    if(SDL_Init( SDL_INIT_EVERYTHING ) != 0 ){
        std::cout << "Could not initialize SDL: " << SDL_GetError( ) << std::endl;
        return;
    }

    window = SDL_CreateWindow( title, x, y, w, h, flags);

    if ( window == NULL )
    {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL){
        std::cout << "Could not create renderer: " << SDL_GetError( ) << std::endl;
        return;
    }
    isRunning = true;
}

Game::~Game(){
    clean();
}

void Game::run(){
    while(isRunning) {
        frameStart = SDL_GetTicks();
        handleInput();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::stop(){
    isRunning = false;
}

const int grayScale = 128;
void Game::update(){
    SDL_SetRenderDrawColor(renderer, grayScale, grayScale, grayScale, 255);
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::handleInput(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            stop();
            break;
        
        default:
            break;
    }
}

void Game::clean(){
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}