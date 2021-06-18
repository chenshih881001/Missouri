#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "library.h"


int Level = 0;
int human = 0;

int main()
{
//  start();                    //press [Space] to start game; loading game
    int Mode = mode_selection();
    switch(Mode)
    {
    case 0:                    //Single Player
        Level = choose_difficulty_level();
        switch(Level)
        {
        case 0:                //Easy
            generate_map();
            deployment(human);
            Battle_easy();
            break;

        case 1:                //Hard
            generate_difficult_map();
            deployment_hard(human);
            Battle_hard();
            break;
        }
        break;

    case 1:                    //PvP
        for(int i=0; i<2; i++)
            deployment(i);
        Battle();
    }
    return 0;
}
























