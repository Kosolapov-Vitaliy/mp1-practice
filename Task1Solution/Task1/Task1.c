#include <stdio.h>
#include <math.h>


int main()
{
    double x1, x2 ,y1, y2, r1, r2;
    printf("Input coordinate 1st circle and radius:");
    scanf(" %lf, %lf, %lf", &x1, &y1, &r1);
    if (r1 <= 0)
    {
        return 0;
    }
    printf("x=%lf, y=%lf, r=%lf \n", x1, y1, r1);
    printf("Input coordinate 2nd circle and radius:");
    scanf(" %lf, %lf, %lf", &x2, &y2, &r2);
    if (r2 <= 0)
    {
        return 0;
    }
    printf("x=%lf, y=%lf, r=%lf \n", x2, y2, r2);
    if ((x1 == x2) && (y1 == y2))
    {
        if (r1 == r2)
        {
            printf("Circle match");
        }
        else if ((r1 < r2) || (r2 < r1))
        {
            printf("Circle in circle");
        }
    }
    else
    {
        double distance, a,b;
        if (x1 <= x2)
        {
            a = x2 - x1;
        }
        else if (x1 > x2)
        {
            a= x1 - x2;

        }
        if (y1<=y2)
        {
            b = y2 - y1;
        }
        else if (y1 > y2)
        {
            b = y1 - y2;
        }
        distance = sqrt(a * a + b * b);
        printf("Distance=%lf \n", distance);
        if (distance > r1 + r2)
        {
            printf("Circles have not general dots");
        }
        else if (distance == r1 + r2)
        {
            printf("Circles have one general dots");
        }
        else if (((distance < r1 + r2) && (r1 - r2 < distance)) || ((distance < r2 + r1) && (r2 - r1 < distance)))
        {
            printf("Circles have two general dots");
        }
        else if ((distance == r2 - r1) || (distance == r1 - r2))
        {
            printf("Circles have one general dots and circle in circle");
        }
        else if ((distance < r2 - r1) || (distance < r1 - r2));

    }
}