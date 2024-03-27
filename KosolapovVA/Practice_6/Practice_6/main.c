#include "FIO.h"
#include <locale.h>

int main(int argc, char** argv)
{
    Full_Name n;
    char *infilename, *outfilename;
    setlocale(LC_ALL, "Rus");
    if (argc < 3)
    {
        printf("Некорректные аргументы");
        return 1;
    }
    infilename = argv[1];
    printf("%s", infilename);
    read_fn(infilename, &n);
    outfilename = argv[2];
    printf("%s", outfilename);
    print_fn(outfilename, &n);
    return 1;
}
