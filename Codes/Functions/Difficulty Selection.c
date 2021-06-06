 /******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define Easy 1
#define Hard 2

int difficulty = 0;
int flag = 0;
char key;
int main()
{
    printf("\n");
            printf("           __  __  _                                _ \n");
            printf("          |  \\/  |(_)                              (_)\n");
            printf("          | \\  / | _  ___  ___   ___   _   _  _ __  _ \n");
            printf("          | |\\/| || |/ __|/ __| / _ \\ | | | || '__|| |\n");
            printf("          | |  | || |\\__ \\\\__ \\| (_) || |_| || |   | |\n");
            printf("          |_|  |_||_||___/|___/ \\___/  \\__,_||_|   |_|\n");
            printf("                                                 \n");
            printf("                                                 \n");
            printf("\n");
    printf ("          Pease choose difficulty using [TAB] and press [SPACE] to continue\n");
    printf("\n");
    printf ("          [Easy]     Hard");


    key = getch();
    while(key!='\t'&& key!=' ')
        key = getch();


    if(key==' ')
        flag = 1;

    while(flag!=1)
    {
        if(key =='\t')
        {
            printf("\r");
            printf ("           Easy     [Hard]           ");
        }

        key = getch();
        while(key!='\t'&& key!=' ')
            key = getch();

        if(key == ' ')
        {
            difficulty = Hard;
            break;
        }
        else if(key == '\t')
        {
            printf("\r");
            printf ("          [Easy]     Hard          ");
        }

        key = getch();
        while(key!='\t'&& key!=' ')
            key = getch();

        if(key == ' ')
        {
            difficulty = Easy;
            break;
        }
    }

    printf("\n");
    printf("\n");
    if(flag == 1)
        printf("          Difficulty: Easy                  ");

    if(difficulty == Easy)
        printf("          Difficulty: Easy                  ");
    else if(difficulty == Hard)
        printf("          Difficulty: Hard                        ");
}


