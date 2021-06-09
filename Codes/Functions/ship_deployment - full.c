#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char display[10][10];
int grid[10][10];

char row[10]= {'A','B','C','D','E','F','G','H','I','J'};
char column[10]= {'0','1','2','3','4','5','6','7','8','9'};
char direction[4]= {'U','R','D','L'};
char position[2]= {'\0'};
int ship = 1;
int flag = 0;
int RowNum = 0;
int ColNum = 0;
int temp=0;
int Direction;
char key;



void ship1_deploy()
{
    printf("                 0  1  2  3  4  5  6  7  8  9\n");
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            display[i][j]='-';
            grid[i][j]=0;
        }
    }

    for(int i=0; i<10; i++)         //print out default map
    {
        printf("              %c  ",row[i]);      //print rows
        for(int j=0; j<10; j++)
            printf("%          c  ",display[i][j]);  //print columns
        printf("\n");
    }


//SHIP 1: OOOO        
        printf("\n");
        printf("              OOOOO Battleship Missouri      Choose the starting point using [TAB] to cycle through values and [Space] to confirm\n");

        int i=0;
        do
        {
            i=0;     //initialize i
            do        //choose row
            {
                printf("\r");
                printf("              Row: %c                  ",row[i]);
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
                printf("              Row: %c      Column: %c",position[0],column[i]);
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

            RowNum = position[0]-65;
            ColNum = position[1]-48;
            //printf("     %d %d",RowNum,ColNum);


            int i=0;   //initialize i
            if(grid[RowNum][ColNum]!=0)
            {
                printf("\r");
                printf("              <HERE HAS BEEN OCCUPIED>"             );
                Sleep(1000);
            }
            else
            {
                do
                {
                    printf("\r");
                    printf("              U: Up, D: Down, L: Left, R: Right || Direction: %c               ",direction[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        Direction=i;
                    else if(key=='\t'&&i<3)
                        i++;
                    else
                        i=0;
                }
                while(key!=' ');

                switch(Direction)
                {
                case 0:
                    temp=0;     //reset temp

                    if(RowNum<4)
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<5; i++)
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                                flag=1;
                            }
//                      printf("\r");
//                      printf("              pass                                   ");
//                      Sleep(1000);
                        }
                    }
                    break;

                case 1:
                    temp=0;     //reset temp
                    if(ColNum>5)
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<5; i++)
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<5; i++)
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              Pass                           ");
//                        Sleep(1000);
                        }

                    }
                    break;

                case 2:
                    temp=0;     //reset temp

                    if(RowNum>5)
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<9-RowNum+1; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<5; i++)
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                    break;

                case 3:
                    temp=0;     //reset temp
                    if(ColNum<4)
                    {
                        printf("\r");
                        printf("              There is not enough space     ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<ColNum+1; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<5; i++)
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                }
            }
        }
        while(flag == 0);

        printf("\n");

        printf("                 0  1  2  3  4  5  6  7  8  9\n");
        for(int i=0; i<10; i++)         //print out default map
        {
            printf("              %c  ",row[i]);      //print rows
            for(int j=0; j<10; j++)
                printf("%          c  ",display[i][j]);  //print columns
            printf("\n");
        }
}

