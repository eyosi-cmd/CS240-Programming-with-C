#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, whiteCnt, otherCnt, i;
	//int whiteCnt1, otherCnt1, i1;
	int digitCnt1[6];
	int digitCnt2[4];
	for (int i = 0; i < 6; ++i)
	{ 
		digitCnt1[i] = 0;
		/* code */
		if (i < 4)
			digitCnt2[i] = 0;

	}
	
	while ((c = getchar()) != EOF){
		if (c >= '0' && c <= '5')
			digitCnt1[c -'0']++;
		else if (c >= '6' && c <= '9')
			digitCnt2[c -'6']++;

		else if (c == ' ' || c == '\n'|| c == '\t')
			whiteCnt++;
		else
			otherCnt++;
}

	printf("%s","digits1 = " );
	for (int i = 0; i < 6; ++i)
	{
		printf("%d", digitCnt1[i]);
	}
	printf("\n");
	printf("%s","digits2 = " );
	for (int i = 0; i < 4; ++i)
	{
		printf("%d", digitCnt2[i]);
		
	}
	printf(", white space = %d, other = %d\n,",whiteCnt, otherCnt);
}