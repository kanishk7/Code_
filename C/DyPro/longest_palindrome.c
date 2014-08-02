#include "template.h"

/*
Q. Find the longest palindrome in a given String.

A subsequence is palindromic if it is the same whether read left to right or right to left. For instance, the sequence
ACGCATGTCAAAATCG
has many palindromic subsequences, including A;C;G;C;A and A; A; A;A (on the other hand, the subsequence A;C; T is not palindromic). Devise an algorithm that takes a sequence x[1 : : : n]
and returns the (length of the) longest palindromic subsequence. Its running time should be O(n^2).
*/

void printMat(int p[20][20])
{
	int i,j;
	printf("   ");
	for(i=0; i<20; i++)
		i<10?printf("%d  ",i):printf("%d ",i);
	printf("\n");
	for(i=0; i<20; i++)
		printf("---");
	printf("\n");
	for(i=0; i<20; i++)
	{
		i<10?printf("%d :",i):printf("%d:",i);
		for(j=0; j<20; j++)
			printf("%d| ",p[i][j]);
		printf("\n");
	}
	return;
}

void printS(char *s, int a, int b)
{
	for(; a<=b; a++)
	{
		printf("%c",s[a]);
	}
	printf("\n");
	return;
}

int main()
{
	char s[20];
	strcpy(s,"madamimadam");
	printf("Original String: %s.\n",s);
	printf("Palindromes of length greater than/equal to 3:-\n");
	int p[20][20];
	int i,j,si;
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)	
			p[i][j] = 0;
			
	for(i=0; i<19; i++)
	{
		p[i][i] = 1;
		if(s[i] == s[i+1])
		{
			p[i][i+1] = 1;
		}
	}

	for(si=2; si<=19; si++)	
	{
		for(i=0; i<(19-si); i++)
		{
//..considering the values of p[i][i+si]
			if(p[i+1][i+si-1])
				if(s[i] == s[i+si])
					p[i][i+si] = 1;
		}
	}
	
	for(i=0; i<19; i++)
		for(j=0; j<19; j++)
		{
			if(p[i][j] && (j-i >= 2))
			{
				printf("%d-%d:",i,j);
				printS(s,i,j);
			}
		}
	//printMat(p);
	return 0;
}
