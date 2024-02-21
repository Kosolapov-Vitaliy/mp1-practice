#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int n;
	double* x;
} TVector;

void allocate(TVector* v, int n);
void fill(TVector* v);
void print(TVector* v);
TVector sum(TVector* v1, TVector* v2);
TVector dif(TVector* v1, TVector* v2);
double mplic(TVector* v1, TVector* v2);

int main()
{
	int n;
	TVector v1, v2, s, d;
	double mp;
	printf("Lenght of v1 = ");
	scanf("%d", &n);
	allocate(&v1, n);
	printf("Lenght of v2 = ");
	scanf("%d", &n);
	allocate(&v2, n);
	fill(&v1);
	fill(&v2);
	s = sum(&v1, &v2);
	print(&s);
	d = dif(&v1, &v2);
	print(&d);
	mp = mplic(&v1, &v2);
	printf("mplic= %lf", mp);
	free(v1.x);
	free(v2.x);
	if (s.x != NULL)
	{
		free(s.x);
		free(d.x);
	}
	return 0;
}

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
void print(TVector* v)
{
	int i = 0;
	printf("Vector: ");
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