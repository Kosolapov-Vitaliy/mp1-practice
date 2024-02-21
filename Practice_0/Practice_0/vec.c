#include "vec.h"

void allocate(TVector* v, int n)
{
	v->n = n;
	v->x = (double*)malloc(sizeof(double) * n);
}
void fill(TVector* v)
{
	int i = 0;
	printf("Fill vector: ");
	for (; i < v->n; i++)
	{
		scanf("%lf", &(v->x[i]));
	}
}
void print_sum(TVector* v)
{
	int i = 0;
	printf("Vector sum: ");
	for (; i < v->n; i++)
	{
		printf("%.2lf ", v->x[i]);
	}
	printf("\n");
}
void print_dif(TVector* v)
{
	int i = 0;
	printf("Vector dif: ");
	for (; i < v->n; i++)
	{
		printf("%.2lf ", v->x[i]);
	}
	printf("\n");
}
TVector sum(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	allocate(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] + v2->x[i];
	}
	return res;
}
TVector dif(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	allocate(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] - v2->x[i];
	}
	return res;
}
double mplic(TVector* v1, TVector* v2)
{
	int i = 0;
	double res = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		return 0;
	}
	for (; i < v1->n; i++)
	{
		res = res + (v1->x[i] * v2->x[i]);
	}
	return res;
}