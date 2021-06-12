#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
struct Player
{
    int grid[10][10];
    char display[10][10];
    char Mask[10][10];
} Player1,Player2;

char key;
const char row[10]= {'A','B','C','D','E','F','G','H','I','J'};
const char column[10]= {'0','1','2','3','4','5','6','7','8','9'};
const char direction[4]= {'U','R','D','L'};
char display[10][10];
int grid[10][10];
char position[2]= {'\0'};
int RowNum;
int ColNum;
int Direction;

/****************************************************************************/

void Print_Missouri()
{
    printf("\n");
    printf("           __  __  _                                _ \n");
    printf("          |  \\/  |(_)                              (_)\n");
    printf("          | \\  / | _  ___  ___   ___   _   _  _ __  _ \n");
    printf("          | |\\/| || |/ __|/ __| / _ \\ | | | || '__|| |\n");
    printf("          | |  | || |\\__ \\\\__ \\| (_) || |_| || |   | |\n");
    printf("          |_|  |_||_||___/|___/ \\___/  \\__,_||_|   |_|\n");
    printf("                                                 \n");
}
/****************************************************************************/

void Print_Grid()
{
    printf("                 0  1  2  3  4  5  6  7  8  9\n");

    for(int i=0; i<10; i++)         //print out default map
    {
        printf("              %c  ",row[i]);      //print rows
        for(int j=0; j<10; j++)
            printf("%          c  ",display[i][j]);  //print columns
        printf("\n");
    }
}
/****************************************************************************/

void start()
{
    Print_Missouri();
    printf("          Press [Space] to start the game");
    char key = getch();
    while(key!='\t'&& key!=' ')
        key = getch();

    for(int i=0; i<10; i++)
    {
        printf("\r");
        printf("          Game Loading: %d percent        ", i*10);
        Sleep(300);
    }
    system("cls");
}
/****************************************************************************/

void Check_key()
{
    key = getch();
    while(key!='\t'&& key!=' ')
        key = getch();
}
/****************************************************************************/

void Choose_Coordinate()
{
    int i=0;     //initialize i
    do        //choose row
    {
        printf("\r");
        printf("              Row: %c                            ",row[i]);
        key = getch();
        while(key!=' '&&key!='\t')
            key=getch();
        if(key==' ')
            position[0]=row[i];
        if(key=='\t' && i<9)
            i++;
        else
            i=0;
    }
    while(key !=' ');
    i=0;     //initialize i
    do       //choose column
    {
        printf("\r");
        printf("              Row: %c      Column: %c                                       ",position[0],column[i]);
        key = getch();
        while(key!=' '&&key!='\t')
            key=getch();
        if(key==' ')
            position[1]=column[i];
        else if(key=='\t' && i<9)
            i++;
        else
            i=0;
    }
    while(key!=' ');
}
/****************************************************************************/

int Choose_Direction()
{
    int i=0;
    do
    {
        printf("\r");
        printf("              (U)p,(D)own,(L)eft,(R)ight || Direction: %c               ",direction[i]);
        key = getch();
        while(key!=' '&&key!='\t')
            key=getch();
        if(key==' ')
            return i;
        else if(key=='\t'&&i<3)
            i++;
        else
            i=0;
    }
    while(key!=' ');
}
/****************************************************************************/

//void update_grid(int Direction, int i, int *grid, char *display, int RowNum, int ColNum)
//{
//    switch(Direction)
//    {
//    case 0:
//        grid[RowNum-i][ColNum]=1;
//        display[RowNum-i][ColNum]='O';
//    case 1:
//        grid[RowNum][ColNum+i]=1;
//        display[RowNum][ColNum+i]='O';
//    case 2:
//        grid[RowNum+i][ColNum]=1;
//        display[RowNum+i][ColNum]='O';
//    case 3:
//        grid[RowNum][ColNum-i];
//        display[RowNum][ColNum-i]='O';
//    }
//}

/****************************************************************************/

void Msg1()                 //HERE HAS BEEN OCCUPIED
{
    printf("\r");
    printf("              <HERE HAS BEEN OCCUPIED>"                      );
    Sleep(1000);
}

void Msg2()                 //There is no enough space
{
    printf("\r");
    printf("              <There is no enough space>                      ");
    Sleep(1000);
}
/****************************************************************************/

