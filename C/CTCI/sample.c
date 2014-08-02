#include "stdio.h"

void printMat(int n, int a[n][n])
{
	int i,j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)	
			printf("%d ",a[i][j]);	
		printf("\n");
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int n,i,j,temp,temp2;
	scanf("%d",&n);
	int a[n][n];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)	
			scanf("%d",&a[i][j]);
	printMat(n,a);
	
	printf("\n\n\n\n");
	
	for(i=0; i<(int)(n/2); i++)
	{
		for(j=0; j<(int)(n/2); j++)
		{
			temp = a[i][j];
			a[i][j] = a[n-i-1][j];
			temp2 = a[i][n-j-1];
			a[i][n-j-1] = temp;
			temp = a[n-i-1][n-j-1];
			a[n-i-1][n-j-1] = temp2;
			a[n-i-1][j] = temp;
		}	
	}
			
	printMat(n,a);
			
	return 0;	
}


