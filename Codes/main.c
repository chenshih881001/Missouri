#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "library.h"

int Mode = 0;
int Level = 0;

int main()
{
    start();           //press [Space] to start game; loading game
    Mode = mode_selection();
    switch(Mode)
    {
        case 1:             //PvP
            for(int i=0;i<2;i++)
                deployment(i);
            break;
        case 2:             //Single Player
            Level = choose_difficulty_level();
            switch(Level)
            {
                case 1:     //Easy
                    deployment(Player1.grid);
                    generate_map(Player2.grid);
                    break;
                case 2:     //Hard
                    deployment_hard(Player1.grid);      //reefs in the map
                    generate_map(Player2.grid);
            }
    }

//    for(int i=0; i<2; i++)
//        deployment(i);

//    for(int i=0; i<10; i++)
//    {
//        for(int j=0; j<10; j++)
//            printf("%c",Player1.display[i][j]);
//        printf("\n");
//    }
//
//    for(int i=0; i<10; i++)
//    {
//        for(int j=0; j<10; j++)
//            printf("%c",Player2.display[i][j]);
//        printf("\n");
//    }
}
