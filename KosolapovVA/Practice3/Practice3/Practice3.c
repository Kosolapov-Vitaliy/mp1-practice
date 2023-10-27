#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n_long;
    do {
        printf("Input the length of the number from 2 to 5");
        scanf("%d \n", n_long );
    } while ((n_long < 2)&&(n_long > 5));
}