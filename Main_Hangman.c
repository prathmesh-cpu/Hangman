#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char name[20];
int ran_arr[10], win = 0, coin = 0;

void c_black()
{
    printf("\033[0;30m");
}

void c_red()
{
    printf("\033[1;31m");
}

void c_green()
{
    printf("\033[1;32m");
}

void c_yellow()
{
    printf("\033[1;33m");
}

void c_blue()
{
    printf("\033[1;34m");
}

void c_purple()
{
    printf("\033[1;35m");
}

void c_cyan()
{
    printf("\033[1;36m");
}

void c_white()
{
    printf("\033[0;37m");
}

void hungman();


void leveleasy();

void levelmoderate();

void levelhard();

void showHungman(int);

void hint1(int);

void hint2(int);

void hint3(int);

int fun(char arr[10][20], int flag_level)
{
    int i, j, size, num, index, num1, flag_hint = 0, temp[20];

    char result[20], alphabet, space = '_', hint;

    index = 0;

    do
    {
        int ans = 0, flag = 0, wrg_atp = 5;
        char ex, rest;

        num1 = ran_arr[index];

        index++;
        c_purple();
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\tCOIN : %d", coin);
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\t\n ");

        if (flag_level == 1)
        {
            hint1(num1);
        }
        else if (flag_level == 2)
        {
            hint2(num1);
        }
        c_cyan();
        printf("\n\n\t\t\t\t\t\t  GUESS THE WORD (CAPITAL only) \n\n\t\t\t\t\t\t\t");

        size = strlen(&arr[num1][0]);

        for (i = 0; i < size; i++)
        {
            temp[i] = 1;
        }
        for (j = 0; j < size; j++)
        {
            c_red();
            printf("%c ", space);
            result[j] = space;
        }

        while (wrg_atp >= 0)
        {
            flag = 0;
            c_purple();
            printf("\n\n\tENTER A LETTER--> ");
            alphabet = getche();

            for (i = 0; i < size; i++)
            {
                if (temp[i] == 1)
                {
                    if (alphabet == arr[num1][i])
                    {
                        temp[i] = 0;
                        result[i] = arr[num1][i];
                        flag = 1;
                        ans++;
                    }
                }
            }

            c_red();
            printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
            c_purple();
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\tCOIN : %d", coin);
            c_cyan();
            printf("\n\t\t\t\t\t\t\tGUESS THE WORD \n\n\t\t\t\t\t\t\t");

            for (i = 0; i < size; i++)
            {
                c_red();
                printf("%c ", result[i]);
            }

            c_cyan();
            if (flag == 1)
            {
                printf("\n\n\t\t\t\t\t\t ( You have %d more letters to go)\n", size - ans);
            }
            else
            {

                printf("\n\n\t\t\t\t\t\t\t%c is a wrong guess", alphabet);
                printf("\n\t\t\t\t\t\t    (You have %d more guesses)\n", wrg_atp);
                showHungman(wrg_atp);
                wrg_atp--;
                if (flag_hint == 0)
                {
                    if (flag_level == 3)
                    {
                        c_purple();
                        printf("\n\t0) FOR HINT.\n\t1) TO CONTINUE.");
                        printf("\n\tENTER HERE--> ");
                        hint = getche();
                        if (hint == '0' && coin < 20)
                        {
                            c_red();
                            printf("\n\n\tINSUFFIENT COIN!!");
                        }
                        else if (hint == '0' && coin >= 20)
                        {
                            flag_hint = 1;
                            coin -= 20;
                            hint3(num1);
                        }
                    }
                }
            }

            if (ans == size)
            {
                break;
            }
        }

        c_red();
        if (ans == size)
        {
            win++;
            if (wrg_atp == 5)
            {
                if (flag_level == 1)
                {
                    coin += 5;
                    printf("\n\t\t\t\t\t\t\tYou Got 5 COIN\n");
                }
                else if (flag_level == 2)
                {
                    coin += 10;
                    printf("\n\t\t\t\t\t\t\tYou Got 10 COIN\n");
                }
                else
                {
                    coin += 15;
                    printf("\n\t\t\t\t\t\t\tYou Got 15 COIN\n");
                }
            }
            printf("\n\t\t\t\t\t\t\t YOUR SCORE: %d", win);
            printf("\n\n\t\t\t\t\t    HURRAY!!! %s YOU GUESSED IT CORRECTLY !!!", strupr(name));
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t YOUR SCORE: %d", win);
            printf("\n\t\t\t\t\t\t\t%s YOU LOST!!!", strupr(name));
            c_purple();
            printf("\n\t0) TO EXIT.\n\t1) TO RESTART.");
            printf("\n\tENTER HERE--> ");
            rest = getche();
            if (rest == '1')
            {
                index = 0;
                win = 0;
                coin = 0;
                continue;
            }
            else
            {
                exit(1);
            }
            return 0;
        }

        c_cyan();
        if (index == 10)
        {
            printf("\n\t\t\t\t\t\t\tLEVEL%d COMPLETED\n\n", flag_level);
            c_red();
            printf("\n\t--------------------------------------------------------------------------------------------------------------");
            return 0;
        }

        c_purple();
        printf("\n\t0) TO EXIT.\n\t1) TO CONTINUE.");
        printf("\n\tENTER HERE--> ");
        ex = getche();
        c_red();
        printf("\n\t--------------------------------------------------------------------------------------------------------------\n");

        if (ex == '0')
        {
            exit(1);
        }
        else
        {
            continue;
        }

    } while (1);

    return 0;
}

