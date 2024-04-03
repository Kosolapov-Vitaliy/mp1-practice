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
    *i = *i + sz +1;
    *str_n = str;
}
void alloc_bd(I_gibdd** arr, int str_n)
{
    I_gibdd* tmp;
    tmp = (I_gibdd*)malloc(str_n * sizeof(I_gibdd));
    *arr = tmp;
}

void make_arr(I_gibdd* inf, const char* in_f, const int str_n, int* s_c)
{
    int i = 0, j = *s_c;
    for (; i < str_n; i++)
    {
        read_info(in_f, &inf[i], &j);
    }
}

void write_all(char* o_f, I_gibdd* bd, int str_n)
{
    FILE* F;
    int i, j = str_n;
    for (i = 0; i < j; i++)
    {
        write_info(o_f, &bd[i]);
        F = fopen(o_f, "a");
        fprintf(F, "\n");
        fclose(F);
    }
}

void seek_otd(char* o_f, I_gibdd* bd, int str_n )
{
    int count=0, num, i=0;
    FILE* F;
    printf("Введите номер отделения ГИБДД:\n");
    scanf("%d", &num);
    for (; i < str_n; i++)
    {
        if (bd[i].otd == num)
        {
            write_info(o_f, &bd[i]);
            F = fopen(o_f, "a");
            fprintf(F, "\n");
            fclose(F);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Ошибка: нет данных о данном отделе ГИБДД");
        F = fopen(o_f, "a");
        fprintf(F, "Данные о данном отделе ГИБДД отсутсвуют, либо введён несуществующий отдел ГИБДД\n");
        fclose(F);
    }

}

void free_bd(I_gibdd* bd, int str_n)
{
    int i = 0;
    for (; i < str_n; i++)
    {
        free_all(&bd[i]);
    }
    free(bd);
}

int check_read(const I_gibdd* inf, int str_n)
{
    int i = 0, str=0, flag=0;
    for (; i < str_n; i++)
    {
        str++;
        flag=check_all(&inf[i]);
        if (flag != 0)
        {
            if (flag == -1)
            {
                printf("В файле присутсвует некорректная дата");
            }
            else if (flag == -2)
            {
                printf("В файле присутсвует некорректный формат даты");
            }
            else if (flag == -3)
            {
                printf("В файле присутсвует некорректный номер телефона");
            }
            else if (flag == -4)
            {
                printf("В файле присутсвует некорректный номер ТС");
            }
            else if (flag == -5)
            {
                printf("В файле присутсвует некорректный номер Тех. паспорта");
            }
            printf("В строке: %d", str);
            return flag;
        }
    }
    return flag;
}