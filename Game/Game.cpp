#include "Game.h"
#include "Bird.h"
#include "Background.h"
#include "Base.h"
#include "MainMenu.h"
#include <fstream>
#include "CheckCollision.h"
#include "TextManager.h"
#include "GameOver.h"

Bird b;
Background bg;
Base base1, base2;
MainMenu menu;

Background Pipe_Above1;
Background Pipe_Below1;
Background Pipe_Above2;
Background Pipe_Below2;
Background Pipe_Above3;
Background Pipe_Below3;
Background ScoreTable;

TextManager buttonReplay;
TextManager buttonExit;
TextManager score;
TextManager highScore;
TextManager scoreWhenDie;

GameOver gover;

const SDL_Color WHITECOLOR = {255, 255, 255, 255};
const SDL_Color BLACKCOLOR = {0, 0 ,0 , 0};
const SDL_Color REDCOLOR = {255, 0, 0, 255};


Game::Game()
{
	window = NULL;
	renderer = NULL;
	isRunning = false;
	birdDie = false;

	b.setSrc(0, 0, 34, 24);
	b.setDest(110, 200, 35, 30);
	bg.setSrc(0, 0, 540, 720);
	bg.setDest(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	base1.setSrc(0, 0, 540, 120);
	base2.setSrc(0, 0, 540, 120);

	Pipe_Above1.setSrc(0, 0, 25, 100);
	Pipe_Below1.setSrc(0, 0, 25, 100);
	Pipe_Above1.setSrc(0, 0, 25, 100);
	Pipe_Below1.setSrc(0, 0, 25, 100);
	Pipe_Above2.setSrc(0, 0, 25, 100);
	Pipe_Below2.setSrc(0, 0, 25, 100);
	Pipe_Above3.setSrc(0, 0, 25, 100);
	Pipe_Below3.setSrc(0, 0, 25, 100);
	Pipe_Above1.setDest(300, -50, 80, 400);
	Pipe_Below1.setDest(300, 410, 80, 400);
	Pipe_Above2.setDest(550, -50, 80, 400);
	Pipe_Below2.setDest(550, 410, 80, 400);
	Pipe_Above3.setDest(800, -50, 80, 400);
	Pipe_Below3.setDest(800, 410, 80, 400);

	ScoreTable.setSrc(0, 0, 444, 282);
	ScoreTable.setDest(150, 250, 300, 300);
}

bool Game::running()
{
    return isRunning;
}

void Game::MainMenu()
{
	menu.Initialize(renderer);
	while (!menu.getClicked())
	{
		SDL_RenderClear(renderer);
		menu.Render(renderer, event);
	}
	SDL_Delay(100);
	menu.clear();
}

void Game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		std::cout<<"Sound could not initialize! Mix_Error: " << Mix_GetError() << std::endl;
	}
	else
	{
		std::cout<<"Sound has been created!..."<<std::endl;
		dieSound = Mix_LoadMUS("Audio/die.wav");
		if(dieSound == NULL) std::cout<<1<<std::endl;
		
		hitSound = Mix_LoadWAV("Audio/hit.wav");
		if(hitSound == NULL) std::cout<<2<<std::endl;
		
		pointSound = Mix_LoadWAV("Audio/point.wav");
		if(pointSound == NULL) std::cout<<3<<std::endl;
		
		wingSound = Mix_LoadWAV("Audio/wing.wav");
		if(wingSound == NULL) std::cout<<5<<std::endl;

		replaySound = Mix_LoadWAV("Audio/replaySound.wav");
		if(replaySound == NULL) std::cout<<6<<std::endl;

		exitSound = Mix_LoadWAV("Audio/exitSound.wav");
		if(exitSound == NULL) std::cout<<7<<std::endl;
	}   
	window = SDL_CreateWindow("Flappy Bird", 
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if(window)
	{
        std::cout<<"Window has been created !..."<<std::endl;
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        if(renderer)
		{
            std::cout<<"Renderer has been created !..."<<std::endl;
            isRunning = true;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            b.createTexture("Image/redbird-midflap.png", renderer);
			b.CreateTexture1("Image/redbird-downflap.png", renderer);
			b.CreateTexture2("Image/redbird-upflap.png", renderer);
                
            bg.createTexture("Image/bgDay.png", renderer);
			ScoreTable.createTexture("Image/Score.png",renderer);
            
            base1.createTexture("Image/baseLong.png",renderer);
            base2.createTexture("Image/baseLong.png",renderer);
                
            Pipe_Below1.createTexture("Image/pipeBottom.png",renderer);
            Pipe_Above1.createTexture("Image/pipeTop.png",renderer);
			Pipe_Below2.createTexture("Image/pipeBottom.png",renderer);
			Pipe_Above2.createTexture("Image/pipeTop.png",renderer);
			Pipe_Below3.createTexture("Image/pipeBottom.png",renderer);
			Pipe_Above3.createTexture("Image/pipeTop.png",renderer);

			score.createFont("TTFfile/04B_19__.TTF", 38);
			gover.createTexture("Image/gameover.png", renderer);
			buttonReplay.createFont("TTFfile/04B_19__.TTF", 40);
			buttonExit.createFont("TTFfile/04B_19__.TTF", 40);
			highScore.createFont("TTFfile/04B_19__.TTF", 40);
			scoreWhenDie.createFont("TTFfile/04B_19__.TTF", 50);
		}
        else
		{
            std::cout<<"Failed to create Renderer !..."<<std::endl;
        }
    }
    else
	{
        std::cout<<"Failed to create Window !..."<<std::endl;
    }
}

