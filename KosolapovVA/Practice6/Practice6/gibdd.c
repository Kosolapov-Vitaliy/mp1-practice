#include "gibdd.h"

void read_info(char* in_f, I_gibdd* inf, int* i)
{
    char buf[248];
    int sz = 0, j;
    j = *i;
    read_person(in_f, &(inf->pers), &j);
    read_car(in_f, &(inf->TS), &j);
    *i = j;
    FILE* f = fopen(in_f, "r");
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d ", &(inf->otd));
    fclose(f);
    sz = strlen(buf);
    *i = *i + sz + 2;

}
void write_info(char* o_f, I_gibdd* inf)
{
    write_person(o_f, &(inf->pers));
    write_car(o_f, &(inf->TS));
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%d", inf->otd);
    fclose(f);
}
int check_all(const I_gibdd* inf)
{
    int flag = 0;
    flag = check_car(&inf->TS);
    if (flag != 0)
        return flag;
    flag = check_pers(&inf->pers);
    return flag;
}



void free_all(I_gibdd* ig)
{
    free_pers(&ig->pers);
    free_car(&ig->TS);
}