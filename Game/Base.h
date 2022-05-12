#pragma once
#include "TextureManager.h"
#include "Game.h"
#include "Object.h"
class Base : public Object
{
private:
    int distance1 = 0;
	int distance2 = 720;

public:
    void Render(SDL_Renderer* renderer);
    void baseUpdate1();
    void baseUpdate2();
};
