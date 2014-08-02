#include <bits/stdc++.h>

using namespace std;

int driver(const char* input)
{
	int L = strlen(input);
	if(L % 2 == 1)
		return -1;

	int mid = L/2, ans = 0;
	vector<int> count(26, 0);

	for(int i = 0; i < mid; i++)
		count[input[i]-'a']++;
	for(int i = mid; i < L; i++)
		count[input[i]-'a']--;
  
	for(int i = 0; i < 26; i++)
	{
		ans = ans + (count[i] > 0? count[i]: 0);
	}

	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	string input;
	int testCases;

	cin >> testCases;
	while(testCases--)
	{
		cin >> input;
		cout << driver(input.c_str()) << endl;
	}

	return 0;
}
