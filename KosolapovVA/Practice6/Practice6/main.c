#include "general.h"

int  main(int argc, char** argv)
{
    int symb_c=0, flag = 0, j, i=0, num;   
    GLib in_lib;
    GLib right_lib;
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
    make_lib(infilename, &in_lib, &symb_c);
    flag = check_read(&in_lib);
    if (flag != 0)
    {
        free_bd(&in_lib);
        return flag;
    }
    F = fopen(outfilename, "w");
    fclose(F);
    printf("Введите номер отделения ГИБДД:\n");
    scanf("%d", &num);
    make_wr_lib(&in_lib, &right_lib, num);
    write_all(outfilename, &right_lib);
    free_bd(&in_lib);
    free_bd(&right_lib);
    return 1;
}