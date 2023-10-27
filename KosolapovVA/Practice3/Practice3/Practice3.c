#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main()
{
    int num_arr[N], n_long=0, i,j;
    do {
        printf("Input the length of the number from 2 to 5: \n");
        scanf("%d ", n_long );
    } while ((n_long < 2)&&(n_long > 5));
    srand((unsigned int)time(0));
    num_arr[0] = 1+ rand() % 9;
    i = 1;
    while (i < n_long)
    {
        num_arr[i] = rand() % 10;
        for (j = 0; j < i; j++)
        {
            if (num_arr[i] == num_arr[j])
            {
                return 0;
            }
        }
        i++;
        printf("%d,%d", i, num_arr[i]);
    }
    return 0;


}