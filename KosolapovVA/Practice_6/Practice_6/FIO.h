#ifndef FIO_H
#define FIO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char* Name;
    char* M_Name;
    char* L_Name;
}Full_Name;


void read_fn(const char* in_f, Full_Name* a);
void print_fn(const char* o_f, Full_Name* a);
#endif FIO_H