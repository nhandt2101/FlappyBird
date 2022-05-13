#include "GameOver.h"

void GameOver::Render(SDL_Renderer*ren)
{
    setSrc(0, 0, 192, 42);
    setDest(100, 50, 400, 200);
    SDL_RenderCopy(ren, getTexture(), &srcRect, &destRect);
}

 