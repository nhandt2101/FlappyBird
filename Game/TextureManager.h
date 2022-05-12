#pragma once
#include "Game.h"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const std::string path, SDL_Renderer* ren);
};
