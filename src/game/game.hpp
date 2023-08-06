#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
public:
    Game(const char *title, int x, int y, int w,int h, Uint32 flags);
    ~Game();

    void run();
    bool running() { return isRunning;}
    void stop();
private:
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    void update();
    void render();
    void handleInput();
    void clean();
};

#endif