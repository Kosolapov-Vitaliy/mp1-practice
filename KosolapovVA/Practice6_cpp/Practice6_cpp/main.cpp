#include "fio.h"

void main(int* argc, char** argv)
{
    char* infilename, *outfilename;
    FILE* F;
    infilename =argv[1];
    F = fopen(infilename, "r");
    fclose(F);
    outfilename = argv[2];
    F = fopen(outfilename, "w+");
    fclose(F);
}