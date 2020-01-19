/* Eyosias Kibe */
#include <stdio.h>
#include <math.h>
#define NUM 4
#define MAX 1024
struct Point
{
    int x;
    int y;
};

unsigned id1, id2;
unsigned dist, cnt1, cnt2;
/* Calculate the distance between two points */
unsigned distance(struct Point* p1, struct Point* p2)
{
    return sqrt(((*p1).x - (*p2).x)*((*p1).x - (*p2).x) 
    	    + ((*p1).y - (*p2).y)*((*p1).y - (*p2).y));
}
/* Find the nearest point to the query point. */
int nearst(struct Point pairs[], int n){
	dist = MAX;
	 cnt1 = 0; cnt2 = 0;
	id1 = 0; id2 = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
        {
        int update = distance(&pairs[i], &pairs[j]);
        if (update < dist) {
    		id1 = i; id2 = j; 
        	dist = update;
        }
      }
 
	}

	/* count the index of the nearst points. */
	for (int i = 1; i <= n; ++i)
	{
		if (pairs[id2].x == pairs[i - 1].x && 
			pairs[id2].y == pairs[i - 1].y)
		{
			cnt1  = id1 + 1;
			cnt2 = id2 + 1;
		}  
	}
	return cnt2;
}

int main(void)
{	
    struct Point pairs[NUM];

    for (int i = 0; i < NUM; i++)
    {
    	// Enter all points
        printf("Enter P%d (x, y): ", i + 1);
        scanf("%d %d", &pairs[i].x, &pairs[i].y);
    }
	int point = nearst(pairs, NUM);
	// The distance between 
	
    printf("The closest points pair: P%d and P%d @ (%d, %d) and (%d, %d)\n" , 
    														cnt1, cnt2,
														    pairs[id1].x, 
    														pairs[id1].y, 
    														pairs[id2].x, 
    														pairs[id2].y);
    printf("The distance between closest points pair\n");
    printf("P%d and P%d is: %d\n", cnt1, cnt2, dist);
	printf("point \'P%d\' is nearest to the query point \'P%d\'\n", point, cnt1);

    return 0;
}