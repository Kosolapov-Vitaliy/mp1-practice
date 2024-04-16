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

void rread_info(char* str_g, I_gibdd* inf);
void write_info(char* o_f, I_gibdd* inf);
void free_all(I_gibdd* ig);
int check_all(const I_gibdd* inf);

#endif GIBDD_H