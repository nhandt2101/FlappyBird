#include "Background.h"
#include <cstdlib>

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &this->srcRect, &this->destRect);
}
void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &this->srcRect, &this->destRect);
}

void Background::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &this->srcRect, &this->destRect);
}

bool Background::Pipe_Above1Update(int incY, int& score,bool birdDie)
{
	
	this->incY1 = incY;
	if (pipeDistance1 <= -50)
	{
		pipeDistance1 += 700;
		if(!birdDie)
		{
		score++;
		}
		return true;
	}
	else
	{
		pipeDistance1 -= 3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance1, -100 + this->incY1, 65, 400);
		return false;
	}
}

bool Background::Pipe_Below1Update(int incY)
{
	this->incY1 = incY;
	if (pipeDistance1 <= -50)
	{
		pipeDistance1 += 700;
		return true;
	}
	else
	{
		pipeDistance1-= 3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance1, 450 + this->incY1, 65, 400);
		return false;
	}
}

bool Background::Pipe_Above2Update(int incY, int& score, bool birdDie)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -50)
	{
		pipeDistance2 += 700;
		if(!birdDie)
		{
		score++;
		}
		return true;
	}
	else
	{
		pipeDistance2 -= 3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance2, -100 + this->incY2, 65, 400);
		return false;
	}
}

bool Background::Pipe_Below2Update(int incY)
{
	this->incY2 = incY;
	if (pipeDistance2 <= -50)
	{
		pipeDistance2 += 700;
		return true;
	}
	else
	{
		pipeDistance2 -= 3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance2, 450 + this->incY2, 65, 400);
		return false;
	}
}

bool Background::Pipe_Above3Update(int incY, int& score, bool birdDie)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -50)
	{
		pipeDistance3 += 700;
		pipeDistance3 -= 3;
		if(!birdDie)
		{
		score++;
		}
		return true;
	}
	else
	{
		pipeDistance3 -= 3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance3, -100 + this->incY3, 65, 400);
		return false;
	}
}
 
bool Background::Pipe_Below3Update(int incY)
{
	this->incY3 = incY;
	if (pipeDistance3 <= -50)
	{
		pipeDistance3 += 700;
		pipeDistance3-=3;
		return true;
	}
	else
	{
		pipeDistance3-=3;
		setSrc(0, 0, 25, 100);
		setDest(pipeDistance3, 450 + this->incY3, 65, 400);
		return false;
	}
}

/* int Background::getPipe1Y()
{
	return 100 + this->incY1;
}

int Background::getPipe1X()
{
	return pipeDistance1;
}

int Background::getPipe2Y()
{
	return 100 + this->incY2;
}

int Background::getPipe2X()
{
	return pipeDistance2;
}

int Background::getPipe3Y()
{
	return 100 + this->incY3;
}

int Background::getPipe3X()
{
	return pipeDistance3;
}
*/
void Background::Reset()
{
	pipeDistance1 = 300;
	pipeDistance2 = 550;
	pipeDistance3 = 800;
	incY1 = 0;
	incY2 = 0;
	incY3 = 0;
}

