#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "Object.h"
#include "Background.h"

class GameOver: public Object
{   
    private:
    public:
        void Render(SDL_Renderer* ren);
};