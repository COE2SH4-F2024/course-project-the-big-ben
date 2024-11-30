#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    //playerPos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    /*TESTING BLOCK*/
    playerPosList->insertTail(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    
}


Player::~Player()
{
    delete playerPosList;
    // delete any heap members here
}

objPosArrayList& Player::getPlayerPos() const
{
    return *playerPosList;  
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    
    switch(input)
    {
        case ' ':
            mainGameMechsRef->setExitTrue();
            break;
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
    //objPos playerHead = playerPosList->getHeadElement();
    int x = playerPosList->getHeadElement().pos->x;
    int y = playerPosList->getHeadElement().pos->y;
    
    // getPlayerPos().getHeadElement().pos->x;
    // int y = playerPosList->getPlayerPos().getHeadElement().pos->y;

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

    getPlayerPos().insertHead(objPos(x, y, '+'));
    getPlayerPos().removeTail();
    
    // PPA3 Finite State Machine logic
}

// More methods to be added