#include <stdio.h>
#include "vec.h"

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
	print_sum(&s);
	d = dif(&v1, &v2);
	print_dif(&d);
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

