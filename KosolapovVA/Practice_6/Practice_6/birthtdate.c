#include "birthdate.h"

void read_br_d(char* in_f, Birth_d* d, int*i)
{
    char buf[248];
    int sz = 0;
    FILE* f = fopen(in_f, "r");
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", buf);    
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d.%d.%d ", &(d->day), &(d->month), &(d->year));
    sz = strlen(buf);
    *i = *i + sz + 1;
    fclose(f);
}

void print_br_d(char* o_f, Birth_d* d)
{
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%d", (d->day));
    if (d->month >= 10)
        fprintf(f, "%d", (d->month));
    else fprintf(f, ".0%d", (d->month));
    fprintf(f, ".%d ", (d->year));
    printf("Конец работы, дата занесена\n");
    fclose(f);
}

int check_date(const Birth_d* d)
{
    if ((d->day < 0) || (d->month < 0 ) || (d->year <0))
        return -2;
    else if (d->day == 0 || d->month == 0 || d->year == 0) 
        return -1;
    else if (d->year > 2024)
    {
        return -1;
    }
    else if ((d->month > 12))
    {
        return -1;
    }
    else if (d->day <= 31)
    {
        switch (d->month)
        {
        case 2:
            if (d->day <= 28) return 0;            
            else if (((d->year) % 4 == 0 & (d->year) % 100 != 0) || (d->year) % 400 == 0)
            {
                if (d->day <= 29) return 0;
            }
        case 4:
            if (d->day <= 30) return 0;
        case 6:
            if (d->day <= 30) return 0;
        case 9:
            if (d->day <= 30) return 0;
        case 11:
            if (d->day <= 30) return 0;
            break;
        }        
    }
    else return -1;
}