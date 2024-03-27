#include "FIO.h"

void read_fn(const char* in_f, Full_Name* a)
{
    FILE* f = fopen(in_f, "r");
    if (f == NULL)
    {
        printf("Файл не найден.");
        abort();
    }
    fscanf(f, "%s", &(a->L_Name));
    fscanf(f, "%s", &(a->Name));
    fscanf(f, "%s", &(a->M_Name));
    fclose(f);
}
void print_fn(const char* o_f, Full_Name* a)
{
    FILE* f = fopen(o_f, "w+");
    fprintf(f, "%s", a->L_Name);
    fprintf(f, "%s", a->M_Name);
    fprintf(f, "%s", a->L_Name);
    fclose(f);
}