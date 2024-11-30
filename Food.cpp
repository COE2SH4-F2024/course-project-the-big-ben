#include <stdlib.h>
#include <time.h>
#include "Food.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

Food::Food()
{
    foodPos = objPos(0, 0, '0');
}

Food::~Food()
{
    //no heap members
}

void Food::generateFood(const objPosArrayList& blockOff, GameMechs* game)
{
    int xRand, yRand;
    bool randomNotFound = true;
    srand(time(NULL));

    while(randomNotFound){
        xRand = 1 + rand() % (game->getBoardSizeX()-2);
        yRand = 1 + rand() % (game->getBoardSizeY()-2);
        randomNotFound = false;
        for(int i=0; i<blockOff.getSize(); i++){
            if(xRand == blockOff.getElement(i).pos->x && yRand == blockOff.getElement(i).pos->y){
                randomNotFound = true;
                break;
            }
        }
        
    }
    setFoodPos(xRand, yRand);
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

void Food::setFoodPos(int xValue, int yValue)
{
    foodPos.pos->x = xValue;
    foodPos.pos->y = yValue;
}
