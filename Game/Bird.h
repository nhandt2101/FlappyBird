#pragma once
#include "Object.h"

class Bird :public Object
{
private:
    
    int Ypos = 256;
    int animationTimer;
    double angle = 0;
    double accelerator1 = 0;
    double accelerator2 = 0;
    double gravity = 0.2;
    double jumpHeight = -6;
    double jumpTimer;
    double lastJump = 0;

    bool inJump = false;
    
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    
public:
    int getYpos();
    
    bool JumpState();
    
    void Gravity();
    void GetJumpTime();
    void Reset();
    void Jump();
    void CreateTexture1(const std::string path, SDL_Renderer* ren);
    void CreateTexture2(const std::string path, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
};