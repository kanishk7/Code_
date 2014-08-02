
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define LENGTHMAX 101

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int testCases;
	scanf("%d", &testCases);
	while(testCases--)
	{
		char* s;g
		char key[] = "aeiou";
		scanf("%s", s);
		int length = strlen(s);
		int vowelCtr = -1;

		char* vowelPtr;
		vowelPtr = strpbrk(s, key);
		if(vowelPtr != NULL)
		{
			while(vowelPtr != NULL)
			{
				vowelCtr++;
				vowelPtr = strpbrk(vowelPtr+1, key);
			}
		}

		cout << length - vowelCtr - 4 << "/" << length << endl;
	}

	return 0;
}