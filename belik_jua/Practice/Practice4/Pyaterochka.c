#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void Command()
{
    printf("1 - add item \n");
    printf("2 - display description \n");
    printf("3 - add item to check \n");
    printf("4 - form a check \n");
    printf("5 - calculate the total \n");
}

void Scan(int quantity[], int goods[], int num)
{
    int temp;
    printf("Enter barcode \n");
    scanf("%d", &temp);
    goods[num] = temp;
    printf("Enter the quantity of goods \n");
    scanf("%d", &quantity[temp]);
}

void Desciption(int goods[], char product[], int price[], int discount[], int num)
{
    printf("%d %s %d %d", goods[num], product[goods[num]], price[goods[num]], discount[goods[num]]);
}

void AddToCheck(int *check, int *total, int goods[], int quantity[], int price[], int discount[], int num)
{
    printf("1");
}

void main()
{
    int num = 0, i, total = 0, check = 0;
    int quantity[N], price[N], discount[N], goods[N];
    char product[N];
    Scan(quantity, goods, num);
    do
    {
        Command();
        scanf("%d", &i);
        switch (i) {
        case 1: 
            Scan(quantity, goods, num);
            break;
        case 2:
            Desciption(goods, product, price, discount, num);
            break;
        case 3: 
            AddToCheck(&check, &total, goods, quantity, price, discount, num);
            num++;
            break;

        }

    } while (i != 5);
}