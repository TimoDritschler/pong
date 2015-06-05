#include <SDL2/SDL.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    SDL_Init (SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Hello, World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_SetRenderDrawColor(ren, 156, 189, 15, 255);
    SDL_RenderClear(ren);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 50;
    rect.h = 50;

    SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
    SDL_RenderDrawRect(ren, &rect);

    SDL_RenderPresent(ren);
    SDL_Delay(3000);

    SDL_Quit();

    return 0;
}
