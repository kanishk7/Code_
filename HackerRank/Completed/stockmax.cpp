// Problem: https://www.hackerrank.com/challenges/stockmax

#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

#define max(a,b) a>b?a:b

#define INF 2000000000
#define i64 long long int
#define vvi64 vector<vector<i64> >
#define vvi vector<vector<int> >
#define vi vector<int>
#define vi64 vector<i64>

vvi64 initializeMatrix(int N);

i64 driver(int N, vi64 price)
{
	i64 maxProfit = 0;
	vi64 maxPriceAfterDay(price.size(), 0);	
	for(int i = N-2; i>=0; i--)
	{
		maxPriceAfterDay[i] = max(maxPriceAfterDay[i+1], price[i+1]);
	}

	for(int i = 0; i <= (N-2); i++)
	{
		i64 profit = maxPriceAfterDay[i] - price[i];
		if(profit > 0)
		{
			maxProfit = maxProfit + profit;
			//printf("Day %d: Added %lld profit to %lld maxProfit.\n", i,  profit, maxProfit);
		}
	}

	return maxProfit;
}

int main()
{
	freopen("input00.txt", "r", stdin);
	//freopen("output00.txt", "w", stdout);

	int testCases;
	scanf("%d", &testCases);

	while(testCases--)
	{
		vi64 input;
		int N;
		i64 temp; 
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &temp);
			input.push_back(temp);
		}
		printf("%lld\n", driver(N, input));
	}
	return 0;
}


