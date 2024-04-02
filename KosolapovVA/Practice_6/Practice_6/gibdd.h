#ifndef GIBDD_H
#define GIBDD_H

#include "gibdd.h"
#include "car.h"
#include "person.h"

typedef struct
{
    Person pers;
    Car TS;
    int otd;
}I_gibdd;

void read_info(char* in_f, I_gibdd* inf, int* i);
void write_info(char* o_f, I_gibdd* inf);
void read_str_n(char* in_f, int* str_n, int* i);
void allocate_inf(I_gibdd* inf, int str_n);
I_gibdd* create_arr(char* in_f, int str_n, int* symb_c);

#endif GIBDD_H
