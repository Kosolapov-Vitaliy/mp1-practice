#include "fio.h"


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