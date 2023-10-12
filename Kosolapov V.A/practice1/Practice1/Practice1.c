#include <stdio.h>

int main()
{
    double h, w, d, m, m1,m2,m3,m4,m5,i;
    double k = 0;
    do
    {
        printf("Input width:");
        scanf("%lf", &w);
    } while ((w < 80) || (w > 120));
    do
    {
        printf("Input height:");
        scanf("%lf", &h);
    } while ((h < 180) || (h > 220));
    do
    {
        printf("Input depth:");
        scanf("%lf", &d);
    } while ((d < 50) || (d > 90));
    double pDSP = 735, pDVP = 800, pTr = 670;
    m1 = ((h * w * 0.5)/1000000)*pDVP;
    m2 = (((h * d * 1.5)*2) / 1000000) * pDSP;
    m3 = (((d * w * 1.5)*2) / 1000000) * pDSP;
    m4 = ((h * w * 1) / 1000000) * pTr;
    i = h;
    while (i >= 40)
    {
        k++;
        i = i - (40 + 1.5);
    }
    m5 = ((k * ((w - 3) * d * 1.5)) / 1000000) * pDSP;
    m = m1 + m2 + m3 + m4 + m5;
    printf("m = %lf", m);
}