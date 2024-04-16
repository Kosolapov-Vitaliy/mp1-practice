#ifndef FIO_H
#define FIO_H

#include "fio.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char* l_name;
    char* name;
    char* m_name;
}fio;

void print_fio(const char* o_f, fio* p);
void free_fio(fio* f);


#endif FIO_H