void ship2_deploy() // SHIP 2: OOOO 
{
        printf("\n");
        printf("              OOOO Cruiser Astoria      Choose the starting point using [TAB] to cycle through values and [Space] to confirm\n");

        int i=0;
        do
        {
            i=0;     //initialize i
            do        //choose row
            {
                printf("\r");
                printf("              Row: %c                  ",row[i]);
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
                printf("              Row: %c      Column: %c",position[0],column[i]);
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

            RowNum = position[0]-65;        //CHANGE HERE?
            ColNum = position[1]-48;        //CHANGE HERE?
            //printf("     %d %d",RowNum,ColNum);


            int i=0;   //initialize i
            if(grid[RowNum][ColNum]!=0)
            {
                printf("\r");
                printf("              <HERE HAS BEEN OCCUPIED>"             );
                Sleep(1000);
            }
            else
            {
                do
                {
                    printf("\r");
                    printf("              U: Up, D: Down, L: Left, R: Right || Direction: %c               ",direction[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        Direction=i;
                    else if(key=='\t'&&i<3)                                                     //CHANGE HERE?
                        i++;
                    else
                        i=0;
                }
                while(key!=' ');

                switch(Direction)
                {
                case 0:
                    temp=0;     //reset temp

                    if(RowNum<3)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<4; i++)                              //changed
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                                flag=1;
                            }
//                      printf("\r");
//                      printf("              pass                                   ");
//                      Sleep(1000);
                        }
                    }
                    break;

                case 1:
                    temp=0;     //reset temp
                    if(ColNum>4)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<4; i++)                          //changed
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<4; i++)                  //changed
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              Pass                           ");
//                        Sleep(1000);
                        }

                    }
                    break;

                case 2:
                    temp=0;     //reset temp

                    if(RowNum>4)                                //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<9-RowNum+1; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<4; i++)                  //changed
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                    break;

                case 3:
                    temp=0;     //reset temp
                    if(ColNum<3)                                    //changed
                    {
                        printf("\r");
                        printf("              There is not enough space     ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<ColNum+1; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<4; i++)                      //changed
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                }
            }
        }
        while(flag == 0);

        printf("\n");

        printf("                 0  1  2  3  4  5  6  7  8  9\n");
        for(int i=0; i<10; i++)         //print out default map
        {
            printf("              %c  ",row[i]);      //print rows
            for(int j=0; j<10; j++)
                printf("%          c  ",display[i][j]);  //print columns
            printf("\n");
        }
}
    
void ship4_deploy() // SHIP 4: OOO 
{
        printf("\n");
        printf("              OOO Destroyer Hammann      Choose the starting point using [TAB] to cycle through values and [Space] to confirm\n");

        int i=0;
        do
        {
            i=0;     //initialize i
            do        //choose row
            {
                printf("\r");
                printf("              Row: %c                  ",row[i]);
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
                printf("              Row: %c      Column: %c",position[0],column[i]);
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

            RowNum = position[0]-65;        //CHANGE HERE?
            ColNum = position[1]-48;        //CHANGE HERE?
            //printf("     %d %d",RowNum,ColNum);


            int i=0;   //initialize i
            if(grid[RowNum][ColNum]!=0)
            {
                printf("\r");
                printf("              <HERE HAS BEEN OCCUPIED>"             );
                Sleep(1000);
            }
            else
            {
                do
                {
                    printf("\r");
                    printf("              U: Up, D: Down, L: Left, R: Right || Direction: %c               ",direction[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        Direction=i;
                    else if(key=='\t'&&i<3)                                                     //CHANGE HERE?
                        i++;
                    else
                        i=0;
                }
                while(key!=' ');

                switch(Direction)
                {
                case 0:
                    temp=0;     //reset temp

                    if(RowNum<2)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<3; i++)                              //changed
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                                flag=1;
                            }
//                      printf("\r");
//                      printf("              pass                                   ");
//                      Sleep(1000);
                        }
                    }
                    break;

                case 1:
                    temp=0;     //reset temp
                    if(ColNum>3)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<3; i++)                          //changed
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<3; i++)                  //changed
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              Pass                           ");
//                        Sleep(1000);
                        }

                    }
                    break;

                case 2:
                    temp=0;     //reset temp

                    if(RowNum>3)                                          //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<9-RowNum+1; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<3; i++)                  //changed
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                    break;

                case 3:
                    temp=0;     //reset temp
                    if(ColNum<2)                                    //changed
                    {
                        printf("\r");
                        printf("              There is not enough space     ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<ColNum+1; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<3; i++)                      //changed
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                }
            }
        }
        while(flag == 0);

        printf("\n");

        printf("                 0  1  2  3  4  5  6  7  8  9\n");
        for(int i=0; i<10; i++)         //print out default map
        {
            printf("              %c  ",row[i]);      //print rows
            for(int j=0; j<10; j++)
                printf("%          c  ",display[i][j]);  //print columns
            printf("\n");
        }
}

