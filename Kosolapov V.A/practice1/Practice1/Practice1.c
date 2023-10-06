#include <stdio.h>

int main()
{
    double h, w, d, m, m1,m2,m3,m4,m5,i;
    double k = 0;
    printf("Input width, height, depth:");
    scanf("%lf, %lf, %lf", &w, &h, &d);
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
    m1 = ((h * w * 0.05)/1000000)*pDVP;
    m2 = (((h * d * 0.15)*2) / 1000000) * pDSP;
    m3 = (((d * w * 0.15)*2) / 1000000) * pDSP;
    m4 = ((h * w * 0.1) / 1000000) * pTr;
    i = h;
    while (i >= 40)
    {
        k++;
    }
    m5 = ((k * ((w - 0.3) * d * 0, 15)) / 1000000) * pDSP;
    printf("m = %lf", m = m1 + m2 + m3 + m4 + m5);
}