/*
 * functions that convert between int, quaternary, and vigesimal numbers
 * 
 * project: hw3
 * name:   Eyoisas Kibe
 * date:    06/24/2019
 * file:    itox.c
 * notes:       
 */

#include <stdio.h>
#include <string.h>
#include "itox.h"
#define QUATLEN (sizeof(int) * 4)
#define VIGELEN  (sizeof(int) * 2)
/* function converts int n to a quaternary string in the
   hexstring array */
void itoq(char quaternaryStr[], int n)
{
 //decimal representation
  int q, r, i; 
  /* Define q as a quotient of four
   * and r as a remainder of four
   * update q and r after checking if
   * each elements in quaternaryStr[]
   * has remainder of either 0, 1, 2, 3
   */
  q = n / 4;
  r = n % 4;
 
  for (i = QUATLEN - 1; i >= 0; i--) {
    if (r == 0) 
      quaternaryStr[i] = '0';
    if (r == 1)
      quaternaryStr[i] = '1';
    if (r == 2)
      quaternaryStr[i] = '2';
    if (r == 3)
      quaternaryStr[i] = '3';
    if ((quaternaryStr[QUATLEN] = '\0'))
        break;
    r = q % 4;
    q = q / 4;
  }

}
/* function converts a quaternary string to its int value  */
int qtoi(char quaternaryStr[])
{ 
  /* queaternaryInt[] is an int array
   * that stores int value from quaternary string
   * that is converted
   * power1[] is another int array that holds
   * each power values of four until the loop ends 
   */
   static int quaternaryInt[QUATLEN];
   static int power1[QUATLEN];
  int i, sum;  // define a sum to add the products
   int b = 1;  
/* b is intialized to 1 as 
 * a base of the power  of 4 calculation
 * state a forloop to assign converted 
 * characters into decimal equivalents
 */
  for (i = 0; (i <= QUATLEN - 1); i++) {
        b *= 4;
        power1[i] = b;
    if (quaternaryStr[i] == '0')
      quaternaryInt[i] = 0;
    if (quaternaryStr[i] == '1')
      quaternaryInt[i] = 1;
    if (quaternaryStr[i] == '2')
      quaternaryInt[i] = 2;
    if (quaternaryStr[i] == '3')
      quaternaryInt[i] = 3;
  }

  sum = 0;
  for (i = QUATLEN - 1; quaternaryStr[i] != '\0' && i >= 0; i--) {
    if ((quaternaryStr[i] >= '0') && (quaternaryStr[i] <= '3')) {
        sum += quaternaryInt[i] * power1[QUATLEN - (i + 1)];
    }    
  }
  sum /= 4;
  return sum;
}

/* function converts int n to a vigesimal string in the
   hexstring array */

void itov(char vigesimalStr[], int n)
{  
  int r, i;
  int q;
  r = 0;
  q = n;
  for (i = VIGELEN - 1; 0 <= i; i--) {
    r = (q % 20);
  /* To convert integer into vigesimal number system
   * use the following algorithem
   */
           if( r < 10)
                r = r + 48; 
            else
                r = r + 55;
            vigesimalStr[i]= r;
            q = q / 20;
        }     
}
 
/* function converts a vigesimal string to its int value  */
int vtoi(char vigesimalStr[])
{ 
   int i;
  int sum = 0;
  i = 0;
  static int power2[VIGELEN];
  int b = 1;
  static int vigesimalInt[VIGELEN];
  for (i = 0; i <= (VIGELEN - 1); i++) {
     b *= 20;
     power2[i] = b;
    if (vigesimalStr[i] >= '0' && vigesimalStr[i] <= '9')
           vigesimalInt[i] = vigesimalStr[i] - 48;
    else if (vigesimalStr[i] >= 'a' && vigesimalStr[i] <= 'j')
            vigesimalInt[i] = (vigesimalStr[i] - 97) + 10;
    else if (vigesimalStr[i] >= 'A' && vigesimalStr[i] <= 'J')
            vigesimalInt[i] = (vigesimalStr[i] - 65) + 10;
    else ;
  }
  
  for (i = VIGELEN- 1; vigesimalStr[i] != '\0' && i >= 0; i--) {
    if ((vigesimalStr[i] >= '0' && vigesimalStr[i] <= '9')||
        (vigesimalStr[i] >= 'a' && vigesimalStr[i] <= 'j')||
        (vigesimalStr[i] >= 'A' && vigesimalStr[i] <= 'J')) {
            sum += vigesimalInt[i] * power2[VIGELEN - (i + 1)];
        }

    }
    sum = sum / 20; 
   return sum;
}