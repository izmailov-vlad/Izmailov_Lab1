#include <ctime>
#include "ContainersFactory.h"
#include <vld.h>
#include <cstdio>
int main()
{
	double start = clock();
	ContainersFactory containers;
	containers.ChooseContainer();

	unsigned int end_time = clock();
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}
