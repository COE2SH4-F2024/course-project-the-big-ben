#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+');
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    
    switch(input)
    {
        case 'w':
            if(myDir != DOWN){
                myDir = UP;
            }
            break;
        case 'a':
            if(myDir != RIGHT){
                myDir = LEFT;
            }
            break;
        case 's':
            if(myDir != UP){
                myDir = DOWN;
            }
            break;
        case 'd':
            if(myDir != LEFT){
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }
        // PPA3 input processing logic     
    input = 0;   
}

void Player::movePlayer()
{
    int x = getPlayerPos().pos->x;
    int y = getPlayerPos().pos->y;

    switch(myDir)
    {
        case STOP:
            break;
        case UP:
            y--;
            if(y == 0){
                y = mainGameMechsRef->getBoardSizeY()-2;
            } 
            break;
        case DOWN:
            y++;
            if(y == mainGameMechsRef->getBoardSizeY()-1){
                y = 1;
            }
            break;
        case LEFT:
            x--;
            if(x == 0){
                x = mainGameMechsRef->getBoardSizeX()-2;
            }
            break;
        case RIGHT:
            x++;
            if(x == mainGameMechsRef->getBoardSizeX()-1){
                x = 1;
            }
            break;
        default:
            break;
    }
    playerPos = objPos(x, y, '+');
    // PPA3 Finite State Machine logic
}

// More methods to be added