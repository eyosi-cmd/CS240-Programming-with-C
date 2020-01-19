/*
 * implement fullAdderSum() fullAdderCarry()
 *
 * project: hw4
 * name: Eyosias Kibe
 * user:
 * date: 07/01/2019
 * file: adder.c
 * pseudo code:
 * notes: Half Adder and Full Adder using bitwise oprations
 */
#include "adder.h"

/*
 * add two bits P and Q
 * return the sum bit
 */

enum bits halfAdderSum(enum bits P, enum bits Q)
{
  return P ^ Q;
}

/*
 * add two bits P and Q
 * return the carry bit
 */
enum bits halfAdderCarry(enum bits P, enum bits Q)
{
  return P & Q;
}

/*
 * add three bits P, Q, and Cin
 * return the sum bit
 */

enum bits fullAdderSum(enum bits P, enum bits Q, enum bits Cin)
{
// Find and return the sum of P, Q, and Cin
enum bits sum = ((P^Q)^ Cin);
 return sum;
}


/*
 * add three bits P, Q, and Cin
 * return the carry bit
 */
enum bits fullAdderCarry(enum bits P, enum bits Q, enum bits Cin)
{
// Find and return the carry out of P, Q, and Cin
  enum bits Cout = (Cin & (P^Q)) | (P & Q);
  return Cout;
}