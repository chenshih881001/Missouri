#include <stdio.h>
#include <stdlib.h>

char grid[10][10]=
{
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-'}
};
char row[10]={'A','B','C','D','E','F','G','H','I','J'};
char column[10]={'1','2','3','4','5','6','7','8','9','x'};
char position1[2]={'\0'};
int ship = 1;
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


        printf("                 1  2  3  4  5  6  7  8  9  10\n");

        for(int i=0;i<10;i++)           //print out default map
        {
            printf("              %c  ",row[i]);      //print rows
            for(int j=0;j<10;j++)
                printf("%          c  ",grid[i][j]);  //print columns
            printf("\n");
        }

                printf("\n");
                printf("              OOOOO Battleship Missouri\n");
                printf("              Please select a block on the grid\n");

                int i=0;
                do              //choose row
                {
                    printf("              Row: %c",row[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        position1[0]=row[i];
                    if(key=='\t' && i<9)
                        i++;
                    else
                        i=0;
                    printf("\r");
                }while(key !=' ');
                printf("\n");

                i=0;     //initialize i

                do       //choose column
                {
                    printf("\r");
                    printf("              Column: %c",column[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        position1[1]=column[i];
                    else if(key=='\t' && i<9)
                        i++;
                    else
                        i=0;
                }while(key!=' ');



        /*

            case 2:
                printf("OOOO Cruiser Astoria\n");
            case 3:
                printf("OOOO Cruiser Portland\n");
            case 4:
                printf("OOO Destroyer Hammann\n");
            case 5:
                printf("OOO Destroyer Anderson\n");
            case 6:
                printf("OOO Destroyer Gwin\n");
            case 7:
                printf("OO Corvette Temptress\n");
            case 8:
                printf("OO Corvette Surprise\n");
            case 9:
                printf("OO Corvette Restless\n");
            case 10:
            printf("OO Corvette Fury\n");
        }
        */
    return 0;
}
