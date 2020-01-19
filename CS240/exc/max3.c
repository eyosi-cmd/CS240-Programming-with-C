#include <stdio.h>
#define max(A,B) ((A) > (B) ? (A):(B))
#define max3(A,B,C) (max(A,B) > max(B,C)? max(A,B): max(B,C))


int main() {
    int i = 1;
    int j = 2;
    int k = 3;
    printf("From %d,%d,%d\n",i,j,k);
    printf("%d is the highest number.\n", max3(i,j,k));
    
    
    
   return 0;
}