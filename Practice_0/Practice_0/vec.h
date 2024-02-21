#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
typedef struct
{
	int n;
	double* x;
} TVector;

void allocate(TVector* v, int n);
void fill(TVector* v);
void print_sum(TVector* v);
void print_dif(TVector* v);
TVector sum(TVector* v1, TVector* v2);
TVector dif(TVector* v1, TVector* v2);
double mplic(TVector* v1, TVector* v2);
#endif // !VEC_H
