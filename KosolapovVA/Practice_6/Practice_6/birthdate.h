#ifndef BIRTTHDATE_H
#define BIRTTHDATE_H

#include "FIO.h"

typedef struct
{
    int day;
    int month;
    int year;
}Birth_d;

void read_br_d(char* in_f, Birth_d* d, int* i);
int check_date(const Birth_d *d);
void print_br_d(char* o_f, Birth_d* d);

#endif BIRTTHDATE_H
