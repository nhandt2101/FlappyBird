#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Background.h"
#include "TextManager.h"

class MainMenu
{
private:
	bool isClicked;
	bool isSelected;
	
	Background menuBackground;
	Background start;
	TextManager press;
public:
	MainMenu();
	~MainMenu();
	
	int EventHandling(SDL_Event& e);
	
	void Initialize(SDL_Renderer* ren);
	void Render(SDL_Renderer* ren,SDL_Event& e);
	
	bool getClicked();
	bool checkSelected(int x, int y);
	
	SDL_Rect destButton;
};