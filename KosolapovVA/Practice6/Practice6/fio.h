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

fio read_fio(const char* inf, int* i);
char* read_name(const char* inf, int* i);


#endif FIO_H
