// http://www.codechef.com/JUNE14/problems/FORGETPW

#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX_LENGTH 1000003

using namespace std;
static int testCase = 0;

char* trimString(char* input)
{
	int runningIndex = 0, startingIndicesFlag = 0, index = 0;
	char* output = (char *)malloc(MAX_LENGTH);

	for(index = 0; index < strlen(input); index++)
	{
		if(input[index] == '0' && startingIndicesFlag == 0)
			continue;
		startingIndicesFlag = 1;
		output[runningIndex] = input[index];
		runningIndex++;
	}

	index = strlen(output) - 1;
	while(output[index] == '0')
	{
		index--;
	}
	if(output[index] == '.')
	{
		// printf("Trimming side case, last decimal point. Index = %d.\n", index);
		if(index == 0)
		{
			output[index] = '0';
			output[index + 1] = '\0';
		}
		else
			output[index] = '\0';
	}

	output[index + 1] = '\0';

	return output;
}

map<char, char> generateMap()
{
	map<char, char> decryptMap;
	int N;
	scanf("%d", &N);


	char x, y;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		decryptMap[x] = y;
		// printf("Added to map %c, the value %c.\n", x, decryptMap[x]);
	}

	return decryptMap;
}

char* decrypt(char* encrypted, map<char, char> decryptMap)
{
	int length = strlen(encrypted);

	for(int i = 0; i < length; i++)
	{
		map<char, char>::iterator search = decryptMap.find(encrypted[i]);
		if(search != decryptMap.end())
		{
			char decryptedCharacter = decryptMap[encrypted[i]];
			encrypted[i] = decryptedCharacter;
		}
	}
	return encrypted;
}

void driver()
{
	testCase++;
	map<char, char> decryptMap = generateMap();
	
	char input[MAX_LENGTH];
	cin >> input;

	//printf("Input taken for testCase %d: %s\n", testCase, input);
	char* output = decrypt(input, decryptMap);
	//printf("Input decrypted for testCase %d: %s\n", testCase, output);
	output = trimString(output);
	//printf("Input trimmed for testCase %d: %s\n", testCase, output);

	cout << output << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int testCases;
	scanf("%d", &testCases);

	while(testCases--)
	{
		driver();
	}

	return 0;
}