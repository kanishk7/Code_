#include <bits/stdc++.h>
#include <vector> 

using namespace std;

long long int driver(vector<int> ratings)
{
	vector<int> candies(ratings.size());
	candies[0] = 1;

	for(int i = 1; i < ratings.size(); i++)
	{
		if(ratings[i] > ratings[i-1])
			candies[i] = candies[i-1] + 1;
		else
			candies[i] = 1;
	}

	for(int i = ratings.size() - 1; i > 0; i--)
	{
		if(ratings[i-1] > ratings[i] && candies[i-1] <= candies[i])
			candies[i-1] = candies[i] + 1;
	}

	long long int ans = 0;
	for(vector<int>::iterator it = candies.begin(); it != candies.end(); it++)
	{
		ans = ans + *it;
	}

	return ans;
}




int main()
{
	int N; 
	cin >> N;
	vector<int> input;
	while(N--)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	cout << driver(input) << endl;
    return 0;
}