void Game::handleEvent()
{
   	b.GetJumpTime();
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		isRunning = false;
	}
	else if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_SPACE)
		{
			if(!b.JumpState())
			{
				b.Jump();
				Mix_PlayChannel(-1, wingSound, 0);
			}
			else
			{
				b.Gravity();
			}
		}
	}
	else
	{
		b.Gravity();
	}
	if(birdDie)
	{
    	if(event.type == SDL_MOUSEBUTTONDOWN
			&& event.motion.x > 250 
			&& event.motion.x < 380 
			&& event.motion.y > 600 
			&& event.motion.y < 640)
		{
			Mix_PlayChannel(-1, replaySound, 0);
			SDL_Delay(100);
			Reset();
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN 
				&& event.motion.x > 250 
				&& event.motion.x < 320 
				&& event.motion.y > 650 
				&& event.motion.y < 690)
		{
			Mix_PlayChannel(-1, exitSound, 0);
			SDL_Delay(100);
			isRunning = false;
			clear();
		}
	}
}

void Game::update()
{
	std::string s;
	s = "Score: " + std::to_string(yourScore);
	score.Text(s, WHITECOLOR, renderer);
	buttonReplay.Text(REPLAY, WHITECOLOR, renderer);
	buttonExit.Text(EXIT, WHITECOLOR, renderer);
    base1.baseUpdate1();
    base2.baseUpdate2();
    bool flag1 = false, flag2 = false;
	flag1 = Pipe_Above1.Pipe_Above1Update(variance1, yourScore, birdDie);
	flag2 = Pipe_Below1.Pipe_Below1Update(variance1);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance1 = rand() % 201 - 100;
		Pipe_Above1.Pipe_Above1Update(variance1, yourScore, birdDie);
		Pipe_Below1.Pipe_Below1Update(variance1);
		if(!birdDie)
		{
		Mix_PlayChannel(-1, pointSound, 0);
		}
	}
	flag1 = Pipe_Above2.Pipe_Above2Update(variance2, yourScore, birdDie);
	flag2 = Pipe_Below2.Pipe_Below2Update(variance2);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance2 = rand() % 201 - 100;
		Pipe_Above2.Pipe_Above2Update(variance2, yourScore, birdDie);
		Pipe_Below2.Pipe_Below2Update(variance2);
		if(!birdDie)
		{
		Mix_PlayChannel(-1, pointSound, 0);
		}
	}
	flag1 = Pipe_Above3.Pipe_Above3Update(variance3, yourScore, birdDie);
	flag2 = Pipe_Below3.Pipe_Below3Update(variance3);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance3 = rand() % 201 - 100;
		Pipe_Above3.Pipe_Above3Update(variance3, yourScore, birdDie);
		Pipe_Below3.Pipe_Below3Update(variance3);
		if(!birdDie)
		{
			Mix_PlayChannel(-1, pointSound, 0);
		}
	}
	CollisionDetection();	
}

