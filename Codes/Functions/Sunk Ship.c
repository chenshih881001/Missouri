










void Query_Ship_State()
{
    printf("          Was a ship sunk?\n");
    printf("\n");
    printf("          [Yes]     No                  ");

    int flag=0;

    while(1)
    {
        Check_key();
        if(key ==' ')
            break;
        else if(key == '\t' && flag == 0)
        {
            printf("\r");
            printf("           Yes     [No]        ");
            flag = 1;
        }
        else if(key == '\t' && flag == 1)
        {
            printf("\r");
            printf("          [Yes]     No             ");
            flag = 0;
        }
    };

    if(flag == 0)
        printf("          A ship has sunk!\n");
    else printf ("          No ship was sunk this turn!\n")

    system("cls");
    return flag;
}