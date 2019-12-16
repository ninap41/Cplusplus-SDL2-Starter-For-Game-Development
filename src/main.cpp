#include <iostream>;
#include <SDL2/SDL.h>;
using namespace std;
#include "Game.h"

int main() {
	// Game game;
	// while(game.isPlayin()) {
    // std::cout << "AHHHH Loop happening" << std::endl;
    // }  

	std::cout << "Hello Easy C++ project!" << std::endl;

    SDL_Init(SDL_INIT_VIDEO);
    // SDL_Window *window = SDL_CreateWindow(const char title, int x, int y, int w, int h, Uint32 flags);
    SDL_Window *window = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, int index, Unit32 flags)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    // now window will open and close right away
    // SDL_SetRenderDrawColor(renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a); rgba value rep
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    // delay to see the window for a bit
    // don't use SDL_Delay() to delay the program ending. Reason:
    // The program goes unresponsive because it's not responding, it's sleeping.
    // Sleeping for extraordinarily long periods is a bad idea for this very reason.
    // In order to properly respond to the OS, you need to run the message pump. In SDL this is accomplished with the Event system.
    SDL_Event evt;
    bool programrunning = true;
    while (programrunning)
    {
        SDL_WaitEvent(&evt);
        if (evt.type == SDL_QUIT)
            programrunning = false;
    }
  
}
