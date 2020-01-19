/* Eyosias Kibe */
#include<stdio.h>
#define LEN 1024
void reverse(char* s, int j);
 int main() {
 	 int j;
     char s[LEN];
     j = 0;
	printf("Input String: ");
    scanf("%s", &(*s));
     while(*(s + j) != '\0') j++;
     // print reverse string
     printf("\"%s\" ", s);
     reverse(s, j);
     printf("reversed to: %s\n", s);
     
       return 0;
    }
     
    void reverse(char *s, int j)
    {
       int i;
       char *a, *b, temp;
       a  = s;
       b  = a;
       for (i = 0; i < j - 1; i++) b++;
       j = (j/2 + 1);
       for (i = 0; i < j - 1; i++)
       {        
          temp = *b;
          *b   = *a;
          *a = temp;
     	  b--;
          a++;
       
       }
    }