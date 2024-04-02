#include "general.h"

int  main(int argc, char** argv)
{
    int symb_c=0, flag=0, str_n, j, i=0;    
    I_gibdd* info;
    char* infilename, * outfilename;
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    if (argc < 3)
    {
        printf("Некорректные данные");
        return 1;
    }
    infilename = argv[1];
    FILE* F = fopen(infilename, "r");
    if (F == NULL)
    {
        printf("Файл пуст.");
        return 2;
    }
    outfilename = argv[2];
    read_str_n(infilename, &str_n, &symb_c);
    info = (I_gibdd*)malloc(str_n * sizeof(I_gibdd));
    for (; i < str_n; i++)
    {
        j = symb_c;
        read_info(infilename, &info[i], &j);
        symb_c = j;
    }
    if (flag != 0)
    {
        if (flag == -1)
        {
            printf("Некорректная дата");
            free_bd(&info, str_n);
            return 1;
        }
        else if (flag == -2)
        {
            printf("Некорректный формат даты");
            free_bd(&info, str_n);
            return 1;
        }
        else if (flag == -3)
        {
            printf("Некорректный номер телефона");
            free_bd(&info, str_n);
            return 1;
        }
        else if (flag == -4)
        {
            printf("Некорректный номер ТС");
            free_bd(&info, str_n); 
            return 1;
        }
        else if (flag == -5)
        {
            printf("Некорректный номер Тех. паспорта");
            free_bd(&info, str_n); 
            return 1;
        }
    }
    F = fopen(outfilename, "w");
    fclose(F);
    write_all(outfilename, &info, str_n);
    free_bd(&info, str_n); 
    return 1;
}