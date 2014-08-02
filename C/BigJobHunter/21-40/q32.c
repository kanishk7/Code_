//Q 32.
//Write a function so that memory is assigned to a 2 dimensional array using malloc function.
//Hint: First construct a dynamic array at each of the 'rows'



#include "template.h"
#define NUM_ROWS 3
#define NUM_COLUMNS 10
int** matrix;

int main()
{
	matrix = (int**)malloc((NUM_ROWS*sizeof(int *)));
	if(matrix == NULL)
	{
		free(matrix);
		printf("Memory allocation failed. Sorry.\n");
		exit(-1);
	}
	printf("%d %d %d.\n", &matrix[0], &matrix[1], &matrix[2]);
	int i = 0, j;
	for(i=0; i<NUM_ROWS; i++)
	{
		matrix[i] = (int *)malloc(NUM_COLUMNS*sizeof(int));
		if(matrix[i] == NULL)
		{
			free(matrix[i]);
			printf("Memory allocation failed. Sorry.\n");
			exit(-1);
		}
	}
	for(i=0; i<NUM_ROWS; i++)
		for(j=0; j<NUM_COLUMNS; j++)
			matrix[i][j] = rand()%26;

	for(i=0; i<NUM_ROWS; i++)
	{
		for(j=0; j<NUM_COLUMNS; j++)
			printf("%d\t",matrix[i][j]);
		printf("\n");
	}

	for(i=0; i<NUM_ROWS; i++)
		free(matrix[i]);
	free(matrix);



	return 0;
}
