#include <stdio.h>
#include "vec.h"

int main(int argc, char** argv)
{
	int n;
	TVector v1, v2, s, d;
	double mp;
	char* infilename, * outfilename;
	if (argc < 4)
	{
		printf("Incorrect arguments\n");
		return 1;
	}
	n = atoi(argv[1]); // atof
	printf("n = %d\n", n);
	infilename = argv[2];
	printf("in file name: %s\n", infilename);
	outfilename = argv[3];
	printf("out file name: %s\n", outfilename);
	read(infilename, &v1, &v2);
	s = sum(&v1, &v2);
	d = dif(&v1, &v2);
	mp = mplic(&v1, &v2);
	write(outfilename, &s, &d, mp);
	free(v1.x);
	free(v2.x);
	if (s.x != NULL)
	{
		free(s.x);
	}
	if (d.x != NULL)
	{
		free(d.x);
	}
	return 0;
}

