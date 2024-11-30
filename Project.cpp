#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *game;
Player *player;


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
    player->movePlayer();
    if(game->getInput() != 0)
    {
        switch(game->getInput())
        {
             case ' ':  // exit
                game->setExitTrue();
                break;
            
        }
        game->setInput(0);
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    int col = game->getBoardSizeX();
    int row = game->getBoardSizeY();
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if((i==0)||(i==row-1)||(j==0)||(j==col-1)){
                MacUILib_printf("#");
            }
            else if((j==player->getPlayerPos().pos->x)&&(i==player->getPlayerPos().pos->y)){
                MacUILib_printf("%c", player->getPlayerPos().symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("============================================================\n");
    MacUILib_printf("FOR DEBUGGING PURPOSES\n");
    MacUILib_printf("player head position: (%d, %d)\n", player->getPlayerPos().pos->x, player->getPlayerPos().pos->y);
   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete game;

    MacUILib_uninit();
}
