// Problem: http://www.codechef.com/problems/MTRICK

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

#define uint64 unsigned long long int

void driver(vector<unsigned long long int> input, char* str, uint64 A, uint64 B, uint64 C, int N)
{
	vector<int> countA(N), countB(N), countC(N);
	int L = strlen(str);
	for(int i = 0; i < L; i++)
	{

	}
}




int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		uint64 A, B, C;
		scanf("%d", &N);
		vector<uint64> input(N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &input[i]);
		}
		scanf("%llu %llu %llu", &A, &B, &C);
		char str[N+1];
		gets(str);

		driver(input, str, A, B, C, N);
	}

	return 0;
}
