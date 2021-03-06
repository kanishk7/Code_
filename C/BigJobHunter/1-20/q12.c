/*
Q12.
Write an one-line C function that determines whether a given number is a power of two or not.
*/

#include "template.h"

/*
Logic:
Any power of 2 will be in the form 1000000...
while that (number-1) will be like 0111111...
Their AND operation will always give a zero. 

What about false positives? No other case will give the same pattern. Think about it. 
*/

int isPowerofTwo(long long int n)
{
	return (n & (n-1))? 0:1;
}

int main()
{
	long long int n = 1;	
	for(n=1; n<=4294967296; n++)
	{
		if(isPowerofTwo(n))
			printf("%lld\n",n);
	}
	return 0;
}
