﻿#include "general.h"

int  main(int argc, char** argv)
{
    int symb_c=0, flag = 0, str_n, j, i=0;    
    I_gibdd* info;
    char *infilename, *outfilename;
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
    fclose(F);
    outfilename = argv[2];
    read_str_n(infilename, &str_n, &symb_c);
    alloc_bd(&info, str_n);
    make_arr(info, infilename, str_n, &symb_c);
    flag = check_read(info, str_n);
    if (flag != 0)
    {
        free_bd(info, str_n);
        return flag;
    }
    F = fopen(outfilename, "w");
    fclose(F);
    seek_otd(outfilename, info, str_n);
    free_bd(info, str_n); 
    return 1;
}