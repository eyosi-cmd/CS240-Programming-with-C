/* write comments here
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

static int compareP(const void *a, const void *b) {
  point *pa, *pb;
  pa = (point*) a;
  pb = (point*) b;
  if (pa->y < pb->y) return -1;
  if (pa->y > pb->y) return 1;
  return 0;
}


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

static double crossP(point *pa, point *pb, point *pc)
{
  double value =  (pb->x - pa->x) * (pc->y - pa->y) -
                    (pc->x - pa->x) * (pb->y - pa->y);
    if(value > 0) return -1;
  else if (value < 0) return 1;
  else return 0;

}
/*static int ccw(const void *a, const void *b, const void *c) {
 point *pa, *pb, *pc;
  pa = (point*) a;
  pb = (point*) b;
  pc = (point*) c;
  
  if(crossP(pa, pb, pc) < 0) return -1;
  else if (crossP(pa, pb, pc) < 0) return 1;
  else return 0;
}*/
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
   //setting max y to point A
  pa->y = ycords[n-1]; 

  
  //matching that y to x of point A
  for (int i = 0; i < n; i++) {
    if (dataSet[i].y == pa->y) {
       pa->x = dataSet[i].x;
       top++;
    }     
  } 
  //at this point we have A
  //shifting points starting with B 
    
  for (int i = 1; i < n; i++) {
  if (dataSet[i].x == pa->x && dataSet[i].y == pa->y){
      dataSet[i].x = 0.0;
      dataSet[i].y = 0.0;
  } 
    dataSet[i].x = dataSet[i].x - pa->x;
    dataSet[i].y = dataSet[i].y - pa->y;
    to  
  }
  
   //sorted array of points
  qsort(dataSet, n, sizeof(point), compareDeg);
  point *pc;

  for (int i = 0; i < n - 1; i++) {
    point A = dataSet[i];
    point B = dataSet[i+1];
    point C = dataSet[top];
    pa = &A;
    pb = &B;
    pc = &C;   
  }
   // qsort(dataSet, n, sizeof(point), ccw);
    if (crossP(pa,pb,pc) < 0) {         
      for (int i = 2; i < n; i++) {
        dataSet[i].x = dataSet[i].x - (pb->x);
      dataSet[i].y = dataSet[i].y - pb->y;
      }
    }
   
  //printing
   
  //int ch_size = sizeof(point) -1;
  printf("Out of %u points, %d vertices are on the convex hull\n", 
   n, top);
  
  for (int i = 0; i < n-1; i++) { 
    printf("%c (%lf, %lf)\n", ('A' + i),
     dataSet[i].x, dataSet[i].y);     
  }
}