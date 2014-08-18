// Problem: http://www.hackerearth.com/problem/algorithm/swapping-game-6/

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

using namespace std;

// Function definitions. 
// Calculates the newIndex of the element at the oldIndex in a String of length strLength
int newIndex(const int oldIndex, const int strLength);

// Calls newIndex a total of K number of times. 
int newIndexMultiple(int oldIndex, const int strLength, const int K);

// Prints (int) vector. 
void printIntegerVector(vector<int> input);

// Returns a vector that contains what the new Index of element i will be. 
vector<int> getNewIndices(int length, const int K);

// Returns original String after K swaps.
string processSwappedString(string input, const int K);

// Calculate the least possible value of K for which the input is equivalent. 
int calculateOptimalK(int strLength, int K);



void test()
{
	printIntegerVector(getNewIndices(7,6));
	printIntegerVector(getNewIndices(8,4));
	printIntegerVector(getNewIndices(9,8));
	printIntegerVector(getNewIndices(10,5));
	printIntegerVector(getNewIndices(22,7));
	printIntegerVector(getNewIndices(35,22));

	int i;
	for(i=5; i<50; i++)
	{
		printf("Repetition is observed in String of L = %d after %d iterations.\n", i, calculateOptimalK(i, 15000));
	}


	string expected = processSwappedString("hrrkhceaate", 3);
	assert (expected == "hackerearth");
	
}

int main()
{
    //test();
	int K; 
	string input; 
	cin >> K;
	cin >> input;
	K = calculateOptimalK(input.length(),K);
	
	cout << processSwappedString(input, K);
	
	return 0;
}

int calculateOptimalK(int strLength, int K)
{
	vector<int> newIndices;
	int iteration;
	int index; 
	int isStringConstant;
	
	for(iteration = 1; iteration < 10000; iteration++)
	{
		isStringConstant = 1; 
		for(index = 1; index < strLength; index++)
		{
			int newIndex = newIndexMultiple(index,strLength,iteration);
			if(newIndex != index)
			{
				isStringConstant = 0; 
				break;
			}
		}
		if(isStringConstant == 1)
		{
			K = K % iteration;
			break;
		}
	}
	return K;
}

// Returns a vector that contains what the new Index of element i will be. 
// e.g. newIndices[2] = 9, indicates that the index that was at 2 is at position 9 after the K swaps. 
// During reconstruction of the original String, we will directly fetch this array and replace index 2 with whaaatever is given at index 9. 
vector<int> getNewIndices(int length, const int K)
{
	vector<int> newIndices(length); 
	newIndices[0] = 0; // The 0th element will stay where it is after K swapping operations. 
	int i = 0; 

	for(i=0; i<length; i++) {
		newIndices[i] = newIndexMultiple(i, length, K); // get New Index.
	}
	
	return newIndices;
	//printIntegerVector(newIndices);
}

string processSwappedString(string input, const int K)
{
	int strLength = input.length();
	vector<int> newIndices = getNewIndices(strLength, K);
	string answer(input);
	int index; 
	
	for(index = 1; index < strLength; index++)
	{
		answer[index] = input[newIndices[index]];
	}

	return answer;
}

// Calculates the newIndex of the element at the oldIndex in a String of length strLength
int newIndex(const int oldIndex, const int strLength)
{
	int output; 
	int median = (strLength/2) + 1;
	if(strLength % 2 == 0)
		median = strLength/2;
	
	if(oldIndex >= median)
		return (strLength*2) - (oldIndex*2) - 1;
	else
		return (oldIndex*2);
}

int newIndexMultiple(int oldIndex, const int strLength, const int K)
{
	int i;
	int median = (strLength/2) + 1;
	if(strLength % 2 == 0)
		median = strLength/2;

	for(i=0; i<K; i++) 
	{
		if (oldIndex >= median)
			oldIndex = (strLength*2) - (oldIndex*2) - 1;
		else
			oldIndex = oldIndex * 2;
	}
	
	return oldIndex;
}

void printIntegerVector(vector<int> input)
{
	for(vector<int>::iterator i = input.begin(); i != input.end(); i++)
		cout << *i << ' ';
	printf("\n");
}

