#include "Object.h"

Object::Object()
{
    this -> Texture = NULL;
}

void Object::createTexture(const std::string path, SDL_Renderer* renderer)
{
    this -> Texture = TextureManager::loadTexture(path, renderer); 
}

void Object::setDest(int x , int y , int w, int h)
{
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;
}

void Object::setSrc(int x , int y , int w, int h)
{
    srcRect.x = x;
    srcRect.y = y;
    srcRect.w = w;
    srcRect.h = h;
}

SDL_Texture* Object::getTexture()
{
    return Texture;
}
