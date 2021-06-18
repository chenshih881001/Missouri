#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "library.h"


int Level;
int Mode;

int player_1 = 0;
int player_2 = 1;

int PvP = 0;
int Easy = 1;
int Hard = 2;


int main()
{
//  start();                    //press [Space] to start game; loading game
    Mode = mode_selection();
    switch(Mode)
    {
    case 0:                    //Single Player
        Level = choose_difficulty_level();
        switch(Level)
        {
        case 0:                //Easy
            generate_map();
            deployment(player_1,Easy);
            //deployment(player_1);
            Battle_easy();
            //Battle(Easy);
            break;

        case 1:                //Hard
            generate_difficult_map();
            deployment(player_1,Hard);
            Battle_hard();
            //Battle(Hard);
            break;
        }
        break;

    case 1:                    //PvP
//        for(int i=0; i<2; i++)
//            deployment(i);
        deployment(player_1,PvP);
        deployment(player_2,PvP);
        Battle();
        //Battle(PvP);
    }
    return 0;
}
























