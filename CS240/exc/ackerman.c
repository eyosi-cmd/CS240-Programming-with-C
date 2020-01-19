#include <stdio.h>
int ackerman(int i, int j);
int main()
{
	int i, j;
	printf("%s\n", "Enter i and j");
	scanf("%d%d", &i, &j);
	int p = ackerman(i, j);
	printf("%d\n",p);
	return 0;
}
int ackerman(int i, int j)
{
	if (i == 0)
		return 1;
	if (i == 1 && j == 0) 
		return 2;
	if (i > 1 && j == 0) 
		return i + 2;
	return ackerman(ackerman(i - 1, j), j-1);
}