int mode_selection()
{
    Print_Missouri();
    printf("          Please choose game mode using [TAB] and press [SPACE] to continue\n");
    printf("\n");
    printf("          [Single Player]     PvP                  ");

    int flag=0;

    while(1)
    {
        Check_key();
        if(key ==' ')
            break;
        else if(key == '\t' && flag == 0)
        {
            printf("\r");
            printf("           Single Player     [PvP]        ");
            flag = 1;
        }
        else if(key == '\t' && flag == 1)
        {
            printf("\r");
            printf("          [Single Player]     PvP             ");
            flag = 0;
        }
    };
    system("cls");
    return flag;
}
/****************************************************************************/

int choose_difficulty_level()
{
    Print_Missouri();
    printf("          Please choose difficulty level using [TAB] and press [SPACE] to continue\n");
    printf("\n");
    printf("          [Easy]     Hard                  ");

    int flag=0;

    while(1)
    {
        Check_key();
        if(key ==' ')
            break;
        else if(key == '\t' && flag == 0)
        {
            printf("\r");
            printf("           Easy     [Hard]                  ");
            flag = 1;
        }
        else if(key == '\t' && flag == 1)
        {
            printf("\r");
            printf("          [Easy]     Hard                  ");
            flag = 0;
        }
    };
    system("cls");
    return flag;
}
/****************************************************************************/

