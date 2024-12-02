#include "Player.h"


Player::Player(GameMechs* thisGMRef)    //constructor with GameMechs parameter
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    /*TESTING BLOCK
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-1, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-2, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-3, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-4, mainGameMechsRef->getBoardSizeY()/2, '+'));
    playerPosList->insertTail(objPos((mainGameMechsRef->getBoardSizeX()/3)-5, mainGameMechsRef->getBoardSizeY()/2, '+'));
    */
}

Player::~Player()   //destructor
{
    delete playerPosList;
    // delete any heap members here
}

objPosArrayList& Player::getPlayerPos() const   //copy assignment operator
{
    return *playerPosList;  
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()      //gets input and updates player direction
{
    char input = mainGameMechsRef->getInput();
    
    switch(input)
    {
        case ' ':   //exit if input is SPACE
            mainGameMechsRef->setExitTrue();
            break;
        case 'w':   //move up
            if(myDir != DOWN){
                myDir = UP;
            }
            break;
        case 'a':   //move left
            // if(myDir != RIGHT && myDir !=STOP){
            //     myDir = LEFT;
            // }
            if(myDir != RIGHT){
                myDir = LEFT;
            }
            break;
        case 's':   //move down
            if(myDir != UP){
                myDir = DOWN;
            }
            break;
        case 'd':   //move right
            if(myDir != LEFT){
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }  
    input = 0;   
}

void Player::movePlayer(Food* foodObj)  //function to move the player while checking for collision
{
    int x = playerPosList->getHeadElement().pos->x;
    int y = playerPosList->getHeadElement().pos->y;

    if(checkSelfCollision()){   //check collision with itself
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    } 
    else {    //moves player in player direction
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
           if (checkFoodConsumption(foodObj)){      //increases snake size and increments score if food consumed
                getPlayerPos().insertHead(objPos(x, y, '+'));
                foodObj->generateFood(this->getPlayerPos(), mainGameMechsRef);
                mainGameMechsRef->incrementScore();
            }else {     //moves the player by inserting head and deleting tail
                getPlayerPos().insertHead(objPos(x, y, '+'));
                getPlayerPos().removeTail();
            }
        }
    }
}


bool Player::checkFoodConsumption(Food* foodObj){   //function to check if player consumes/collides with food
    if(playerPosList->getHeadElement().pos->x == foodObj->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == foodObj->getFoodPos().pos->y){
        return true;
    }
    return false;
}

bool Player::checkSelfCollision(){      //function to check if snake collided with itself
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