/* Eyosias Kibe 
 * CS 240
 * Homework 2
 */
#include <stdio.h>
# define SIZE 27
# define AST 4000

void histo(int words[]){
/* SIZE represents the max capacity of words length
 * AST is numbers of words required to a to print
 * an asterisk "*" for 1 - 4000 words
 * add more asterisks with 4000 words differences.
 * x stores the word differences as words/AST. 
 * v is AST in  a float type
 */
	int x = 0;
	float v = (float) AST;
	for (int i = 1; i <= SIZE; ++i)
	{
/* prints 27 lines of outputs with
 * a number of lines (width 2), word counts (width 6),
 * and a single asterisk in every 4000 words difference.
 */
		printf("%2d %6d ", i, words[i]);
		if (words[i] > AST) {
/* if the amounts of words above
 * 4000, calculate histograms
 * with an AST diffrences.
 */
		x = ((words[i]/AST) + 1);
		for (int k = 0; k < x; k++)
			printf("%s","*" );
		}
		else if (words[i] < AST && (words[i]/v) != 0) {
/* when words are less than AST,
 * but not equal 0 length,
 * print a single astricks.
 */
			printf("%s","*");
		}
/* else do nothing */  
	else ;
/* goto a new line */
	printf("\n");	
		
	}
}

int main(void)
{
/* an array called 'words' holds 27 chars at max
 * Cnt is a counter for each letter in a word
 * c gets chars as an input comparison of  EOF
 * in the while loop.
 */
   int words[SIZE];
   int Cnt, c;
   /* sets 0 as default values of words array */
	for (int i = 1; i <= SIZE;i++)
     	words[i] = 0;

     Cnt = 0;
   while ((c = getchar()) != EOF) { 
/* check if each chars in c are alphanumeric
 * means chars between 0-9, a-z or A -Z 
 */
     if ((c >= 'a' && c <= 'z') 
     	|| (c >= 'A' && c <= 'Z') || 
	 	(c >= '0' && c <= '9')) {
/* increment the charter counter 
 * by 1
 */
     	Cnt++;      
     }
/* if c is not alphanumeric, 
 * count total number of words in c 
 * using the length of each word 
 * in the loop as an index.
 */
     else {
/* find the total amounts of words
 * rest Cnt to 0, when a new word
 * starts counting
 */
       words[Cnt]++;
       Cnt = 0;
     }
}
/* invoke the histogram function
 * of the program.
 */
	histo(words);
	return 0;
}

