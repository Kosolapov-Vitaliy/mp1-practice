#include "birthdate.h"

void read_br_d(char* in_f, Birth_d* d, int* i)
{
    char buf[248];
    int sz = 0;
    FILE* f = fopen(in_f, "r");
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d.%d.%d ", &(d->day), &(d->month), &(d->year));
    fclose(f);
    sz = strlen(buf);
    *i = *i + sz + 1;
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