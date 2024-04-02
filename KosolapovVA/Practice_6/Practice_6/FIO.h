#ifndef FIO_H
#define FIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char* L_Name;
    char* Name;
    char* M_Name;
    char* empty;
}Full_Name;

void read_fn(const char* in_f, Full_Name* a, int* i);
void print_fn(const char* o_f, Full_Name* a);
void free_nm(Full_Name *a);
#endif FIO_H