#include "fio.h"

void read_fio(fio* f, const char* inf, int* i)
{
    char* buf[128];
    int sz = 0;
    FILE* F = fopen(inf, "r");
    fseek(F, *i, SEEK_SET);
    fscanf(F, "%s", buf);
    fclose(F);
    sz = strlen(buf);
    *i = *i + sz + 1;
    f->l_name = _strdup(buf);
    F = fopen(inf, "r");
    fseek(F, *i, SEEK_SET);
    fscanf(F, "%s\n", buf);
    fclose(F);
    sz = strlen(buf);
    *i = *i + sz + 1;
    f->name = _strdup(buf);
    F = fopen(inf, "r");
    fseek(F, *i, SEEK_SET);
    fscanf(F, "%s\n", buf);
    fclose(F);
    sz = strlen(buf);
    *i = *i + sz + 1;
    f->m_name = _strdup(buf);
}

void print_fio(const char* o_f, fio* f)
{
    FILE* F = fopen(o_f, "a");
    fprintf(F, "%s ", f->l_name);
    fprintf(F, "%s ", f->name);
    fprintf(F, "%s ", f->m_name);
    fclose(F);
}

void free_fio(fio* f)
{
    free(f->l_name);
    free(f->name);
    free(f->m_name);
}