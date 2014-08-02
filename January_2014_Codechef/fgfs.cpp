// http://www.codechef.com/JAN14/problems/FGFS

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

void print(vector<pair<int, int> > compartment, int K);
bool compareBySecondElement(const pair<int, int>& pairOne, const pair<int, int>& pairTwo);

int driver(map<int, vector<pair<int, int> > > customerTimes)
{
	int count = 0;
	for(int i = 0; i < customerTimes.size(); i++)
	{
		vector<pair<int, int> > current = customerTimes[i];
		if(current.size() == 0)
			continue;
		sort(current.begin(), current.end(), compareBySecondElement);
		//print(current, i);
		int last = current[0].second;
		count++;
		for(int j = 1; j < current.size(); j++)
		{
			if(current[j].first >= last)
			{
				last = current[i].second;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T, N, K, st, ft;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		map<int, vector<pair<int, int> > > customerTimesForCompartment(K+1);
		for(int i = 0; i < N; i++)
		{
			int t;
			scanf("%d %d %d", &st, &ft, &t);
			customerTimesForCompartment[t].push_back(make_pair(st, ft));
		}
		cout << driver(customerTimesForCompartment) << endl;
	}

	return 0;
}

void print(vector<pair<int, int> > compartment, int K)
{
	printf("Compartment output %d.\n", K);
	printf("No.\tst\tft\n", K);
	for(int i = 0; i < compartment.size(); i++)
	{
		printf("%d\t%d\t%d\n", i, compartment[i].first,  compartment[i].second);
	}
}

bool compareBySecondElement(const pair<int, int>& pairOne, const pair<int, int>& pairTwo)
{
	return pairOne.second < pairTwo.second;
}