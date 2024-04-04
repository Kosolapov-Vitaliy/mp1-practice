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
            wr_l->ts[count].pers.FIO.l_name = _strdup(in_l->ts[i].pers.FIO.l_name);
            wr_l->ts[count].pers.FIO.name = _strdup(in_l->ts[i].pers.FIO.name);
            wr_l->ts[count].pers.FIO.m_name = _strdup(in_l->ts[i].pers.FIO.m_name);
            wr_l->ts[count].pers.birth.day = in_l->ts[i].pers.birth.day;
            wr_l->ts[count].pers.birth.month = in_l->ts[i].pers.birth.month;
            wr_l->ts[count].pers.birth.year = in_l->ts[i].pers.birth.year;
            wr_l->ts[count].pers.phone_num = _strdup(in_l->ts[i].pers.phone_num);
            wr_l->ts[count].TS.car_num = _strdup(in_l->ts[i].TS.car_num);
            wr_l->ts[count].TS.passport = _strdup(in_l->ts[i].TS.passport);
            wr_l->ts[count].otd = in_l->ts[i].otd;
            count++;
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
                printf("� ����� ����������� ������������ ���� ");
            }
            else if (flag == -2)
            {
                printf("� ����� ����������� ������������ ������ ���� ");
            }
            else if (flag == -3)
            {
                printf("� ����� ����������� ������������ ����� �������� ");
            }
            else if (flag == -4)
            {
                printf("� ����� ����������� ������������ ����� �� ");
            }
            else if (flag == -5)
            {
                printf("� ����� ����������� ������������ ����� ���. �������� ");
            }
            printf("� ������: %d", str);
            return flag;
        }
    }
    return flag;
}