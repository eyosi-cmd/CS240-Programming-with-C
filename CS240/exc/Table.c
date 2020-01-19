/* Eyosias Kibe */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int a, b, j, k;
	if (argc == 3) {
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}
	printf("%s %d %d\n\n", "Your numbers are: ",a,b);
	//scanf("%d%d", &a, &b);

	for (int i = 1; i <= a; ++i) {
		j = i*a;
		printf("%d x %d = %d\n",i, a, j); 
	}
	printf("\n");
	for (int i = 1; i <= b; ++i){
		k = i*b;
		printf("%d x %d = %d\n",i, b, k);
	}

	return 0;
}