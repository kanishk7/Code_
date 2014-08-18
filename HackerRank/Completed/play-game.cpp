// Problem: https://www.hackerrank.com/challenges/play-game
/* 

Logic:

Let the stack be of N bricks. We will represent this with array input. 
input[0] is the bottommost brick of the stack. and input[length - 1] is the topmost.

Let there be a preset value array "Score" of length N that determines the following. 
=> Score[i] = Score of the player who gets to choose first of the i sub-bricks left in the stack.

It follows that,
Score[0] = input[0];
Score[1] = input[1];
Score[2] = input[2];

Now given we have Score[0]..Score[i-1],
we have the following strategy:

If you choose the ith brick only.. 
then next player will get Score[i-1], therefore current player score = {Sum[i] - Score[i-1]}  - [a]

If you choose 2 bricks, ith and (i-1)th..
then next player will get Score[i-1], therefore current player score = {Sum[i] - Score[i-2]}  - [a]

If you choose 3 bricks, ith and (i-1)th and (i-2)..
then next player will get Score[i-1], therefore current player score = {Sum[i] - Score[i-3]}  - [a]

Therefore, Score[i] = max([a], [b], [c]).
Solve bottoms-up. :) 

*/

#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define MAX_LENGTH 1000003
#define i64 long long int
using namespace std;
static i64 testCase = 0;

i64 computeMaxScore(vector<i64> input, vector<i64> sum);
vector<i64> precomputeSum(vector<i64> input);

i64 driver(vector<i64> input)
{
	vector<i64> sum = precomputeSum(input);
	return computeMaxScore(input, sum);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	i64 testCases;
	scanf("%lld",&testCases);
	while(testCases--)
	{
		i64 length;
		scanf("%lld",&length);
		vector<i64> input(length);
		for(i64 i = 0; i < length; i++)
		{
			i64 val;
			scanf("%lld", &val);
			input[length - (i+1)] = val;
		}
		cout << driver(input) << endl;
	}
	return 0;
}

i64 min3(i64 a, i64 b, i64 c);

i64 computeMaxScore(vector<i64> input, vector<i64> sum)
{
	i64 n = input.size();
	vector<i64> Score(n);
	for(i64 i = 0; i < 3 && i < n; i++)
		Score[i] = sum[i];

	if(n >= 3)
	{
		for(i64 i = 3; i < n; i++)
			Score[i] = sum[i] - min3(Score[i-1], Score[i-2], Score[i-3]);
	}

	return Score[n-1];
}

vector<i64> precomputeSum(vector<i64> input)
{
	i64 n = input.size();
	vector<i64> sum(n);

	sum[0] = input[0];
	for(i64 i = 1; i < n; i++)
	{
		sum[i] = sum[i-1] + input[i];
	}

	return sum;
}

i64 min3(i64 a, i64 b, i64 c)
{
	if(a < b)
		if(a < c)
			return a;
		else
			return c;

	return b < c? b: c;
}