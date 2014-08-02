// Problem: https://www.hackerrank.com/challenges/beadornaments

#include <vector>
#include <algorithm>
#include <iostream>

#define u64 unsigned long long int
#define i64 long long int
#define mod 1000000007

using namespace std;

i64 multiply(i64 a, i64 b)
{
	i64 rem1 = a % mod;
	i64 rem2 = b % mod;
	return (rem1 * rem2) % mod;
}

i64 exponent(i64 base, i64 power)
{
	power = (power) % (mod - 1); // from Fermat's little theorem
	i64 result = multiply(base, base);
	for(int i = 2; i < power; i++)
	{	
		result = multiply(base, result);
	}
	return result;
}

i64 addition(i64 a, i64 b)
{
	i64 rem1 = a % mod;
	i64 rem2 = b % mod;
	return (rem1 + rem2) % mod;
}

i64 cayleyFormula(i64 n)
{
	if(n == 1 || n == 2)
		return 1;
	return exponent(n, n-2);
}

/*

Idea. 

The number of ways a graph of K connected components, with each connected 'i' of size s[i] can be ennumerated is by the formula
(N ^ (K-2)) * (S[1] * S[2] * ... * S[k])

We will multiply this by the number of ways an internal component can be 

*/

i64 driver(i64 n, vector<i64> beads)
{
	i64 sum = 0, result = 1;
	for(int i = 0; i < beads.size(); i++)
	{
		result = multiply(result, beads[i]);
		result = multiply(result, cayleyFormula(beads[i]));
		sum = sum + beads[i];
	}
	result = multiply(result, exponent(sum, n-2));
	return result;
}

int main()
{
	int testCases;
	scanf("%d",&testCases);
	while(testCases--)
	{
		int n;
		scanf("%d", &n);
		vector<long long int> input(n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lld", &input[i]);
		}

        printf("%lld\n", driver(n, input));
	}

	return 0;
}