int deployment(int PlayerNum)
{
    int ship = 1;
    int flag = 0;
    int RowNum = 0;
    int ColNum = 0;
    int temp=0;
    int Direction;
    char key;

    /****************************** initialize grid *********************************/
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            display[i][j]='-';
            grid[i][j]=0;
        }
    }

    /****************************  Carrier deployment  ***************************/

    Print_Missouri();
    Print_Grid();
    printf("\n");
    printf("              OOOOO Carrier Missouri\n");
    printf("              [TAB] : cycle through options\n");
    printf("              [Space] : confirm\n");

    do
    {
        temp=0;     //reset temp
        Choose_Coordinate();
        RowNum = position[0]-65;
        ColNum = position[1]-48;
        if(grid[RowNum][ColNum]!=0)
            Msg1();        //Here has been occupied
        else
        {
            Direction = Choose_Direction();
            switch(Direction)
            {
            case 0:
                if(RowNum<4)
                    Msg2();         //There is no enough space
                else
                {
                    for(int i=0; i<5; i++)
                        temp=temp+grid[RowNum-i][ColNum];
                    if(temp!=0)
                        Msg2();         //There is no enough space
                    else
                    {
                        for(int i=0; i<5; i++)
                        {
                            grid[RowNum-i][ColNum]=1;
                            display[RowNum-i][ColNum]='O';
                        }
                        flag=1;
                    }
                }
                break;

            case 1:
                if(ColNum>5)
                    Msg2();         //There is no enough space
                else
                {
                    for(int i=0; i<5; i++)
                        temp=temp+grid[RowNum][ColNum+i];

                    if(temp!=0)
                        Msg2();         //There is no enough space
                    else
                    {
                        for(int i=0; i<5; i++)
                        {
                            grid[RowNum][ColNum+i]=1;
                            display[RowNum][ColNum+i]='O';
                        }
                        flag=1;
                    }
                }
                break;

            case 2:
                if(RowNum>5)
                    Msg2();         //There is no enough space
                else
                {
                    for(int i=0; i<9-RowNum+1; i++)
                        temp=temp+grid[RowNum+i][ColNum];
                    if(temp!=0)
                        Msg2();         //There is no enough space
                    else
                    {
                        for(int i=0; i<5; i++)
                        {
                            grid[RowNum+i][ColNum]=1;
                            display[RowNum+i][ColNum]='O';
                        }
                        flag=1;
                    }
                }
                break;

            case 3:
                if(ColNum<4)
                    Msg2();         //There is no enough space
                else
                {
                    for(int i=0; i<ColNum+1; i++)
                        temp=temp+grid[RowNum][ColNum-i];
                    if(temp!=0)
                        Msg2();         //There is no enough space
                    else
                    {
                        for(int i=0; i<5; i++)
                        {
                            grid[RowNum][ColNum-i];
                            display[RowNum][ColNum-i]='O';
                        }
                        flag=1;
                    }
                }
            }
        }
    }
    while(flag == 0);
    system("cls");

    /***************************  Battleship deployment  ***********************************/

    for(int i=0; i<2; i++)
    {
        Print_Missouri();
        Print_Grid();
        printf("\n");
        printf("              OOOO Battleship\n");
        printf("              [TAB] : cycle through options\n");
        printf("              [Space] : confirm\n");
        flag = 0;   //reset flag
        do
        {
            temp=0;     //reset temp
            Choose_Coordinate();
            RowNum = position[0]-65;
            ColNum = position[1]-48;
            if(grid[RowNum][ColNum]!=0)
            {
                Msg1();    //Here has been occupied
                printf("%d %d",RowNum,ColNum);
                Sleep(3000);
            }

            else
            {
                Direction = Choose_Direction();
                switch(Direction)
                {
                case 0:
                    if(RowNum<3)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<4; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<4; i++)
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 1:
                    if(ColNum>6)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<4; i++)
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<4; i++)
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                            }
                            flag=1;
                        }

                    }
                    break;

                case 2:
                    if(RowNum>6)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<4; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<4; i++)
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 3:
                    if(ColNum<3)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<4; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<4; i++)                      //changed
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                            }
                            flag=1;
                        }
                    }
                }
            }
        }
        while(flag == 0);
        system("cls");
    }

    /****************************  Cruiser deployment ***************************************/

    for(int i=0; i<3; i++)
    {
        Print_Missouri();
        Print_Grid();
        printf("\n");
        printf("              OOO Cruiser\n");
        printf("              [TAB] : cycle through options\n");
        printf("              [Space] : confirm\n");
        int i=0;
        int flag = 0;   //reset flag
        do
        {
            temp=0;     //reset temp
            Choose_Coordinate();
            RowNum = position[0]-65;
            ColNum = position[1]-48;
            if(grid[RowNum][ColNum]!=0)
                Msg1();    //Here has been occupied
            else
            {
                Direction = Choose_Direction();
                switch(Direction)
                {
                case 0:
                    if(RowNum<2)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<3; i++)
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 1:
                    if(ColNum>7)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<3; i++)
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<3; i++)
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                            }
                            flag=1;
                        }

                    }
                    break;

                case 2:
                    if(RowNum>7)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<3; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<3; i++)
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 3:
                    if(ColNum<2)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<3; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<3; i++)                      //changed
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                            }
                            flag=1;
                        }
                    }
                }
            }
        }
        while(flag == 0);
        system("cls");
    }

    /****************************  Destroyer deployment *******************************************/

    for(int i=0; i<4; i++)
    {
        Print_Missouri();
        Print_Grid();
        printf("\n");
        printf("              OO Destroyer\n");
        printf("              [TAB] : cycle through options\n");
        printf("              [Space] : confirm\n");

        flag = 0;   //reset flag
        do
        {
            temp=0;     //reset temp
            Choose_Coordinate();
            RowNum = position[0]-65;
            ColNum = position[1]-48;
            if(grid[RowNum][ColNum]!=0)
                Msg1();    //Here has been occupied
            else
            {
                Direction = Choose_Direction();
                switch(Direction)
                {
                case 0:
                    if(RowNum<1)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<2; i++)
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 1:
                    if(ColNum>8)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<2; i++)
                            temp=temp+grid[RowNum][ColNum+i];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<2; i++)
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 2:
                    if(RowNum>8)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<2; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<2; i++)
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                            }
                            flag=1;
                        }
                    }
                    break;

                case 3:
                    if(ColNum<1)
                        Msg2();     //There is no enough space
                    else
                    {
                        for(int i=0; i<2; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                            Msg2();     //There is no enough space
                        else
                        {
                            for(int i=0; i<2; i++)
                            {
                                grid[RowNum][ColNum-i]=1;
                                display[RowNum][ColNum-i]='O';
                            }
                            flag=1;
                        }
                    }
                }
            }
        }
        while(flag == 0);
        system("cls");
    }
    Print_Missouri();
    Print_Grid();

    /*******************************************************************************/

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(PlayerNum == 0)                          //set player 1's grid
            {
                Player1.grid[i][j] = grid[i][j];
                Player1.display[i][j] = display[i][j];
            }
            else                                        //set player 2's grid
            {
                Player2.grid[i][j] = grid[i][j];
                Player2.display[i][j] = display[i][j];
            }
        }
    }

    printf("\n");
    printf("              Your Fleet is now complete!");
    Sleep(2000);
    system("cls");
    return 0;
}

/*******************************************************************************/

