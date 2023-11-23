#include <stdio.h>
#include <stdlib.h>
#define m 4
#define N 10
char* name[N] = { "Milk","Bread","Sausage","Cheese", "Flakes", "Fish fillet", "Pasta", "Sugar", "Juice", "Chocolate" };
double price[N] = { 99.9, 25.9, 189.9, 399.9, 199.9, 349.9, 139.9, 95.9, 119.9, 99.9 };
int barcode[N][m] = { {1,0,3,1},{2,0,4,1}, {3,0,5,1},{1,1,6,1},{4,0,7,1},{3,1,8,1},{2,1,9,1},{5,0,1,2},{6,0,2,2},{7,0,3,2} };
int discount[N] = {10, 5, 20, 3,1,8,25,4,50,30};


void check_barcode(int u_bar, int *id);
void inf_output(int id);
void print_receipt();
struct receipt
{
    char* name;
    double price;
    int count;
    int discount;
    double sum;
}pos[N];
int main()
{
    int operation=1, user_barcode, id, i=0;
    double sum = 0;
    for (; i < N; i++)
    {
        pos[i].name = name[i];
        pos[i].price = price[i];
        pos[i].count = 0;
        pos[i].discount = discount[i];
        pos[i].sum = 0;
    }
    print_receipt();
    do {
        switch (operation) 
        {
        case 1:
            id = 10;
            printf("Please scan the 4 digit barcode:");
            scanf("%d", &user_barcode);
            while (user_barcode / 1000 > 10)
            {
                printf("Error, your barcode is too long, scan again:");
                scanf("%d", &user_barcode);
            }
            check_barcode(user_barcode, &(id));
            if (id == 10)
            {
                printf("Error, this product is not in the database,try again\n");
            }
            else
            {
                printf("Enter 1 if you want to scan the next item.\n Enter 2 if you want to see the product description.\n Enter 3 if you want to add product details to the receipt.\n Enter 4 if you want to withdraw the receipt\n Enter 5 if you want to withdraw the total amount.\n");
                scanf("%d", &operation);
            }
            break;
        case 2:
            inf_output(id);
            printf("Enter 1 if you want to scan the next item.\n Enter 3 if you want to add product details to the receipt.\n Enter 4 if you want to withdraw the receipt\n Enter 5 if you want to withdraw the total amount.\n");
            scanf("%d", &operation);
            break;
        case 3:
            pos[id].count++;
            pos[id].sum = (pos[id].price + pos[id].price * (pos[id].discount / 100)) * pos[id].count;
            printf("Enter 1 if you want to scan the next item.\n Enter 4 if you want to withdraw the receipt\n Enter 5 if you want to withdraw the total amount.\n");
            scanf("%d", &operation);
            break;
        case 4:
            print_receipt();
            printf("Enter 1 if you want to scan the next item.\n Enter 5 if you want to withdraw the total amount.\n");
            scanf("%d", &operation);
            break;
        }
    } while (operation != 5);
    for (i=0; i < N; i++)
    {
        sum = sum + pos[i].sum;
    }
    printf("Sum receipt = %g", sum);
    return 0;
}
void print_receipt()
{
    int i = 0;
    for (; i < N; i++)
    {
        if (pos[i].count != 0)
        {
            printf("Name: %s,Price= %g, Count: %d, Discount= %d, Sum= %g \n", pos[i].name, pos[i].price, pos[i].count, pos[i].discount, pos[i].sum);
        }
    }
}
void check_barcode(int u_bar, int *f_id)
{
    int u_bar_arr[m], i = m - 1, j, count, p_bar=u_bar;
    for (; i >= 0; i--)
    {
        u_bar_arr[i] = p_bar % 10;
        p_bar = p_bar / 10;
    }
    for (j = 0; j < N; j++)
    {
        count = 0;
        for (i = 0; i < m; i++)
        {
            if (u_bar_arr[i] == barcode[j][i])
            {
                count++;
            }
        }
        if (count == 4)
        {
            *f_id = j;
        }
    }
}
void inf_output(int id)
{
    printf("Name:%s, price:%lf, discount:%d \n", name[id], price[id], discount[id]);
}

