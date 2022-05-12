#include "Bird.h"
#include <iostream>

int Bird::getYpos()
{
	return Ypos;
}

bool Bird::JumpState()
{
	return inJump;
}

void Bird::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 25)
	{
		SDL_RenderCopyEx(ren, getTexture(), &this -> srcRect, &this -> destRect, angle, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 25 && animationTimer <= 50)
	{
		SDL_RenderCopyEx(ren, Tex1, &this -> srcRect, &this -> destRect, angle, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 50)
	{
		SDL_RenderCopyEx(ren, Tex2, &this -> srcRect, &this -> destRect, angle, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 75)
	{
		animationTimer = 0;
	}
}

void Bird::Gravity()
{
	
	if (JumpState())
	{
		angle = 0;
		accelerator1 = accelerator1 + 0.03;
		accelerator2 = accelerator2 + 0.03;
		jumpHeight = jumpHeight + gravity;
		angle -= 20;
		
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(25, Ypos, 35, 30);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		
		}
	}
	else
	{
		angle += 1;
		accelerator1 = accelerator1 + 0.03;
		accelerator2 = accelerator2 + 0.03;
		Ypos = Ypos + gravity + accelerator1 + accelerator2;
		setDest(25, Ypos, 35, 30);
	}
		if (angle <= -45){
		angle = -45;
		}
		else if (angle >= 80){
		angle = 80;
	}
	
}

void Bird::Jump()
{
	if (jumpTimer - lastJump > 10)
	{
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void Bird::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

void Bird::Reset()
{
	accelerator1 = 0;
	accelerator2 = 0;
	Ypos = 256;
	lastJump = 0;
	angle = 0;
}

void Bird::CreateTexture1(const std::string path, SDL_Renderer* ren)
{
	Tex1 = TextureManager::loadTexture(path, ren);
}

void Bird::CreateTexture2(const std::string path, SDL_Renderer* ren)
{
	Tex2 = TextureManager::loadTexture(path, ren);
}  