#include "general.h"

void make_lib(char* in_f, GLib* in_l, int *i)
{
    char buf[32];
    int sz = 0, str, ci = 0, j;
    FILE* f = fopen(in_f, "r");
    fscanf(f, "%s", buf);
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%d", &str);
    fclose(f);
    sz = strlen(buf);
    *i = *i + sz + 1;
    in_l->count = str;
    in_l->ts = (I_gibdd*)malloc(in_l->count * sizeof(I_gibdd));
    j = *i;
    for (; ci < in_l->count; ci++)
    {
        read_info(in_f, &in_l->ts[ci], &j);
    }
    *i = j;
}

void make_wr_lib(GLib* in_l, GLib* wr_l, const int num)
{
    int count = 0, i = 0, j=0;
    for (; i < in_l->count; i++)
    {
        if (in_l->ts[i].otd == num)
        {
            count++;
        }
    }
    wr_l->count = count;
    count = 0;
    wr_l->ts = (I_gibdd*)malloc(wr_l->count * sizeof(I_gibdd));
    for (i=0; i < in_l->count; i++)
    {
        if (in_l->ts[i].otd == num)
        {
            wr_l->ts[count] = in_l->ts[i];
            count++
        }
    }
}

void write_all(char* o_f, GLib *bd)
{
    FILE* F;
    int i;
    for (i = 0; i < bd->count; i++)
    {
        write_info(o_f, &bd->ts[i]);
        F = fopen(o_f, "a");
        fprintf(F, "\n");
        fclose(F);
    }
}

void free_bd(GLib *lib)
{
    int i = 0;
    for (; i < lib->count; i++)
    {
        free_all(&lib->ts[i]);
    }
    free(lib->ts);
}

int check_read(const GLib *inf)
{
    int i = 0, str=0, flag=0;
    for (; i < inf->count; i++)
    {
        str++;
        flag = check_all(&inf->ts[i]);
        if (flag != 0)
        {
            if (flag == -1)
            {
                printf("В файле присутсвует некорректная дата ");
            }
            else if (flag == -2)
            {
                printf("В файле присутсвует некорректный формат даты ");
            }
            else if (flag == -3)
            {
                printf("В файле присутсвует некорректный номер телефона ");
            }
            else if (flag == -4)
            {
                printf("В файле присутсвует некорректный номер ТС ");
            }
            else if (flag == -5)
            {
                printf("В файле присутсвует некорректный номер Тех. паспорта ");
            }
            printf("в строке: %d", str);
            return flag;
        }
    }
    return flag;
}