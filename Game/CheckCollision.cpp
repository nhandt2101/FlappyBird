#include "CheckCollision.h"
bool CheckCollision::Check_Collision(SDL_Rect* a, SDL_Rect *b)
{
    SDL_bool Colliosion = SDL_HasIntersection(a, b);
    if(Colliosion)
    {
        return true;
    }
    return false;
}