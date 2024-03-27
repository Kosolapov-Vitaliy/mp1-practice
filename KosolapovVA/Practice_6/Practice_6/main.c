#include <locale.h>
#include "FIO.h"

int main(int argc, char** argv)
{
    Full_Name n;
    char* infilename = argv[1];
    char* outfilename = argv[2];
    setlocale(LC_ALL, "Rus");
    read_fn(infilename, &n);
    print_fn(outfilename, &n);
}
