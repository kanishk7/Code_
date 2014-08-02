// Problem: http://www.codechef.com/JUNE14/problems/DIGJUMP

#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// Used for debugging.
void printGraphDetails(vector<vector<int> > graph, string input);


vector<vector<int> > addEdge(int from, int to, vector<vector<int> > vertexAt)
{
	if(find(vertexAt[from].begin(), vertexAt[from].end(), to) == vertexAt[from].end())
		vertexAt[from].push_back(to);

	if(find(vertexAt[to].begin(), vertexAt[to].end(), from) == vertexAt[to].end())
		vertexAt[to].push_back(from);

	return vertexAt;
}

vector<vector<int> > populateGraph(string input)
{
	vector<vector<int> > graph(input.length() + 1);
	for(int i = 0; i < input.length(); i++)
	{
		char runningCharacter = input[i];
		if(i == 0)
		{
			graph = addEdge(0, 1, graph);
		}
		else if(i == input.length() - 1)
		{
			graph = addEdge(i, i-1, graph);
		}
		else
		{
			graph = addEdge(i, i-1, graph);
			graph = addEdge(i, i+1, graph);
		}

		for(int j = i + 1; j < input.length(); j++)
		{
			if(runningCharacter == input[j])	
				graph = addEdge(i, j, graph);
		}
	}
	return graph;
}

int performBFS(vector<vector<int> > graph, int source, int target)
{
	vector<int> visited(graph.size());
	for(int i=0; i < graph.size(); i++)
		visited[i] = 0;
	queue<int> bfsQueue;
	int turns = 0, found = 0, EOT_flag = -127, current = 0;

	bfsQueue.push(source);
	bfsQueue.push(EOT_flag);
	while(!bfsQueue.empty())
	{
		current = bfsQueue.front();
		// printf("Performing BFS on node %d at turn %d.\n", current, turns);
		bfsQueue.pop();

		if(current == target)
			return turns;

		if(current == EOT_flag)
		{
			turns++;
			if(bfsQueue.empty()) // no unvisited unreachable nodes.
				break;
			bfsQueue.push(EOT_flag);
			continue;
		}
		if(visited[current] == 0)
		{
			visited[current] = 1;
			for(vector<int>::iterator it = graph[current].begin(); it != graph[current].end(); it++)
			{
				// printf("Trying to add %d to %d's BFS traversal.\n", *it, current);
				if(visited[*it] < 1)
					bfsQueue.push(*it);
			}
		}
	}

	return turns;
}

void test()
{
	vector<vector<int> > graph(20);
	string testString = "01234567890";
	graph = populateGraph(testString);
	// printGraphDetails(graph, testString);
	cout << performBFS(graph, 0, testString.length() - 1) << endl;
}

void driver(string testString)
{
	vector<vector<int> > graph(testString.length());
	graph = populateGraph(testString);
	cout << performBFS(graph, 0, testString.length() - 1) << endl;
}

void setupDummyInput()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

int main()
{
	//test();
	//setupDummyInput();
	string input;
	cin >> input;
	driver(input);
	return 0;
}

// Used for debugging.
void printGraphDetails(vector<vector<int> > graph, string input)
{
	printf("ID/C\tEdge To\n");
	for(int i = 0; i < graph.size(); i++)
	{
		printf("%d|%c\t", i, input[i]);

		printf("{");
		for(vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
		{
			printf("%d,", *it);
		}
		printf("}\n", input[i]);
	}
}

