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

void driver(vector<unsigned long long int> input, string str, uint64 A, uint64 B, uint64 C, int N)
{
	printf("\nA = %llu. B = %llu. C = %llu. str = %s.\n", A, B, C, str.c_str());
	vector<int> countA(N, 0), countR(N, 0), countM(N, 0);
	int L = str.size();

	if(str[0] == 'R')
		countR[0] = 1;
	else if(str[0] == 'A')
		countA[0] = 1;
	else
		countM[0] = 1;

	for(int i = 1; i < L; i++)
	{
		switch(str[i])
		{
			case 'A':
			{
				countA[i] = countA[i-1] + 1;
				countR[i] = countR[i-1];
				countM[i] = countM[i-1];
				break;
			}
			case 'R':
			{
				countA[i] = countA[i-1];
				countR[i] = countR[i-1] + 1;
				countM[i] = countM[i-1];
				break;
			}
			case 'M':
			{
				countA[i] = countA[i-1];
				countR[i] = countR[i-1];
				countM[i] = countM[i-1] + 1;
				break;
			}
			default:
				break;
		}
	}
	printf("%d %d %d %d.\n", countA[1], countA[2], countR[2], countM[2]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		uint64 A, B, C;
		scanf("%d", &N);
		printf("Took N = %d.\n", N);
		vector<uint64> input(N);
		for(int i = 0; i < N; i++)
		{
			scanf("%llu", &input[i]);
			printf("%llu", input[i]);
		}
		scanf("%llu %llu %llu", &A, &B, &C);
		string str;
		cin >> str;
		//printf("A = %d. B = %d. C = %d. str = %s.\n", A, B, C, str);
		driver(input, str, A, B, C, N);
	}

	return 0;
}
