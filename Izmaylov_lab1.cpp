#include <ctime>
#include "ConsoleIteractor.h"
#include <vld.h>
#include <cstdio>
int main()
{
	double start = clock();
	ConsoleIteractor console;
	console.Test();

	unsigned int end_time = clock();
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}
