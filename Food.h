#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"


class Food
{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();

        void generateFood(const objPosArrayList& blockOff, GameMechs* game);
        objPos getFoodPos() const;
        void setFoodPos(int x, int y);
};

#endif