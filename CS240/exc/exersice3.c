/*Eyosias Kibe
*/
#include <stdio.h>

#define count 10
#define var 5 

int main(void)
{
	int update;
	for (int i = count; 0 < i; i/2)
	{
		for (int j = 0; j < i; j++)
		{	
			int c = j;
			printf("%3s","*");
			i--;
			
		}

	 printf("\n");
	}
	return 0;
}