#include "Game.h"

Game*game = new Game();

int main(int argc, char** argv)
{
    const int FPS = 60;
	const int DELAY_TIME = 1000 / FPS;

	Uint64 frameStart;
	Uint64 frameTime;
    
    game -> init();
    game -> MainMenu();
    
    while(game -> running())
    {
        frameStart = SDL_GetTicks();
        
        game-> handleEvent();
        game->update();
        game-> render();
        
        frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(DELAY_TIME - frameTime);
		}
        
    }
    game->clear();
    return 0;
}