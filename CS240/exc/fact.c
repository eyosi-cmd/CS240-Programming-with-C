#include <stdio.h>
int factorial(int a);
int main(int argc, char const *argv[])
{
	int n = 
	int p = factorial(n);
	printf("%d\n",p);
	return 0;
}
int factorial(int i, int j)
{
	if (i == 0) return 1;
	if (i ==  1 && j == 0) return 2;
	if (i > 1 && j == 0) return j + 2;
	return factorial(factorial(i - 1, j), (j -1));
}
