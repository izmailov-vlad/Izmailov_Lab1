#include <iostream>
#include <ctime>
#include "StackConsole.h"
#include <vld.h>

int main()
{
	double start = clock();
	StackConsole console;
	console.Actions();
	console.InputAction();
	unsigned int end_time = clock();
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}
