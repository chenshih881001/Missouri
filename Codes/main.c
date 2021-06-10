#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int Mode = 0;
int Level = 0;
struct Player
{
    int grid[10][10];
    char display[10][10];
}Player1,Player2;

int main()
{

    Enter_game();           //press [TAB] to start game; loading game
    Mode = mode_selection();
    switch(Mode)
    {
        case 1:             //PvP
            deployment(Player1.grid);
            deployment(Player2.grid);
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
}
