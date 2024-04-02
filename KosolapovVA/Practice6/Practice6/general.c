#include "gibdd.h"

void read_str_n(char* in_f, int* str_n, int* i)
{
    char buf[32];
    int sz = 0, str;
    FILE* f = fopen(in_f, "r");
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d", &str);
    fclose(f);
    sz = strlen(buf);
    *i = *i + sz + 1;
    *str_n = str;
}