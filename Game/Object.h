#pragma once
#include "TextureManager.h"
#include "Game.h"

class Object
{
public:
    Object();
    
    void createTexture(const std::string path, SDL_Renderer* renderer);
    void setSrc(int x , int y , int w, int h);
    void setDest(int x , int y , int w, int h);
        
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture* getTexture();

private:
       SDL_Texture* Texture;
};