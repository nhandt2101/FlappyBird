#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Background.h"

class MainMenu
{
private:
	bool isClicked;
	bool isSelected;
	Mix_Chunk* startSound;	
	Background menuBackground;
	Background start;
	
public:
	MainMenu();
	~MainMenu();
	
	int EventHandling(SDL_Event& e);
	
	void Initialize(SDL_Renderer* ren);
	void Render(SDL_Renderer* ren,SDL_Event& e);
	
	bool getClicked();
	bool checkSelected(int x, int y);
	void clear();
	SDL_Rect destButton;
};