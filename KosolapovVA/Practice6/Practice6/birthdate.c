#include "birthdate.h"


void rread_br_d(char* str, Birth_d* d)
{
    int sz, i=0, j;
    char buf[20];
    sz = strlen(str);
    j = 0;
    memset(buf, '\0', 20);
    do {
        buf[j] = str[i];
        i++; j++;
    } while (str[i]!='.');
    d->day = atoi(buf);
    memset(buf, '\0', 20);
    j = 0;
    while (str[i] == '.')
        i++;
    do {
        buf[j] = str[i];
        i++; j++;
    } while (str[i] != '.');
    d->month = atoi(buf);
    memset(buf, '\0', 20);
    j = 0;
    while (str[i] == '.')
        i++;
    do {
        buf[j] = str[i];
        i++; j++;
    } while (i!=sz);
    d->year = atoi(buf);
}


void print_br_d(const char* o_f, Birth_d* d)
{
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%d", (d->day));
    if (d->month >= 10)
        fprintf(f, ".%d", (d->month));
    else fprintf(f, ".0%d", (d->month));
    fprintf(f, ".%d ", (d->year));
    fclose(f);
}

int check_date(const Birth_d* d)
{
    int flag = 0;
    if ((d->day < 0) || (d->month < 0) || (d->year < 0))
        flag = -2;
    else if (d->day == 0 || d->month == 0 || d->year == 0)
    {
        flag = -1;
    }
    else if (d->year > 2024)
    {
        flag = -1;
    }
    else if ((d->month > 12))
    {
        flag = -1;
    }
    if (d->day <= 31)
    {
        switch (d->month)
        {
        case 2:
            if (d->day <= 28) flag = 0;
            else if (((d->year) % 4 == 0 & (d->year) % 100 != 0) || (d->year) % 400 == 0)
            {
                if (d->day <= 29) flag = 0;
            }
        case 4:
            if (d->day <= 30) flag = 0;
        case 6:
            if (d->day <= 30) flag = 0;
        case 9:
            if (d->day <= 30) flag = 0;
        case 11:
            if (d->day <= 30) flag = 0;
            break;
        }
    }
    else 
        flag = -1;
    return flag;
}