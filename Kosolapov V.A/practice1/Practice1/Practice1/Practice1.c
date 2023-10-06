#include <stdio.h>

int main()
{
    double h, w, d, m;
    printf("Input width, height, depth:");
    scanf("%lf, %lf, %lf", w, h, d);
    if ((180 <= h <= 220) || (80 <= w <= 120) || (50 <= d <= 90))
    {
        printf("Correct");
    }
    else
    {
        printf("Incorrect");
        return 0;
    }
    double pDSP = 735, pDVP = 800, pTr = 670;

}