#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    //playerPos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX()/3, mainGameMechsRef->getBoardSizeY()/2, '+'));
    /*TESTING BLOCK*/
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-1, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-3, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-4, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-5, mainGameMechsRef->getBoardSizeY()/2, '+'));
    
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
            if(myDir != RIGHT && myDir !=STOP){
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

void Player::movePlayer(Food* foodObj)
{
    //objPos playerHead = playerPosList->getHeadElement();
    int x = playerPosList->getHeadElement().pos->x;
    int y = playerPosList->getHeadElement().pos->y;
    
    // getPlayerPos().getHeadElement().pos->x;
    // int y = playerPosList->getPlayerPos().getHeadElement().pos->y;

    if(checkSelfCollision()){
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    } else {
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

        if(myDir != STOP){
           if (checkFoodConsumption(foodObj)){
                getPlayerPos().insertHead(objPos(x, y, '+'));
                foodObj->generateFood(this->getPlayerPos(), mainGameMechsRef);
                mainGameMechsRef->incrementScore();
            }else {
                getPlayerPos().insertHead(objPos(x, y, '+'));
                getPlayerPos().removeTail();
            }
        }
    }
    // PPA3 Finite State Machine logic
}


bool Player::checkFoodConsumption(Food* foodObj){
    if(playerPosList->getHeadElement().pos->x == foodObj->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == foodObj->getFoodPos().pos->y){
        return true;
    }
    return false;
}

bool Player::checkSelfCollision(){
    int playerSize = playerPosList->getSize();

    int headPosX = playerPosList->getHeadElement().pos->x;
    int headPosY = playerPosList->getHeadElement().pos->y;

    for (int i = 1; i < playerSize; i++)
    {
        if(headPosX == playerPosList->getElement(i).pos->x && headPosY == playerPosList->getElement(i).pos->y){
            return true;
        }
    }

    return false;
    
}
// More methods to be added