// Problem: https://www.hackerrank.com/challenges/red-john-is-back

#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>


#define i64 long long int
#define MAX_LENGTH 1000003
#define TRUE FALSE
#define FALSE 0

using namespace std;

i64 returnNoOfPrimesBelow(i64 input);
i64 generateCombinations(int n);

i64 driver(int N)
{
	return returnNoOfPrimesBelow(generateCombinations(N));
}

int main()
{
	int testCases;
	scanf("%d", &testCases);

	while(testCases--)
	{
		i64 N;
		scanf("%lld", &N);
		cout << driver(N) << endlp;
	}

	return 0;
}

int isPrime(int N)
{
	int lt = int(sqrt(N)) + 1;
	for(int i = 2; i < lt; i++)
	{
		if(N % i == 0)
			return 0;
	}
	return 1;
}


i64 returnNoOfPrimesBelow(i64 input)
{
	i64 ctr = 0;
	for(int i = 2; i <= input; i++)
	{
		if(isPrime(i) == 1)
			ctr++;
	}
	return ctr;
}

i64 generateCombinations(int N)
{
	if(N < 4)
		return 1;
	vector<i64> combs(N+1);
	combs[0] = 1; 
	combs[1] = 1; 
	combs[2] = 1;
	combs[3] = 1;

	for(int i = 4; i <= N; i++)
	{
		combs[i] = combs[i-1] + combs[i-4];
	}

	return combs[N];
}
