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
void free_all(I_gibdd* ig);
int check_all(const I_gibdd* inf);
I_gibdd* read_bd(char* in_f, int str_n, int* s_c);
void write_all(char* o_f, I_gibdd** bd, int str_n);
void free_bd(I_gibdd** bd, int str_n);
#endif GIBDD_H