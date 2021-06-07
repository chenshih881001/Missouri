#include <stdio.h>
#include <stdlib.h>

#define HomePage 1
#define ModeSelection 2
#define CDL 3             //Choose Difficulty Level
#define Deployment 4
#define Battle 5
#define Result 6

#define SinglePlayer 7
#define PvP 8
#define Easy 9
#define Hard 10

int Mode = 0;
int Level = 0;

int main()
{
    switch(State)
    {
        case HomePage:
            /*
                1. Display Msg (Func)
                2. Press Enter to start (Func)
            */

        case ModeSelection:
            /*
                1. Display Msg (Func)
                2. Choose Game Mode (Func)

                Mode = SinglePlayer / PvP;
                if(Mode == SinglePlayer)
                    State = CDL;
                else
                    state = Deployment;
                break;
            */

        case CDL:
            /*
                1. Display Msg (Func)
                2. CDL (Func)

                Level = Easy / Hard;
                state = Deployment;
                break;
            */

        case Deployment:
            /*
                1. Show grid (Func)
                2. Deploy ships (Func)

                if(Mode == SinglePlayer)
                {
                    if(Level == Easy)
                    {
                        FUNCTIONS
                    }
                    else
                    {
                        FUNCTIONS
                    }
                }
                else
                {
                    FUNCTIONS
                }

                break;
            */

        case Battle:
            /*
                1. Select target (Func)
                2. Attack target (Func)
                3. Show attack result (Func)
                4. Quit (Func)
                if(win || quit)
                {
                    state = Result;
                    break;
                }
            */

        case Result:
            /*
                1. Display final result (Func)
                2. Decide next move (Func)
                if(Next == HomePage)
                {
                    state = HomePage;
                }
                else
                    break;
            */
    }

}
