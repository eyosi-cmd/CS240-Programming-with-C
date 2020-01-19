/*Eyosias Kibe
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
char text, ch;
char *p1, *p2;
char *p3, unshift[MAX];
char Casar(char s) {
	switch(s) {
		case 'a' :s = 'd';break; case 'b' :s ='e'; break; case 'c' :s ='f'; break; case 'd' :s ='g'; break; 
		case 'e' :s ='h'; break; case 'f' :s ='i'; break; case 'g' :s ='j'; break; case 'h' :s ='k'; break;
		case 'i' :s ='l'; break; case 'j' :s ='m'; break; case 'k' :s ='n'; break; case 'l' :s ='o'; break;
		case 'm' :s ='p'; break; case 'n' :s ='q'; break; case 'o' :s ='r'; break; case 'p' :s ='s'; break;
		case 'q' :s ='t'; break; case 'r' :s ='u'; break; case 's' :s ='v'; break; case 't' :s ='w'; break;
		case 'u' :s ='x'; break; case 'v' :s ='y'; break; case 'w' :s ='z'; break; case 'x' :s ='a'; break;
		case 'y' :s ='b'; break; case 'z' :s ='c'; break; default:;	
	}
	return s;
}

char unshifted(char ch) {
char temp;
temp = (ch >= 'a' && ch <= 'c') ? 
ch = ((ch - 'a') % 26 + 'x'): ch;
ch = (ch >= 'd' && ch <= 'z')? 
	((ch - 'a' - 3) % 26 + 'a'): ch;
ch =  (temp >= 'a' && temp <= 'w')? ch: temp;
return ch;

}
int main(int argc, char const *argv[])
{
	printf("%d\n",argc);
	char msg[] = "my secret message";
	p3 = malloc(sizeof(msg));
	p1 = msg;
 	for (int i = 0; i < sizeof(msg); i++)
	{
		p3[i] = Casar((char) *(p1 + i));
	} 
	int i = 0; 
	p2 = p3;
	while(i < sizeof(msg))
		unshift[i] = unshifted((char) *(p2 + i)), i++;
	printf("Orginal Text: %s\n", msg);

	printf("Shifted lower: %s\n", p3);
	printf("unshifted back: %s\n", unshift);
	printf("\n");

int a[] = {1, 3, 5,7, 9, 11, 13, 15, 19};
int *pa = &a[4];
int *pb = &a[1];



int a1[5] = {0, 1, 2, 3, 4};
int a2[5] = {5, 6, 7, 8, 9};
int *a3;
a3 = malloc(10);
for(i = 0; i < 5; i++)
	 a3[i] = a1[i], a3[i + 5] = a2[i]; 
for(i = 0; i < 10; i++)
	printf("%d", *(a3 + i));
	printf("\n");



printf("%d\n", *(a +2));
printf("%ld\n", pa - pb);
printf("%d\n", pb[1]);
printf("%d\n", *pa += 5);
printf("%d\n", *(pa += 2));
printf("%d\n", pa[3]);
printf("%p\n", pa);
printf("%p\n", pb);	
return 0;
}
