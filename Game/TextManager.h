#pragma once
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class TextManager
{
private:
    TTF_Font* font;
    SDL_Texture *fontTexture;
    
public:
    SDL_Rect TextRect;
    void createFont(const std::string path, int size);
    void Text(std::string text, SDL_Color color, SDL_Renderer* ren);
    void createTexture(SDL_Surface* sur, SDL_Renderer* ren);
    void Render(SDL_Renderer* renderder, int x, int y);
    void closeFont();
    
};