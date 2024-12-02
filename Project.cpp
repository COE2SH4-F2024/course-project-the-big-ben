#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *game;
Player *player;
Food *food;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs(30, 15);
    player = new Player(game);
    food = new Food;
    //food->generateFood(player->getPlayerPos(), game);
    food->generateFood(player->getPlayerPos(), game);
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
        game->setInput(MacUILib_getChar());
   }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer(food);
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    int col = game->getBoardSizeX();
    int row = game->getBoardSizeY();


    //food->generateFood(player->getPlayerPos(), game); //for testing purposes
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if((i==0)||(i==row-1)||(j==0)||(j==col-1)){
                MacUILib_printf("#");
            }
            else{
                bool drawn = false;
                for(int k=0; k<player->getPlayerPos().getSize(); k++){
                    if((j==player->getPlayerPos().getElement(k).pos->x)&&(i==player->getPlayerPos().getElement(k).pos->y) && !drawn){
                        MacUILib_printf("%c", player->getPlayerPos().getElement(k).symbol);
                        drawn = true;
                    }
                }
                if(!drawn && (i==food->getFoodPos().pos->y)&&(j==food->getFoodPos().pos->x)){
                    MacUILib_printf("%c", food->getFoodPos().getSymbol());
                }
                else if(!drawn){
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("============================================================\n");
    MacUILib_printf("FOR DEBUGGING PURPOSES\n");
    int xPrint = player->getPlayerPos().getHeadElement().getPos().x;
    int yPrint = player->getPlayerPos().getHeadElement().getPos().y;
    MacUILib_printf("player head position: (%d, %d)\n", xPrint, yPrint);
    MacUILib_printf("Food position: (%d, %d)\n", food->getFoodPos().pos->x, food->getFoodPos().pos->y);
    MacUILib_printf("List Size: %d\n", player->getPlayerPos().getSize());
   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}
 

void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete game;
    delete player;
    delete food;

    MacUILib_uninit();
}
