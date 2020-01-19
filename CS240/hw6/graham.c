/* name: Eyosias Kibe
 * date: 07/26/2019
 * user:
 * assignment: hw6
 * file: graham.c
 * Pseudocode: 1. Sorting the array of y-ccordinates to get the maxium point.
               2. Sorting all points in the array setData with their angles.
               3. choose points of convex hull based on left or right turns
                 and return positive +1 for left turns and negative -1 
                 for right turns.
               4. use quick sort to sort points by points, ccw, and angles.
               5. use a stack of points to print from the top of stack to bottom. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

/* compare y cordinates of a and b
 * return either +1, -1 , or zero
 */

static int compareP(const void *a, const void *b) {
  point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;
  if (pa->y < pb->y) return -1;
  if (pa->y > pb->y) return 1;
  return 0;
}
/* find the angle between points
 * compare the the angles between point a and b
 * return -1 if the angle on a is less than on b
 * return +1 if the angle on a is greater than on b
 * else return zero
 */

static int compareDeg(const void *a, const void *b) {
 double angleA, angleB;
  point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;         
  
  angleA = atan(pa->y/pa->x);
  angleB = atan(pb->y/pb->x);     

  if (angleA < angleB) return -1; 
  if (angleA > angleB) return 1;
  return 0;
}
// calculate a cross products of points
static double crossP(point *pa, point *pb, point *pc)
{
  double value =  (pb->x - pa->x) * (pc->y - pa->y) -
                    (pc->x - pa->x) * (pb->y - pa->y);
    if(value > 0) return 1;
  else if (value < 0) return -1;
  else return 0;

}
/* return +1 if the the cross product values of points is positive
 * return -1 if its negative
 * else return zero
 */
point *pc;
static int ccw(const void *a, const void *b, const void *c) {
 point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;
  pc = (point*) c;
  
  if(crossP(pa, pb, pc) < 0) return -1;
  else if (crossP(pa, pb, pc) > 0) return 1;
  else return 0;
}
static int compareCCW(const void *a, const void *b) {
 point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;
  
  if(ccw(pa, pb, pc) < 0) return -1;
  else if (ccw(pa, pb, pc) > 0) return 1;
  else return 0;     

}

/* implement Graham's scan
 * at the end of this function, before returning to main()
 * you should print the vertices of the convex hull counterclockwise
 * starting from the vertex with the largest y-coordinate
 */
void graham(point dataSet[], unsigned n)
{
  /* print the number of vertices on the hull
   * print x- and y-coordinates of the vertices labeled with A, B, C, etc
   */
  
  //making array of y-coordinates of all points
  double * ycords = (double *) malloc(sizeof(double) * n);
  for (int i = 0; i < n; i++) 
      ycords[i] = dataSet[i].y;

 qsort(ycords, sizeof(ycords), sizeof(double),
     compareP);
  int top = 2;
  point A, B;
  point *pa = &A;
  point *pb = &B;
   //set the maxium values y in point A
  pa->y = ycords[n-1]; 

  
  //matching that y to x of point A
  for (int i = 0; i < n; i++) {
    if (dataSet[i].y == pa->y) {
       pa->x = dataSet[i].x;
       top++;
    }     
  } 

  /* shift points from B to A.
   * if x and y of point A are
   * equal set x and y to orgins.
   * or sets vertex with highest y
   * value positioned at (0,0)
   */
  for (int i = 1; i < n; i++) {
  if (dataSet[i].x == pa->x && dataSet[i].y == pa->y){
     /* set vertex with highest points 
      * y values a (0,0)
      */
      dataSet[i].x = 0.0;
      dataSet[i].y = 0.0;
  } 
    dataSet[i].x = dataSet[i].x - pa->x;
    dataSet[i].y = dataSet[i].y - pa->y; 
  }
  
  //A sorted array of point A, B, and Cs.
  qsort(dataSet, n, sizeof(point), compareDeg);
  point *pc;

 /* use a stack of array 
  * to arrange points in the data.
  */
  for (int i = 0; i < n - 1; i++) {
    point A = dataSet[i];
    point B = dataSet[i+1];
    point C = dataSet[top];
    pa = &A;
    pb = &B;
    pc = &C;
  
  }
  /* check if ccw of point a, b, c 
   * is less than zero to check
   * if it turns to right, left or 
   * neither. if it goes to right 
   * sort the array again
   */
    if (ccw(pa,pb,pc) < 0) {         
      for (int i = 2; i < n; i++) {
        crossP(pa,pb,pc); 
        dataSet[i].x = dataSet[i].x - (pb->x);
        dataSet[i].y = dataSet[i].y - pb->y;
         qsort(dataSet, n, sizeof(point), compareCCW);
      }
    }
  /* Final output of data in the stack */
  printf("Out of %u points, %d vertices are on the convex hull\n", 
   n, top);
  
  for (int i = 0; i < n-1; i++) { 
    printf("%c (% lf, % lf)\n", ('A' + i),
     dataSet[i].x, dataSet[i].y);     
  }
}