int PvP_Battle()
{
    int Win = 0;
    int turn = 0;
    int P1 = 0;
    int P2 = 0;

    for(int i = 0; i<10; i++)           //initialize mask
    {
        for(int j=0; j<10; j++)
        {
            Player1.Mask[i][j]='-';
            Player2.Mask[i][j]='-';
        }
    }

    while(Win!=1)
    {
        Print_Missouri();
        if(turn==0)
        {
            printf("          [ Player 1 ]\n");
            printf("\n");
        }
        else
        {
            printf("          [ Player 2 ]\n");
            printf("\n");
        }

        printf("              0  1  2  3  4  5  6  7  8  9              0  1  2  3  4  5  6  7  8  9\n");
        for(int i=0; i<10; i++)
        {
            switch(turn)
            {
            case 0:
                printf("           %c  ",row[i]);       //print rows
                for(int j=0; j<10; j++)
                    printf("%c  ",Player1.display[i][j]);
                printf("         %c  ",row[i]);         //print rows (Mask)
                for(int j=0; j<10; j++)
                    printf("%c  ",Player2.Mask[i][j]);  //print mask for player
                break;

            case 1:
                printf("           %c  ",row[i]);       //print rows
                for(int j=0; j<10; j++)
                    printf("%c  ",Player2.display[i][j]);
                printf("         %c  ",row[i]);  //print rows (Mask)
                for(int j=0; j<10; j++)
                    printf("%c  ",Player1.Mask[i][j]);  //print mask for player
                break;
            }
            printf("\n");
        }

        switch(turn)
        {
        case 0:                         //Player 1 attack
            printf("\n");
            Choose_Coordinate();
            RowNum = position[0]-65;
            ColNum = position[1]-48;

            if(Player2.grid[RowNum][ColNum]==1)
            {
                Player2.grid[RowNum][ColNum]=0;
                Player2.Mask[RowNum][ColNum]='X';
                Player2.display[RowNum][ColNum]='X';
            }
            else
            {
                Player2.Mask[RowNum][ColNum]=' ';
                if(Player2.display[RowNum][ColNum]!='O')
                    Player2.display[RowNum][ColNum]=' ';
            }


            system("cls");                              //Update board
            Print_Missouri();
            printf("          [ Player 1 ]\n");
            printf("\n");
            printf("              0  1  2  3  4  5  6  7  8  9              0  1  2  3  4  5  6  7  8  9\n");
            for(int i=0; i<10; i++)
            {
                printf("           %c  ",row[i]);       //print rows
                for(int j=0; j<10; j++)
                    printf("%c  ",Player1.display[i][j]);
                printf("         %c  ",row[i]);         //print rows(Mask)
                for(int j=0; j<10; j++)
                    printf("%c  ",Player2.Mask[i][j]);  //print mask for player
                printf("\n");
            }
            turn = 1;
            Sleep(1500);
            system("cls");
            break;

        case 1:                     //Player 2 attack
            printf("\n");
            Choose_Coordinate();
            RowNum = position[0]-65;
            ColNum = position[1]-48;

            if(Player1.grid[RowNum][ColNum]==1)
            {
                Player1.grid[RowNum][ColNum]=0;
                Player1.Mask[RowNum][ColNum]='X';
                Player1.display[RowNum][ColNum]='X';
            }
            else
            {
                Player1.Mask[RowNum][ColNum]=' ';
                if(Player1.display[RowNum][ColNum]!='O')
                    Player1.display[RowNum][ColNum]=' ';
            }


            system("cls");                              //Update board
            Print_Missouri();
            printf("          [ Player 2 ]\n");
            printf("\n");

            printf("              0  1  2  3  4  5  6  7  8  9              0  1  2  3  4  5  6  7  8  9\n");
            for(int i=0; i<10; i++)
            {
                printf("           %c  ",row[i]);       //print rows
                for(int j=0; j<10; j++)
                    printf("%c  ",Player2.display[i][j]);
                printf("         %c  ",row[i]);         //print rows(Mask)
                for(int j=0; j<10; j++)
                    printf("%c  ",Player1.Mask[i][j]);  //print mask for player
                printf("\n");
            }
            turn = 0;
            Sleep(1500);
            system("cls");
            break;
        }

        for(int i=0; i<10; i++)         //check result
        {
            for(int j=0; j<10; j++)
            {
                P1 = P1 + Player1.grid[i][j];
                P2 = P2 + Player2.grid[i][j];
            }
        }
        if(P1==0 || P2 == 0)
            Win = 1;
    }
    system("cls");
    Print_Missouri();
    if(P1 == 0)
    {
        printf("              PLAYER 2 VICTORY !!!");
        Sleep(3000);
    }
    else
    {
        printf("              PLAYER 1 VICTORY !!!");
        Sleep(3000);
    }
}













































