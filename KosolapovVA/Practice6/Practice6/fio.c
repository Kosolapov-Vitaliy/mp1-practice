#include "fio.h"

fio read_fio(const char* inf, int* i)
{
    fio f;
    int j = *i;
    f.l_name = read_name(inf, &j);
    f.name = read_name(inf, &j);
    f.m_name = read_name(inf, &j);
    *i = j;
    printf("Функция завершена");
    return f;
}
char* read_name(const char* inf, int* i)
{
    char* name;
    char buf[10];
    int sz = 0, sz_f = 0;
    FILE* F = fopen(inf, "r");
    fseek(F, *i, SEEK_SET);
    fscanf(F, "%s", buf);
    fclose(F);
    sz = strlen(buf);
    printf("%d", sz);
    *i = *i + sz+1;
    sz++;
    name = _strdup(buf);
    printf("%s", name);
    return name;
}