#include <stdio.h>
#define ROW 3
#define COL 3
void martrixInput(int mat[ROW][COL]);
void martrixPrint(int mat[ROW][COL]);
void martrixMultiply(int mat1[ROW][COL], int mat2[ROW][COL], int res[ROW][COL]);
int main(int argc, char const *argv[])
{
	int mat1[ROW][COL];
	int mat2[ROW][COL];
	int product[ROW][COL];
	
	
	return 0;
}
void martrixInput(int mat[ROW][COL]){
	int row, col;
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; j < COL; ++col)
		{
			scanf("%d", (*(mat + row) + col));
		}
	}

void martrixPrint(int mat[ROW][COL]){
	int row, col;
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
		{
			printf("%d", *(*(mat + row) + col));
		}
		printf("\n");
	}
}
void martrixMultiply(int mat1[ROW][COL], int mat2[ROW][COL], int res[ROW][COL]){
	int row, col, i;
	int sum;
 for (row = 0; row < ROW; ++row)
 {
 	for (i = 0; i < COL; ++col)
 	{
 		sum = 0;
 		for (i = 0; i < COL; ++i)
 		{
 			sum += *(*(mat1 + row) + i)*(*(*(mat2 + row) + col));
 		}
 		 *(*(res + row) + col) = sum;
 	}
 }

}