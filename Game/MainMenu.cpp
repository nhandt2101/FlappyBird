#include "MainMenu.h"

MainMenu::MainMenu()
{
	isClicked = false;
	isSelected = false;
	destButton.x = 215;
	destButton.y = 640;
	destButton.w = 165;
	destButton.h = 60;
}

void MainMenu::Initialize(SDL_Renderer* ren)
{
	menuBackground.createTexture("Image/MainMenu.png", ren);
	start.createTexture("Image/PressStart.PNG",ren);
}
bool MainMenu::checkSelected(int x, int y)
{
	if (x >= destButton.x 
	   && x <= destButton.x + destButton.w 
	   && y >= destButton.y 
	   && y <=destButton.y + destButton.h)
	{
		return true;
	}
	return false;
}

void MainMenu::Render(SDL_Renderer* ren, SDL_Event &e)
{
    menuBackground.setSrc(0, 0, 800, 640);
    menuBackground.setDest(0, 0, 600, 800);
	while(true)
	{
		
		menuBackground.Render(ren);
		start.Render(ren);
		
		SDL_RenderPresent(ren);
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				exit(0);
			}
			if(e.type == SDL_MOUSEMOTION)
			{
		if(checkSelected(e.motion.x, e.motion.y))
			{
				if(!isSelected)
				{
				isSelected = true;
				start.setSrc(0,0, 225, 66);
				start.setDest(215,630,170, 85);
				}
			}
		else
			{
			if(isSelected)
			{
			isSelected = false;
			start.setSrc(252,0, 225, 66);
			start.setDest(215,630,170, 85);
			}
		}
	}
			if (e.type == SDL_MOUSEBUTTONDOWN 
				&& e.motion.x > 215 
				&& e.motion.x < 380 
				&& e.motion.y > 640 
				&& e.motion.y < 700)
			{
			isClicked = true;
			}
		}
		if(isClicked == true)
		{
			break;
		}
	}
}

bool MainMenu::getClicked()
{
	return isClicked;
}

MainMenu::~MainMenu()
{
	isClicked = false;
	isSelected = false;
}