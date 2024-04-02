#include "FIO.h" 
void read_fn(const char* in_f, Full_Name* a, int* i)
{
    char buf[248];
    int s_sz;
    FILE* f = fopen(in_f, "r");
    if (f == NULL)
    {
        printf("Файл не найден.");
        abort();
    }
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s ", buf);
    s_sz = strlen(buf);
    *i = *i + s_sz + 1;
    a->L_Name = (char*)malloc((s_sz) * sizeof(a->L_Name));
    strcpy(&a->L_Name, &buf);
    fscanf(f, "%s ", buf);
    s_sz = strlen(buf);
    a->Name = (char*)malloc((s_sz) * sizeof(a->Name));
    *i = *i + s_sz + 1;
    strcpy(&a->Name, &buf);
    fscanf(f, "%s ", buf);
    s_sz = strlen(buf);
    a->M_Name = (char*)malloc((s_sz) * sizeof(a->M_Name));
    *i = *i + s_sz + 1;
    strcpy(&a->M_Name, &buf);
    fclose(f);
}

void print_fn(const char* o_f, Full_Name* a)
{
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%s ", &a->L_Name);
    fprintf(f, "%s ", &a->Name);
    fprintf(f, "%s ", &a->M_Name);
    printf("Конец работы, имена занесены\n");
    fclose(f);
}

void free_nm(Full_Name* a)
{    
    free(a->L_Name);
    free(a->Name);
    free(a->M_Name);
}
