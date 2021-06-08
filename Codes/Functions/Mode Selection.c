 /******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SinglePlayer 1
#define PvP 2

int mode = 0;
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
    printf ("          Please choose game mode using [TAB] and press [SPACE] to continue\n");
    printf("\n");
    printf ("          [Single Player]     PvP");


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
            printf ("           Single Player     [PvP]           ");
        }

        key = getch();
        while(key!='\t'&& key!=' ')
            key = getch();

        if(key == ' ')
        {
            mode = PvP;
            break;
        }
        else if(key == '\t')
        {
            printf("\r");
            printf ("          [Single Player]     PvP          ");
        }

        key = getch();
        while(key!='\t'&& key!=' ')
            key = getch();

        if(key == ' ')
        {
            mode = SinglePlayer;
            break;
        }
    }

    printf("\n");
    printf("\n");
    if(flag == 1)
        printf("          Mode: Single Player                  ");

    if(mode == SinglePlayer)
        printf("          Mode: Single Player                  ");
    else if(mode == PvP)
        printf("          Mode: PvP                        ");
}


