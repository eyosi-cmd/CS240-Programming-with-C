#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int numdays,d, m, y;
  printf("Enter the days: %d\n", days );
  scanf("%d", &numdays);
  y = (int) numdays/365;
  numdays = numdays - (y*365);
  m = numdays/30;
  d = numdays -(m*30);
  printf("You have %d years %d months %d days", y, m, d);
	
	
	return 0;
}
