#include <ctime>
#include "ConsoleIteractor.h"
#include "Test.h"
#include <vld.h>
#include <cstdio>
int main()
{
	double start = clock();
	Test test;
	if (test.RunTest()) {
		ConsoleIteractor console;
		console.InputAction();
			//TestForConstructors();
			//TestForOperators();
	}

	unsigned int end_time = clock();
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}
