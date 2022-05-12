#include "Base.h"


void Base::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, getTexture(), &srcRect, &destRect);
}

void Base::baseUpdate1()
{
    if (distance1 <= -720)
	{
		distance1 = 0;
	}
	else
	{
		distance1 = distance1 - 2;
		setDest(distance1, 660 , 800, 140);
	}
}

void Base::baseUpdate2()
{
    
	if (distance2 <= 0)
	{
		distance2 = 720;
	}
	else
	{
		distance2 = distance2 - 2;
		setDest(distance2, 660, 800, 140);
	}
}
