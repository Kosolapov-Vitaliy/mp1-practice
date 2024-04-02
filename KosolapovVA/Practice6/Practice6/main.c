#include "fio.h"

int  main(int argc, char** argv)
{
    int symb_c=0;
    fio f;
    char* infilename, * outfilename;
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    if (argc < 3)
    {
        printf("Некорректные данные");
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];
    //f.l_name = read_name(infilename, &symb_c);
    f = read_fio(infilename, &symb_c);
    printf("%s", f.l_name);
    FILE* F = fopen(outfilename, "w");
    fclose(F);
    free(f.l_name);
    free(f.name);
    free(f.m_name);
    return 1;
}