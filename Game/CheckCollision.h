#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class CheckCollision
{
    private:
    
    public:
        static bool Check_Collision(SDL_Rect* a, SDL_Rect *b);
};
