#include "gibdd.h"

void read_info(char* in_f, I_gibdd* inf, int* i)
{
    read_person(in_f, &(inf->pers), &*i);
    read_car(in_f, &(inf->TS), &*i);
    char buf[248];
    int sz = 0;
    FILE* f = fopen(in_f, "r");
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d ", &(inf->otd));
    sz = strlen(buf);
    *i = *i + sz + 1;
    fclose(f);

}
void write_info(char* o_f, I_gibdd* inf)
{
    write_person(o_f, &inf->pers);
    write_car(o_f, &inf->TS);
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%d", inf->otd);
    fclose(f);
}

void read_str_n(char* in_f, int* str_n, int* i)
{
    char buf[32];
    int sz = 0;
    FILE* f = fopen(in_f, "r");
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d", &*str_n);
    sz = strlen(buf);
    *i = *i + sz + 1;
    fclose(f);
}

I_gibdd*create_arr(char* in_f, int str_n, int* symb_c)
{
    I_gibdd* inf;
    inf = (I_gibdd*)malloc(str_n * sizeof(I_gibdd));
    int i = 0;
    for (; i < str_n; i++)    {

        read_info(in_f, &inf[i], &symb_c);
    }
    return inf;
}