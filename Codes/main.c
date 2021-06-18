#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "library.h"

int Mode = 0;
int Level = 0;
int human = 0;

int main()
{
//    start();                        //press [Space] to start game; loading game
    Mode = mode_selection();
    switch(Mode)
    {
    case 0:                     //Single Player
        Level = choose_difficulty_level();
        switch(Level)
        {
        case 0:             //Easy
            generate_map();
            deployment(human);
            Battle_easy();

//            for(int i = 0; i<10; i++)
//            {
//                for(int j=0; j<10; j++)
//                    printf(" %c ",Player2.display[i][j]);
//                printf("\n");
//            }
//            printf("\n");
//            printf("\n");
//            for(int i = 0; i<10; i++)
//            {
//                for(int j=0; j<10; j++)
//                    printf(" %d ",Player2.grid[i][j]);
//                printf("\n");
//            }

            break;
        case 1:             //Hard
            //printf("2");
            //deployment_hard(Player1.grid);      //reefs in the map
            generate_difficult_map();
            for(int i = 0; i<10; i++)
            {
                for(int j=0; j<10; j++)
                    printf(" %c ",Player2.display[i][j]);
                printf("\n");
            }
            printf("\n");
            printf("\n");
            for(int i = 0; i<10; i++)
            {
                for(int j=0; j<10; j++)
                    printf(" %d ",Player2.grid[i][j]);
                printf("\n");
            }

            break;
        }
        break;

    case 1:                     //PvP
        for(int i=0; i<2; i++)
            deployment(i);
        PvP_Battle();
    }
    return 0;
}
























