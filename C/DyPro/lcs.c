/*
Q.

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.

It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

*/

#include "template.h"
#define max(a,b) a>b? a:b;
#define size 10

void printMat(int p[size+1][size+1])
{
	int i,j;
	printf("   ");
	for(i=0; i<=size; i++)
		i<10?printf("%d  ",i):printf("%d ",i);
	printf("\n");
	for(i=0; i<=size; i++)
		printf("---");
	printf("\n");
	for(i=0; i<=size; i++)
	{
		i<10?printf("%d :",i):printf("%d:",i);
		for(j=0; j<=size; j++)
			printf("%d| ",p[i][j]);
		printf("\n");
	}
	return;
}


void rand_s(int length, char *s)
{
    srand(time(NULL));
    int i;
    char a[length];
    for(i=0; i<length; i++)
    {
        a[i] = (char)(rand()%26 + 97);
    }
    strcpy(s,a);
    s[length] = '\0';
}

int main()
{
	int i,j,k;
	char s1[size];
	char s2[size];
	int L[size+1][size+1];
//	rand_s(size,s1);
//	rand_s(size,s2);
	strcpy(s1,"abcklipqrz");
	strcpy(s2,"cklirabdez");
	printf("String 1 = %s.\n",s1);
	printf("String 2 = %s.\n",s2);
	
	for(i=0; i<=size; i++)
	{
		for(j=0; j<=size; j++)
		{
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
		}
	}
	
	printMat(L);
	
	return 0;

}
