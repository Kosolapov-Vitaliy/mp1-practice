#ifndef GENERAL_H
#define GENERAL_H

#include "general.h"
#include "gibdd.h"

void read_str_n(char* in_f, int* str_n, int* i);
void alloc_bd(I_gibdd** arr, int str_n);
void make_arr(I_gibdd* inf, const char* in_f, const int str_n, int* s_c);
void write_all(char* o_f, I_gibdd* bd, int str_n);
void free_bd(I_gibdd* bd, int str_n);
#endif GENERAL_H
