#ifndef GENERAL_H
#define GENERAL_H

#include "general.h"
#include "gibdd.h"

typedef struct
{
    I_gibdd* ts;
    int count;
} GLib;

void make_lib(char* in_f, GLib* in_l, int* i);
void make_wr_lib(GLib* in_l, GLib* wr_l, const int num);
void write_all(char* o_f, GLib* bd);
int check_read(const GLib* inf);
void free_bd(GLib* bd);
#endif GENERAL_H