int main()
{
    char level1[10][20] = {"KEYWORDS", "POINTER", "ARRAY", "STRUCTURE", "FUNCTION", "VARIABLE", "CONSTANT", "STRING", "RECURSION", "UNION"};

    char level2[10][20] = {"LOGICAL", "MACRO", "GRAPH", "TYPEDEF", "ALGORITHM", "COMPILER", "DOUBLE", "FLOAT", "PREINCREMENT", "VOID"};

    char level3[10][20] = {"DEBUGGER", "REGISTER", "ENUM", "TIME.H", "FLOWCHART", "QUEUE", "STACK", "STRING.H", "TERNARY", "SWITCH"};

    int index = 0, n = 10, num, num1;

    bool b_arr[10] = {0};

    char ch;
    system("color ");
    c_cyan();
    printf("\n\n\t\t\t\t\t ~~~~~ CREATED BY ANIKET, PARTH AND PRATHAMESH ~~~~~ \n\n");

    hungman();

    c_purple();
    printf("\n\tENTER PLAYER NAME--> ");
    gets(name);

    c_purple();
    printf("\n\t1)EASY LEVEL\n\t2)MODERATE LEVEL\n\t3)HARD LEVEL\n");
    printf("\tENTER HERE--> ");
    ch = getche();

    srand(time(0));
    for (index = 0; index < n; index++)
    {
        num = rand() % 10;
        if (!b_arr[num])
        {
            ran_arr[index] = num;
        }
        else
        {
            index--;
        }
        b_arr[num] = 1;
    }

    switch (ch)
    {
    case '1':
        leveleasy();

        fun(level1, 1);

    case '2':
        levelmoderate();
        fun(level2, 2);

    case '3':
        levelhard();
        fun(level3, 3);
    }
    return 0;
}

void showHungman(int wrg_atp)
{
    c_purple();
    switch (wrg_atp)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\tCOIN : %d", coin);
    case 0:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   %cO/", '\\');
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   / %c", '\\');
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;

    case 1:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   %cO/", '\\');
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||     %c", '\\');
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;

    case 2:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   %cO/", '\\');
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;

    case 3:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   %cO/", '\\');
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;

    case 4:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||   %cO ", '\\');
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;

    case 5:
        printf("\n\t\t\t\t\t\t\t   ||===== ");
        printf("\n\t\t\t\t\t\t\t   ||    | ");
        printf("\n\t\t\t\t\t\t\t   ||    O ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        printf("\n\t\t\t\t\t\t\t   ||      ");
        break;
    }
}

void hint1(int num1)
{
    c_cyan();
    switch (num1)
    {

    case 0:
        printf("\n\t\t\t\t\t HINT : Words that have special meaning to Compiler");
        break;

    case 1:
        printf("\n\t\t\t\t\t   HINT : Stores address of another variable");
        break;

    case 2:
        printf("\n\t\t\t\t\t   HINT : Collection of similar data values");
        break;

    case 3:
        printf("\n\t\t\t\t\tHINT : Collection of variables under a single name");
        break;

    case 4:
        printf("\n\t\t\t\t\t   HINT : Group of statement that performs a task");
        break;

    case 5:
        printf("\n\t\t\t\t\tHINT : Memory location that we use for storing data");
        break;

    case 6:
        printf("\n\t\t\t\t\t   HINT : Variable whose value can't be changed");
        break;

    case 7:
        printf("\n\t\t\t\t\tHINT : Sequence of characters terminated with Null Character");
        break;

    case 8:
        printf("\n\t\t\t\t\t   HINT : Process in which Function calls itself");
        break;

    case 9:
        printf("\n\t\t\t\t\t HINT : Collection of variables in same memory location");
        break;
    }
}

void hint2(int num1)
{
    c_cyan();
    switch (num1)
    {

    case 0:
        printf("\n\t\t\t\t\t\t    HINT :  && Operator");
        break;

    case 1:
        printf("\n\t\t\t\t\t\t    HINT : #define");
        break;

    case 2:
        printf("\n\t\t\t\t\t\t    HINT :  Nodes and Edges");
        break;

    case 3:
        printf("\n\t\t\t\t\t\t    HINT : Name Of Data Type");
        break;

    case 4:
        printf("\n\t\t\t\t\t\t    HINT : Set of Instructions");
        break;

    case 5:
        printf("\n\t\t\t\t\t\t    HINT : It Translates");
        break;

    case 6:
        printf("\n\t\t\t\t\t\t    HINT : 8 Byte");
        break;

    case 7:
        printf("\n\t\t\t\t\t\t    HINT : 12.521334");
        break;

    case 8:
        printf("\n\t\t\t\t\t\t    HINT : ++i");
        break;

    case 9:
        printf("\n\t\t\t\t\t\t    HINT : Return Nothing");
        break;
    }
}

