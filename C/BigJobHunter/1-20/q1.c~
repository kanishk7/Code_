/* Q1.

Perform binary search in a 2-D array. Vertices are arranged vertically downwards, e.g - 

The 2-D array is sorted in an unusual way. Consider a sample: 
-------
2 10 18 
4 13 22
6 14 23
7 15 25
-------
Do you see the pattern? It is sorted across all its columns, and then across its rows. 

Consider the 2-D array to have R rows and C columns.
There are 2 algorithms here:-

1. The one suggested in BJH mentions that you should perform binary search on every row. So, take a for loop: run it R number of times and perform a binary search across EVERY row. Time complexity = O(RlogC).

2. The other one is used here and will generally have a complexity of O(log RC). Basically, every 2-D index is converted to an equivalent index in a 1-D array. The algo follows. 

*/

#include "template.h"
#define R 12
#define C 12

static int rows = R;
static int columns = C;
static int variance = 27;

int n(int x, int y)
{
	return x*rows + y;
}

int ninv(int* x, int* y, int index)
{
	*y = index%rows;	
	*x = index/rows;
}

int binarySearch(int b[R][C], int val)
{
	int low,high,mid;
	low = n(0,0);
	high = n(R-1,C-1);
	printf("L = %d H = %d.\n",low,high);
	int xt1, yt1, xt2, yt2;
	while(low < high)
	{
		mid = (int)(low + (high-low)/2);
		//printf("mid updated to %d.\n",mid);
		ninv(&xt1,&yt1,mid);
		printf("%d. %d.",xt1,yt1);
		if(b[xt1][yt1] < val)
		{
			low = mid+1;
		}
		else if(b[xt1][yt1] > val)
		{
			high = mid-1;
		}
		else 
			return mid;
	}

}

void print2Darray(int b[R][C])
{
	int x,y;
	for(y=0; y<columns; y++)
	{
		for(x=0; x<rows; x++)
		{
			printf("%d\t", b[x][y]);
		}
		printf("\n");
	}
	printf("<EOA>\n");
}

void generateSorted2Darray(int b[R][C])
{
	int x,y,prev; 
	prev = rand()%variance + 1;
	for(x=0; x<rows; x++)
	{
		for(y=0; y<columns; y++)
		{
			b[x][y] = prev;
			prev += rand()%variance + 1;
		}
	}
	
}

int main()
{
	int x, y;
	printf("%d.\n",n(3,1));
	ninv(&x, &y, 17);
	printf("17 => (%d,%d).\n", x, y);
	int b[rows][columns];
	generateSorted2Darray(b);
	print2Darray(b);
	ninv(&x, &y, binarySearch(b,56));
	printf("\nCo-ordinates = (%d,%d)\n",x+1,y+1);
	return 0;
}
