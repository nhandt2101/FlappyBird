#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>


class Game
{
    public:
        Game();
        
        void MainMenu();
        bool running();
        void update();
        void Reset();
        void CollisionDetection();
        void init();
        void handleEvent();
        void whenBirdDie();
        void render();
        void clear();
        
    private:
        
        const int SCREEN_HEIGHT = 800;
        const int SCREEN_WIDTH = 600;
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        SDL_Texture* texture;

        Mix_Music* dieSound;
        Mix_Chunk* swooshSound;
        Mix_Chunk* pointSound;
        Mix_Chunk* wingSound;
        Mix_Chunk* hitSound;
        Mix_Chunk* replaySound;
        Mix_Chunk* exitSound;
        
        int variance1 = rand() % 201 - 100;
	    int variance2 = rand() % 201 - 100;
	    int variance3 = rand() % 201 - 100;
        int _highScore;
        int yourScore = 0;
        
        bool birdDie = false;
        bool isRunning;
        bool playSound = true;
        
        const std::string REPLAY = "REPLAY";
        const std::string EXIT = "EXIT";
};