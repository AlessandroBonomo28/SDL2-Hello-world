#include <iostream>
#include <SDL2/SDL.h>
#include "src/game/game.hpp"
const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    Game game = Game( "Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    game.run();
    return 0;
}