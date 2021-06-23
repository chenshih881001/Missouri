#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "library.h"
#include <mmsystem.h>


int Level;
int Mode;

int player_1 = 0;
int player_2 = 1;

int Bot = 0;
int Human = 1;


int PvP = 0;
int Easy = 1;
int Hard = 2;


int main()
{
    //PlaySound(TEXT("test.wav"),NULL,SND_ASYNC);
    //start();                    //press [Space] to start game; loading game
    Mode = mode_selection();
    switch(Mode)
    {
    case 0:                    //Single Player
        Level = choose_difficulty_level();
        switch(Level)
        {
        case 0:                //Easy
            generate_map(Bot);

//            system("cls");
//            printf("          [ Player 2 ]\n");
//            printf("\n");
//            printf("              0  1  2  3  4  5  6  7  8  9\n");
//            for(int i=0; i<10; i++)
//            {
//                printf("           %c  ",row[i]);       //print rows
//                for(int j=0; j<10; j++)
//                    printf("%c  ",Player2.display[i][j]);
//                printf("\n");
//            }
//            Sleep(5000);
//            system("cls");

            //deployment(player_1,Easy);
            Battle(Easy);
            break;

        case 1:                //Hard
            generate_map(Human);
            generate_map(Bot);
            deployment(player_1,Hard);
            Battle(Hard);
            break;
        }
        break;

    case 1:                    //PvP
        deployment(player_1,PvP);
        deployment(player_2,PvP);
        Battle(PvP);
    }
    return 0;
}
























