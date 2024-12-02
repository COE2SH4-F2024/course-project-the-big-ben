#include "GameMechs.h"

GameMechs::GameMechs()    //Default Constructor with gameboard of 30 by 15
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)      //Constructor with board game size parameters
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}
 
GameMechs::~GameMechs() //GameMechs class has no heap members
{
    //No heap data members
}

//getter functions to return variables
bool GameMechs::getExitFlagStatus() const   
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

void GameMechs::incrementScore()    //increment score by 1
{
    score++;
}

//setters functions to set GameMech variables
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}
