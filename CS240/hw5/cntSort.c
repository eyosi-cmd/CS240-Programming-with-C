/*
 * implementation of counting sort
 *
 * project: hw5
 * name: Eyosias Kibe 
 * user??
 * date: 07/15/2019
 * file: cntSort.c
 * pseudo-code: 1.    Initialiaze count array elements with all 0's
                     from 0 to m - 1 index.    
                                  
                     2. Scan through the data array, and use each elements                   
                     data array as an index for count array, then increment count                   
                     array values by 1, every time it encounter the same indexs                   
                     or values of data[i].                    
                     That's how it counts the number of all repetitive                    
                     elements in the data array.                        
                     3. Use a for loop that goes from n - 1 to 0                     
                     Then check if the count does not equal to 0,                     
                     if so assign current position value in the data array and                     
                     decriment the values of count by 1 at current postion                    
                     until it reaches zero.   

                     4. When the value of count is equal 0, go to position 
                     of the count array, decrement i to maintain the position
                     of the array. Use the same itration until newly sorted data 
                     assigned in the data array or i becomes zero.  
 * notes:
 */

#include <stdlib.h>
void cntSort(unsigned m, unsigned n, unsigned data[])
{
unsigned *count;
unsigned position;
/* allocate memory */
count = (unsigned *)malloc(sizeof(unsigned) * m);

/* assign pos to 0 */
position = 0; 
for (int j = 0; j < m; ++j)
	  count[j] = 0;	
/*
 * Store count of each element of the data array.
 * use data[i] as an index of count array.
 */
for (int i = 0; i < n; ++i)	
	count[data[i]]++;
// iterate from n-1 to 0 
for (int i = n; i; i--)
{
/* if count[data[i]] is not equal to 0
 * assign the current position to the array data
 * decrement count in a current position.
 * else increment position and i 
 */
 	if (count[position]) 
	{
		data[n - i] = position;
		count[position]--;
	}
	else position++, i++;
}
/* end of the loop */ 

/* free up memory */
free(count);
}



