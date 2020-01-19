/*
 * implement of myAdd() using fullAdderSum() and fullAdderCarry()
 *
 * project: hw4
 * name: Eyosias Kibe
 * user??
 * date: 07/01/2018
 * file: myAdd.c
 * pseudo code:
 * notes: It builds a 32-bit integer adder
 */

#include <stdio.h>
#include <stdlib.h>
#include "adder.h"
#define BITS 32
/*
 * use fullAdderSum() and fullAdderCarry() to add two numbers bit by bit
 * p and q are nonnegative
 * assume their sum does not cause overflow of a 32-bit unsigned int
 */

unsigned int myAdd(unsigned int p, unsigned int q)
{
unsigned int mySum;
enum bits Cin;
// mySum and Cin starts at zero.
mySum = 0; Cin = ZERO; 
for (int i = 0; i < BITS; i++)
{
// divide p and q by the power of 2 XAND 1
	enum bits P = (p >> i)&1;
	enum bits Q = (q >> i)&1;
/* 
 * use fullAdderSum() to add P, Q and Cin
 * get the sum
 */
	enum bits sum = fullAdderSum(P, Q, Cin);
/* 
 * use fullAdderCarry() to add P, Q and Cin
 * get the Cout (current carryout)
 */
	enum bits Cout = fullAdderCarry(P, Q, Cin);

/*
 * Assign bit i of mySum to be sum, when it's 0 or 1.
 * Use halfAdderSum() and halfAdderCarry() to convert
 * mySum to 0 or 1 based on the value of sum.
 * 
 */
	if (sum) mySum = halfAdderSum(mySum, (1 << i));
	else mySum = halfAdderCarry(mySum , ~(1 << i));
// update Cin from Cout
	Cin = Cout;
	/* End of the loop */
}
	// return final sum after the iteration
	return mySum;
}
