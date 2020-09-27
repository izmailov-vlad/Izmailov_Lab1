#include <ctime>
#include "Containers.h"
#include <vld.h>
#include <cstdio>
int main()
{
	double start = clock();
	Containers containers;
	containers.ChooseContainer();

	unsigned int end_time = clock();
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}
