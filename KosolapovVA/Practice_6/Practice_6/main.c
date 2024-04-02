#include "gibdd.h"
#include <locale.h>

int main(int argc, char** argv)
{
    I_gibdd* inf;
    Person p;
    Car c;
    int flag = 0, symb_c = 0, str_n=0;
    char* infilename, * outfilename;
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    if (argc < 3)
    {
        printf("Некорректные аргументы");
        return 1;
    }
    infilename = argv[1];
    read_str_n(infilename, &str_n, &symb_c);
    //read_info(infilename, &inf, &symb_c);
    inf = create_arr(infilename, str_n, &symb_c);
    printf("%s\n", &inf[1].pers.phone_num);
    printf("%s\n", &inf[1].TS.car_num);
    printf("%d\n", symb_c);
    flag = check_pers(&inf[1].pers);
    if (flag != 0)
    {
        if (flag == -1) 
        {
            printf("В файле есть некорректная дата рождения");
            free_pers(&p);
            return 1;
        }
        else if (flag == -2)
        {
            printf("В файле присутсвует некорректный формат даты рождения");
            free_pers(&p);
            return 1;
        }
        else if (flag == -3)
        {
            printf("В файле присутсвует некорректный номер телефона");
            free_pers(&p);
            return 1;
        }
    }
    outfilename = argv[2];
    FILE* f = fopen(outfilename, "w+");
    fclose;
    write_info(outfilename, &inf);
    free_pers(&inf[1].pers);
    free_car(&inf[1].TS);
    free_pers(&inf[2].pers);
    free_car(&inf[2].TS);
    return 1;
}

