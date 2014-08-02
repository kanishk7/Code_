#include "template.h"

#define inf 99999
#define invalid -1

#define min(a,b) a<b? a:b;

void splitdemo(int** split)
{
	printf("Keep entering nos:");
	while(1)	
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a == 0 || b == 0)
			break;
		printf("split(%d,%d) = %d",a,b,split[a][b]);
	}
	return;	
}


int main()
{
	int m[] = {50,20,1,10,100};
	int n = 4, i,k,j;
	long long int cost = inf;
	//Multiplying matrices of the size 50x20, 20x1, 1x10, 10x100
	
	int C[n+1][n+1];
	int split[n+1][n+1];

	for(i=0; i<=n; i++)	
		for(j=0; j<=n; j++)
			C[i][j] = inf;
	int s = 1;	
	for(i=1; i<=n; i++)
		C[i][i] = 0;
		
	for(s=1; s<n; s++)	
	{
		for(i=1; i<=(n-s); i++)
		{
			j = i+s;
			for(k=i; k<j; k++)
			{
				cost = C[i][k] + C[k+1][j] + m[i-1]*m[k]*m[j];
				printf("Cost at %d,%d,%d = %d + %d + %d = %lld.\n",i,k,j,C[i][k],C[k+1][j],m[i-1]*m[k]*m[j],cost);
				if(C[i][j] > cost)
				{
					if(j == i || j == i+1)
						split[i][j] = invalid;
					else
						split[i][j] = k;
					C[i][j] = cost;
				}
			}
		}
	}
	printf("%d %d.\n",C[1][4], split[1][4]);
	

}

