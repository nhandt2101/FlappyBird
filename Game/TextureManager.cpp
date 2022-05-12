#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const std::string path, SDL_Renderer* ren)
{
        SDL_Surface* surface = IMG_Load(path.c_str());
        SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
        SDL_FreeSurface(surface);
        return tex;
}