void hint3(int num1)
{
    c_cyan();
    switch (num1)
    {

    case 0:
        printf("\n\t\t\t\t\t\t    HINT :  Computer Program");
        break;

    case 1:
        printf("\n\t\t\t\t\t\t    HINT : Storage Variable");
        break;

    case 2:
        printf("\n\t\t\t\t\t\t    HINT : Keyword");
        break;

    case 3:
        printf("\n\t\t\t\t\t\t    HINT : Header File");
        break;

    case 4:
        printf("\n\t\t\t\t\t\t    HINT : Geometric Shapes");
        break;

    case 5:
        printf("\n\t\t\t\t\t\t    HINT : FIFO");
        break;

    case 6:
        printf("\n\t\t\t\t\t\t    HINT : LIFO");
        break;

    case 7:
        printf("\n\t\t\t\t\t\t    HINT : strcat(s1, s2)");
        break;

    case 8:
        printf("\n\t\t\t\t\t\t    HINT : (? :)");
        break;

    case 9:
        printf("\n\t\t\t\t\t\t    HINT : Break");
        break;
    }
}

void hungman()
{
    c_red();
    printf("\n\t\t\t\t\t\t\t\tHANGMAN\n");
    // printf("\n\t   --------------------------------------------------------------------------------------------------------------");
    // printf("\n\t   |    **      **       ****       ***      **    **********    ***        ***       ****       ***      **    |");
    // printf("\n\t   |    **      **      **  **      ****     **    **********    ****      ****      **  **      ****     **    |");
    // printf("\n\t   |    **      **     **    **     ** **    **    **            ** **    ** **     **    **     ** **    **    |");
    // printf("\n\t   |    **********    **********    **  **   **    **    ****    ** **    ** **    **********    **  **   **    |");
    // printf("\n\t   |    **********    **********    **   **  **    **    ****    **  ******  **    **********    **   **  **    |");
    // printf("\n\t   |    **      **    **      **    **    ** **    **      **    **   ****   **    **      **    **    ** **    |");
    // printf("\n\t   |    **      **    **      **    **     ****    **********    **          **    **      **    **     ****    |");
    // printf("\n\t   |    **      **    **      **    **      ***    **********    **          **    **      **    **      ***    |");
    // printf("\n\t   --------------------------------------------------------------------------------------------------------------\n");
    // printf("\n\n");
}

void leveleasy()
{
    c_red();
    printf("\n\n\t\tLEVEL 1: EASY\n");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
    // printf("\n\t\t\t**            **********    **        **    **********    **               *** ");
    // printf("\n\t\t\t**            **********    **        **    **********    **              **** ");
    // printf("\n\t\t\t**            **            **        **    **            **            **  ** ");
    // printf("\n\t\t\t**            **********    **        **    **********    **                ** ");
    // printf("\n\t\t\t**            **********     **      **     **********    **                ** ");
    // printf("\n\t\t\t**            **              **    **      **            **                ** ");
    // printf("\n\t\t\t**********    **********       ******       **********    **********        ** ");
    // printf("\n\t\t\t**********    **********        ****        **********    **********        ** ");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
}

void levelmoderate()
{
    c_red();
     printf("\n\n\t\tLEVEL 2: MEDIUM\n");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
    // printf("\n\t\t\t**            **********    **        **    **********    **              ******   ");
    // printf("\n\t\t\t**            **********    **        **    **********    **             ********  ");
    // printf("\n\t\t\t**            **            **        **    **            **            **      ** ");
    // printf("\n\t\t\t**            **********    **        **    **********    **                   **  ");
    // printf("\n\t\t\t**            **********     **      **     **********    **                 **    ");
    // printf("\n\t\t\t**            **              **    **      **            **              **       ");
    // printf("\n\t\t\t**********    **********       ******       **********    **********    ********** ");
    // printf("\n\t\t\t**********    **********        ****        **********    **********    ********** ");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
}

void levelhard()
{
    c_red();
     printf("\n\n\t\tLEVEL 3: HARD\n");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
    // printf("\n\t\t\t**            **********    **        **    **********    **            ********** ");
    // printf("\n\t\t\t**            **********    **        **    **********    **            ********** ");
    // printf("\n\t\t\t**            **            **        **    **            **            **      ** ");
    // printf("\n\t\t\t**            **********    **        **    **********    **                 ***** ");
    // printf("\n\t\t\t**            **********     **      **     **********    **                 ***** ");
    // printf("\n\t\t\t**            **              **    **      **            **            **      ** ");
    // printf("\n\t\t\t**********    **********       ******       **********    **********    ********** ");
    // printf("\n\t\t\t**********    **********        ****        **********    **********    ********** ");
    // printf("\n\t--------------------------------------------------------------------------------------------------------------\n");
}
