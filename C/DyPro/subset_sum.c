#include "template.h"

void printMat(int m, int n, int p[m][n])
{
	int i,j;
	printf("   ");
	for(i=0; i<m; i++)
		i<10?printf("%d  ",i):printf("%d ",i);
	printf("\n");
	for(i=0; i<m; i++)
		printf("---");
	printf("\n");
	for(i=0; i<m; i++)
	{
		i<10?printf("%d :",i):printf("%d:",i);
		for(j=0; j<n; j++)
			printf("%d| ",p[i][j]);
		printf("\n");
	}
	return;
}


int main()
{
	int A[] = {3,4,17,29,6,2};
	int n = sizeof(A)/sizeof(int);
	int Sum = 100,i,j;
	
	printf("N = %d.\n",n);
	
	short Subset[Sum][n];
	for(i=0; i<Sum; ++i)
	{
		for(j=0; j<n; j++)
		{
			Subset[i][j] = 0;
		}
	}
	Subset[A[0]][0] = 1; 
	
	for(j=1; j<n; j++)
	{
		for(i=0; i<Sum; i++)
		{
			while(i < A[j])
			{
				Subset[i][j] = Subset[i][j-1];
				i++;
			}
			Subset[i][j] = Subset[i-A[j]][j-1] | Subset[i][j-1];
		}		
	}
	
	printf("All possible subset sums are as follows:-\n");
	
	for(i=0; i<Sum; i++)
	{
		for(j=0; j<n; j++)
		{
			if(Subset[i][j] == 1)
			{
				printf("%d\t",i);
				break;
			}
		}
	}
	printf("\n\n");
	
}


