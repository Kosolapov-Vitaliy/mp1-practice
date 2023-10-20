#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 999

int main()
{
    int mode;
    do {
        printf("Enter 0 if you want gues or 1 if you want ask: \n");
        scanf("%d", &mode);
    } while ((mode != 1) && (mode != 0));
    if (mode == 0)
    {
        printf("You gues\n");
        srand((unsigned int)time(0));
        int number = rand() % 1000;
        int m_answer = 0, kol = 0;
        do {
            do {
                printf("Input number: \n");
                scanf("%d", &m_answer);

            } while ((m_answer > 1000) || (m_answer < 1));
            kol++;
            if (number > m_answer) printf("%d < answer\n", m_answer);
            else if (number < m_answer) printf("%d > answer\n", m_answer);
        } while (m_answer != number);
        printf("Right answer == %d, number of attempts == %d", number, kol);
        return 0;
    }
    if (mode == 1)
    {
        printf("You ask\n");
        int answer = 0;
        do {
            printf("Input answer: \n ");
            scanf("%d", &answer); printf("%d \n", answer);
        } while ((answer < 1) || (answer > 1000));        
        int i = 0, j = 1000, max=1000, bot_ans=0, kol=0;
        char znak;
        do {
            printf("%d\n", bot_ans = i + max / 2);  
            kol++;
            do {
                printf("Input >, < or =: \n");
                scanf("%s", &znak); printf("%s", znak);
            } while ((znak != "<")&& (znak != ">") && (znak != "="));
            if (znak == "<")
            {
                j = bot_ans;
                max = max / 2;
            }
            else if (znak == ">")
            {
                i = bot_ans;
                max = max / 2;
            }
        } while (znak != "=");
        printf("Answer = %d", bot_ans);
    }
}