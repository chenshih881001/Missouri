#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>



char Display_Original[10][10] =
{
    {'-','-','O','O','-','O','-','O','-','-'},
    {'-','-','-','-','-','O','-','O','-','O'},
    {'O','O','O','O','-','O','-','O','-','O'},
    {'-','-','-','-','-','O','-','-','-','-'},
    {'-','-','-','-','-','O','-','-','-','-'},
    {'-','-','-','O','-','-','-','O','O','O'},
    {'-','O','-','O','-','-','-','-','-','-'},
    {'-','O','-','O','-','-','-','-','-','-'},
    {'-','O','-','-','-','O','O','O','O','-'},
    {'-','-','O','O','-','-','O','O','-','-'},
};

char Display_test[10][10];


int step = 0;
int Grid_test[10][10];
int RowNum;
int ColNum;
int TempRowNum = 0;
int TempColNum = 0;
int turn = 0;
int flag = 0;
int temp;

int win = 0;

int action;

int direction;
int up = 0;
int right = 1;

int TempRowNum;
int TempColNum;


void print()
{
    printf("        ");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            printf("%c  ",Display_test[i][j]);
        printf("\n");
        printf("        ");
    }
    printf("\n");
    printf("\n");
    printf("        ");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            printf("%c  ",Display_Original[i][j]);
        printf("\n");
        printf("        ");
    }

//    printf("\n");
//    printf("\n");
//    printf("        ");
//    for(int i=0; i<10; i++)
//    {
//        for(int j=0; j<10; j++)
//            printf("%d  ",Grid_test[i][j]);
//        printf("\n");
//        printf("        ");
//    }
    Sleep(100);
}

int main()
{
    for(int i=0; i<10; i++)  //initialize grid
    {
        for(int j=0; j<10; j++)
        {
            Grid_test[i][j]=0;
            Display_test[i][j]=Display_Original[i][j];
        }

    }

    action = 0;
    while(win!=1)
    {
        switch(action)
        {
        case 0:
            if(turn == 0)
            {
                do
                {
                    srand(time(NULL));
                    TempRowNum = rand() % 9;       //generate a integer num (0~9)
                    TempColNum = rand() % 9;       //generate a integer num (0~9)
                }
                while(Grid_test[TempRowNum][TempColNum]!=0);
                RowNum = TempRowNum;
                ColNum = TempRowNum;
                turn = 1;
            }
            else
            {
                flag = 0;   //reset flag
                for(int i=0; i<10; i++)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(Grid_test[i][j]== 0 && flag == 0)
                        {
                            RowNum = i;
                            ColNum = j;
                            flag = 1;
                        }
                    }
                }
                turn = 0;
            }

            if(Display_Original[RowNum][ColNum]== 'O')    // if its a Hit
            {
                Grid_test[RowNum][ColNum]=1;
                Display_test[RowNum][ColNum]='X';
                action = 1;
            }
            else
            {
                Grid_test[RowNum][ColNum] = 2;
                if(Display_test[RowNum][ColNum]!='X')
                    Display_test[RowNum][ColNum] = ' ';
            }


            print();
            system("cls");
            break;

        case 1:
            TempRowNum = RowNum;
            TempColNum = ColNum;
            int hit = 0;


            //check vertically
            TempRowNum--;
            while(Display_Original[TempRowNum][ColNum]=='O' && TempRowNum>=0)        //check north
            {
                Grid_test[TempRowNum][ColNum]=1;      //edit
                if(ColNum-1>=0)                       //edit
                    Grid_test[TempRowNum][ColNum-1]=2;
                if(ColNum+1<=9)                       //edit
                    Grid_test[TempRowNum][ColNum+1]=2;

                Display_test[TempRowNum][ColNum]='X';
                TempRowNum--;
                print();
                system("cls");
                hit++;
            }
//            Display_test[TempRowNum][ColNum]=' ';
            if(TempRowNum>=0)                          //edit
            {
                Display_test[TempRowNum][ColNum]=' ';
                Grid_test[TempRowNum][ColNum] = 2;
            }
            print();
            system("cls");
            /**************************************************************************/

            TempRowNum = RowNum;
            TempRowNum++;
            while(Display_Original[TempRowNum][ColNum]=='O' && TempRowNum<=9)        //check south
            {
                Grid_test[TempRowNum][ColNum]=1;      //edit
                if(ColNum-1>=0)                       //edit
                    Grid_test[TempRowNum][ColNum-1]=2;
                if(ColNum+1<=9)                       //edit
                    Grid_test[TempRowNum][ColNum+1]=2;

                Display_test[TempRowNum][ColNum]='X';
                TempRowNum++;
                print();
                system("cls");
                hit++;
            }
//            Display_test[TempRowNum][ColNum]=' ';
            if(TempRowNum<=9)                          //edit
            {
                Display_test[TempRowNum][ColNum]=' ';
                Grid_test[TempRowNum][ColNum] = 2;
            }

            if(hit>0)
            {
                if(ColNum-1>=0)                       //edit
                    Grid_test[RowNum][ColNum-1]=2;
                if(ColNum+1<=9)                       //edit
                    Grid_test[RowNum][ColNum+1]=2;
            }
            print();
            system("cls");

            /**************************************************************************/

            if(hit == 0)       //check horizontally
            {
                TempColNum++;
                while(Display_Original[RowNum][TempColNum]=='O' && TempColNum<=9)
                {
                    Grid_test[RowNum][TempColNum]=1;          //edit
                    if(RowNum-1>=0)
                        Grid_test[RowNum-1][TempColNum] = 2;  //edit
                    if(RowNum+1<=9)
                        Grid_test[RowNum+1][TempColNum] = 2;  //edit

                    Display_test[RowNum][TempColNum]='X';
                    TempColNum++;
                    print();
                    system("cls");
                }
//                Display_test[RowNum][TempColNum]=' ';
                if(TempColNum<=9)                             //edit
                {
                    Display_test[RowNum][TempColNum]=' ';
                    Grid_test[RowNum][TempColNum]=2;
                }
                print();
                system("cls");

                /**************************************************************************/
                TempColNum = ColNum;
                TempColNum--;
                while(Display_Original[RowNum][TempColNum]=='O' && TempColNum>=0)
                {
                    Grid_test[RowNum][TempColNum]=1;            //edit
                    if(RowNum-1>=0)
                        Grid_test[RowNum-1][TempColNum] = 2;    //edit
                    if(RowNum+1<=9)
                        Grid_test[RowNum+1][TempColNum] = 2;    //edit

                    Display_test[RowNum][TempColNum]='X';
                    TempColNum--;
                    print();
                    system("cls");
                }
//                Display_test[RowNum][TempColNum]=' ';
                if(TempColNum>=0)                             //edit
                {
                    Display_test[RowNum][TempColNum]=' ';
                    Grid_test[RowNum][TempColNum]=2;
                }

                if(RowNum-1>=0)                       //edit
                    Grid_test[RowNum-1][ColNum]=2;
                if(RowNum+1<=9)                       //edit
                    Grid_test[RowNum+1][ColNum]=2;

                print();
                system("cls");
            }
            action = 0;
            break;
        }

        temp=0;                         //check win
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(Grid_test[i][j]==1)
                    temp++;
            }
        }
        if(temp==30)
            win = 1;
    }
    return 0;
}
