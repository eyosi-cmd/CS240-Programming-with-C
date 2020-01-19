#include <stdio.h>

int main(int argc, char const *argv[])
{
 /*int n, c, k, j;
 printf("%s\n", "Enter the number: " );
scanf("%d", &n);
 k  = 3;
 	if(n > 1)
 		printf("2 ");
 	for (int i = 2; i <= n; k++)
 	{
 		for (j = 0; j < i; j++)
 			if(k%j == 0) 
 				break;
 		if(j == k){
 		 printf("%d ",k);
 		 i++;
 		}*/
	int i = 0;
	char *s = "Hello";
	while(*s != '\0')
		printf("%c", *s++);
	while(i++ <= 5);
	printf("\n%d\n", i);
 		



	
	return 0;
}
