// Problem: https://www.hackerrank.com/challenges/the-quickest-way-up

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define BOARD_SIZE 100
#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

vector<int> generateBoardMoves(vector<int> board);
vector<int> accountForSnakesAndLadders(vector<int> board, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders);
int minElementInVector(vector<int> input);
void printBoard(vector<int> board);
void printSnakes(vector<pair<int, int> > snakes);
void printLadders(vector<pair<int, int> > ladders);


void driver()
{
	vector<int> board(BOARD_SIZE, 2000);
	board[0] = 0;
	board = generateBoardMoves(board);

	int nSnakes, nLadders;
	scanf("%d,%d", &nLadders, &nSnakes);
	vector<pair<int, int> > snakes;
	vector<pair<int, int> > ladders;

	while(nLadders--)
	{
		int x,y;
		scanf("%d,%d", &x, &y);
		ladders.push_back(make_pair(x, y));
		//printf("Pushing %d %d to ladders.\n", x, y);
	}

	while(nSnakes--)
	{
		int x,y;
		scanf("%d,%d", &x, &y);
		snakes.push_back(make_pair(x, y));
		//printf("Pushing %d %d to snakes.\n", x, y);
	}

	board = accountForSnakesAndLadders(board, snakes, ladders);
	board = generateBoardMoves(board);
	board = accountForSnakesAndLadders(board, snakes, ladders);
	board = generateBoardMoves(board);

	cout << board[99] << endl;
	//printBoard(board);
}

int main()
{
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int testCases;
	scanf("%d", &testCases);
	while(testCases--)
	{
		driver();
	}

	return 0;
}

vector<int> generateBoardMoves(vector<int> board)
{
	for(int i = 1; i < BOARD_SIZE; i++)
	{
		vector<int> minimumMovesBefore;
		for(int j = i - 1; j >= 0 && j >= (i - 6); j--)
		{
			minimumMovesBefore.push_back(board[j]);
		}
		board[i] = min(minElementInVector(minimumMovesBefore) + 1, board[i]);
	}
	return board;
}

void printBoard(vector<int> board)
{
	for(int i=0; i<100; i++)
	{
		printf("%d\t%d\n", i, board[i]);
	}
	return;
}

int minElementInVector(vector<int> input)
{
	int min = input[0];
	for(int i = 0; i < input.size(); i++)
	{
		if(min > input[i])
			min = input[i];
	}
	return min;
}

vector<int> accountForSnakesAndLadders(vector<int> board, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders)
{
	for(int i = 0; i < snakes.size(); i++)	
	{
		int lowerValue = min(board[snakes[i].first], board[snakes[i].second]);
		board[snakes[i].second] = lowerValue;
		
		//printf("(SNAKE) board[%d], board[%d] is now = %d (verify = %d).\n", snakes[i].first, snakes[i].second, lowerValue, board[snakes[i].second]);
	}

	for(int i = 0; i < ladders.size(); i++)	
	{
		board[ladders[i].second] = min(board[ladders[i].first], board[ladders[i].second]);
		//printf("(LADDER) board[%d], board[%d] is now = %d.\n", ladders[i].first, ladders[i].second, board[ladders[i].second]);
	}

	return board;
}

void printSnakes(vector<pair<int, int> > snakes)
{
	printf("Snakes.\n");
	for(int i = 0; i < snakes.size(); i++)
	{
		printf("(%d %d)\n", snakes[i].first, snakes[i].second);
	}
}

void printLadders(vector<pair<int, int> > ladders)
{
	printf("Ladders.\n");
	for(int i = 0; i < ladders.size(); i++)
	{
		printf("(%d %d)\n", ladders[i].first, ladders[i].second);
	}
}
