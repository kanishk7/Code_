// Problem: http://www.codechef.com/JAN14/problems/ERROR

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int testCases;

	scanf("%d", &testCases);

	char input[100003];
	gets(input);
	while(testCases--)
	{
		gets(input);
		int L = strlen(input), flag = 0;
		for(int i = 0; i < (L-2); i++)
		{
			if(input[i] == input[i+2] && input[i] != input[i+1])
			{
				flag = 1;
				break;
			}
		}

		cout << (flag? "Good": "Bad") << endl;
	}

	return 0;
}