void ship7_deploy() // SHIP 7: OO 
{
        printf("\n");
        printf("              OO Corvette Temptress      Choose the starting point using [TAB] to cycle through values and [Space] to confirm\n");

        int i=0;
        do
        {
            i=0;     //initialize i
            do        //choose row
            {
                printf("\r");
                printf("              Row: %c                  ",row[i]);
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
                printf("              Row: %c      Column: %c",position[0],column[i]);
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

            RowNum = position[0]-65;        //CHANGE HERE?
            ColNum = position[1]-48;        //CHANGE HERE?
            //printf("     %d %d",RowNum,ColNum);


            int i=0;   //initialize i
            if(grid[RowNum][ColNum]!=0)
            {
                printf("\r");
                printf("              <HERE HAS BEEN OCCUPIED>"             );
                Sleep(1000);
            }
            else
            {
                do
                {
                    printf("\r");
                    printf("              U: Up, D: Down, L: Left, R: Right || Direction: %c               ",direction[i]);
                    key = getch();
                    while(key!=' '&&key!='\t')
                        key=getch();
                    if(key==' ')
                        Direction=i;
                    else if(key=='\t'&&i<3)                                                     //CHANGE HERE?
                        i++;
                    else
                        i=0;
                }
                while(key!=' ');

                switch(Direction)
                {
                case 0:
                    temp=0;     //reset temp

                    if(RowNum<1)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<RowNum+1; i++)
                            temp=temp+grid[RowNum-i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<2; i++)                              //changed
                            {
                                grid[RowNum-i][ColNum]=1;
                                display[RowNum-i][ColNum]='O';
                                flag=1;
                            }
//                      printf("\r");
//                      printf("              pass                                   ");
//                      Sleep(1000);
                        }
                    }
                    break;

                case 1:
                    temp=0;     //reset temp
                    if(ColNum>2)                                            //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<2; i++)                          //changed
                            temp=temp+grid[RowNum][ColNum+i];

                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space!      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<2; i++)                  //changed
                            {
                                grid[RowNum][ColNum+i]=1;
                                display[RowNum][ColNum+i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              Pass                           ");
//                        Sleep(1000);
                        }

                    }
                    break;

                case 2:
                    temp=0;     //reset temp

                    if(RowNum>2)                                          //changed
                    {
                        printf("\r");
                        printf("              There is not enough space      ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<9-RowNum+1; i++)
                            temp=temp+grid[RowNum+i][ColNum];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<2; i++)                  //changed
                            {
                                grid[RowNum+i][ColNum]=1;
                                display[RowNum+i][ColNum]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                    break;

                case 3:
                    temp=0;     //reset temp
                    if(ColNum<1)                                    //changed
                    {
                        printf("\r");
                        printf("              There is not enough space     ");
                        Sleep(1000);
                    }
                    else
                    {
                        for(int i=0; i<ColNum+1; i++)
                            temp=temp+grid[RowNum][ColNum-i];
                        if(temp!=0)
                        {
                            printf("\r");
                            printf("              There is not enough space      ");
                            Sleep(1000);
                        }
                        else
                        {
                            for(int i=0; i<2; i++)                      //changed
                            {
                                grid[RowNum][ColNum-i];
                                display[RowNum][ColNum-i]='O';
                                flag=1;
                            }
//                        printf("\r");
//                        printf("              pass                                   ");
//                        Sleep(1000);
                        }
                    }
                }
            }
        }
        while(flag == 0);

        printf("\n");

        printf("                 0  1  2  3  4  5  6  7  8  9\n");
        for(int i=0; i<10; i++)         //print out default map
        {
            printf("              %c  ",row[i]);      //print rows
            for(int j=0; j<10; j++)
                printf("%          c  ",display[i][j]);  //print columns
            printf("\n");
        }
}

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

    ship1_deploy();
    ship2_deploy();
    ship4_deploy();
    ship7_deploy();
    
    return 0;
}