void Game::CollisionDetection()
{
  	if (CheckCollision::Check_Collision(&b.destRect, &Pipe_Above1.destRect) || CheckCollision::Check_Collision(&b.destRect, &Pipe_Below1.destRect) || 
		CheckCollision::Check_Collision(&b.destRect, &Pipe_Above2.destRect) || CheckCollision::Check_Collision(&b.destRect, &Pipe_Below2.destRect) || 
		CheckCollision::Check_Collision(&b.destRect, &Pipe_Above3.destRect) || CheckCollision::Check_Collision(&b.destRect, &Pipe_Below3.destRect))
	{
		birdDie = true;
		if(playSound)
		{
		Mix_PlayChannel(-1, hitSound, 0);
		SDL_Delay(500);
		Mix_PlayMusic(dieSound, 0);
		}
		playSound = false;
		
	}
	else if (CheckCollision::Check_Collision(&b.destRect, &base1.destRect) || CheckCollision::Check_Collision(&b.destRect, &base2.destRect) || b.getYpos() < 0)
	{
		birdDie = true;
		
		if(playSound)
		{
		Mix_PlayChannel(-1, hitSound, 0);
		Mix_PlayMusic(dieSound, 0);
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	bg.Render(renderer);
   	Pipe_Above1.Render(renderer);
	Pipe_Below1.Render(renderer);
	Pipe_Above2.Render(renderer);
	Pipe_Below2.Render(renderer);
	Pipe_Above3.Render(renderer);
	Pipe_Below3.Render(renderer);
	base1.Render(renderer);
	base2.Render(renderer);
	if(birdDie)
	{
		whenBirdDie();
		gover.Render(renderer);
		ScoreTable.Render(renderer);
		buttonReplay.Render(renderer, 250, 600);
		buttonExit.Render(renderer, 250,650);
		scoreWhenDie.Render(renderer, 230, 375);
		highScore.Render(renderer, 355, 340);
	}
	else
	{
		b.Render(renderer);
		score.Render(renderer, 0, 0);
	}
    	SDL_RenderPresent(renderer);
}

void Game::whenBirdDie()
{
		scoreWhenDie.Text(std::to_string(yourScore), BLACKCOLOR, renderer);
		std::ifstream inputFile("HighScore.txt");
		if(inputFile)
		{
			while(!inputFile.eof())
			{
				inputFile >> _highScore;
			}
		} 
		inputFile.close();
		std::ofstream writeFile("HighScore.txt");
		if(writeFile)
		{
			if(yourScore > _highScore)
			{
				_highScore = yourScore;
			}
			writeFile << _highScore;
		}
		writeFile.close();
		highScore.Text(std::to_string(_highScore), BLACKCOLOR, renderer);
}

void Game::Reset()
{
	variance1 = rand() % 201 - 100;
	variance2 = rand() % 201 - 100;
	variance3 = rand() % 201 - 100;
	b.Reset();
	yourScore = 0;
	Pipe_Above1.Reset();
	Pipe_Above2.Reset();
	Pipe_Above3.Reset();
	Pipe_Below1.Reset();
	Pipe_Below2.Reset();
	Pipe_Below3.Reset();
	birdDie = false;
	playSound = true;
}
void Game::clear()
{
	scoreWhenDie.closeFont();
	buttonExit.closeFont();
	buttonExit.closeFont();
	score.closeFont();
	highScore.closeFont();
	Mix_FreeChunk(pointSound);
	Mix_FreeChunk(wingSound);
	Mix_FreeMusic(dieSound);
	Mix_FreeChunk(hitSound);
	Mix_FreeChunk(replaySound);
	Mix_FreeChunk(exitSound);
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    IMG_Quit();
    SDL_Quit();
	std::cout<<"Game Cleaned!..."<<std::endl;
}