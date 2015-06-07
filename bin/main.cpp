#include <SDL2/SDL.h>
#include <stdio.h>
#include "stuff.hpp"

bool CGame::init () {
    lastTime = 0;
    dt = 0;
    SDL_Init (SDL_INIT_EVERYTHING);

    mainWindow = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    auto newThing = std::make_shared<CGrowingBox>();
    manager->registerNew("GrowBox", newThing);

    return true;
}

bool CGame::isStopping () {
    if (SDL_GetTicks() > 3000)
        return true;
    else
        return false;
}

bool CGame::run () {

    uint32_t curTime = SDL_GetTicks();
    dt = curTime - lastTime;
    lastTime = curTime;

    SDL_SetRenderDrawColor(mainRenderer, 156, 189, 15, 255);
    SDL_RenderClear(mainRenderer);

    auto growBox = manager->getEntityByName("GrowBox");
    growBox->draw->draw(mainRenderer);

    SDL_RenderPresent(mainRenderer);

    return true;
}


CGame::~CGame () {
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
}


int main (int argc, char **argv)
{
    (void) argc;
    (void) argv;

    CGame *theGame = new CGame();
    theGame->init();

    while (!theGame->isStopping()) {
        theGame->run();
    }

    delete theGame;
    return 0;
}
