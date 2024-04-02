#include "car.h"

void read_car(char* in_f, Car* c, int* i)
{
    char buf[248];
    int  sz;
    FILE* f = fopen(in_f, "r");
    if (f == NULL)
    {
        printf("Файл не найден.");
        abort();
    }
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s ", buf);
    sz = strlen(buf);
    *i = *i + sz + 1;
    c->car_num = (char*)malloc((sz+1) * sizeof(c->car_num));
    strcpy(&c->car_num, &buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s ", buf);
    sz = strlen(buf);
    *i = *i + sz + 1;
    c->passport = (char*)malloc((sz+1) * sizeof(c->passport));
    strcpy(&c->passport, &buf);
    fclose(f);
}

void write_car(char* o_f, Car* c)
{
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%s ", &c->car_num);
    fprintf(f, "%s ", &c->passport);
    printf("Конец работы, данные занесены\n");
    fclose(f);
}

void free_car(Car* c)
{
    free(c->car_num);
    free(c->passport);
}