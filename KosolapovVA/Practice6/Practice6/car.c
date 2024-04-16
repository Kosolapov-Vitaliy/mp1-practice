#include "car.h"


void write_car(char* o_f, Car* c)
{
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%s ", c->car_num);
    fprintf(f, "%s ", c->passport);
    fclose(f);
}

int check_car(const Car* c)
{
    int flag = 0, sz;
    sz = strlen(c->car_num);
    if (sz == 9 || sz == 8)
        flag = flag;
    else
        flag = -4;
    if (flag != 0)
        return flag;
    sz = strlen(c->passport);
    if (sz == 10)
        flag = flag;
    else
        flag = -5;
    return flag;
}

void free_car(Car* c)
{
    free(c->car_num);
    free(c->passport);
}