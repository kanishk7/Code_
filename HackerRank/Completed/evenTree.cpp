// Problem: https://www.hackerrank.com/challenges/even-tree

#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

struct tNode
{
	vector<int> children;
	int parent;
	int size;
};

#define isOdd( num ) ((num) & 1)
#define isEven( num ) (!isOdd( (num) ))


int breakTree(vector<tNode> tree, int index)
{
	int cuts = 0;
	vector<int> children = tree[index].children;

	// For all odd vertices, you may not cut any more edges out at this level. You may not remove an even component because that would 
	// leave this component odd. We will iterator over all children now and ask them to report how many cuts they have. 
	for (vector<int>::iterator it = children.begin(); it != children.end(); it++)
	{
		// One eligible cut here if current node has even size and one child node has even size. 
		if(isEven(tree[*it].size))
		{
			cuts++;
			// printf("Cut here between %d and %d.\n", *it, index);
		}

		cuts = cuts + breakTree(tree, *it); // recurse over children
	}

	return cuts;
}

vector<tNode> addEdge(vector<tNode> tree, int child, int parent)
{
	tree[parent].children.push_back(child);
	tree[child].parent = parent;
	tree[child].size = 1;

	// Incrementing size of all parent nodes by 1 because of addition of this node. 
	do
	{
		tree[parent].size++;
		parent = tree[parent].parent;
	} while(parent != 0);

	return tree;
}

vector<tNode> initTree(int vertices)
{
	vector<tNode> tree(vertices+1);
	tree[1].parent = 0;
	tree[1].size = 1;

	return tree;
}


vector<tNode> parseInput()
{
	int vertices, edges;
	scanf("%d %d", &vertices, &edges);

	vector<tNode> tree = initTree(vertices);

	for(int i = 0; i < edges; i++)
	{
		int child,parent;
		scanf("%d %d", &child, &parent);
		tree = addEdge(tree, child, parent);
	}

	return tree;
}

// Used for debugging.
void printTreeDetails(vector<tNode> tree)
{
	printf("ID\tsize\tparent\tChildren\n");
	for(int i = 0; i < tree.size(); i++)
	{
		printf("%d\t%d\t%d\t", i, tree[i].size, tree[i].parent);

		printf("{");
		for(vector<int>::iterator it = tree[i].children.begin(); it != tree[i].children.end(); it++)
		{
			printf("%d,", *it);
		}
		printf("}\n");
	}
}


void test()
{
	vector<tNode> tree = initTree(10);

	tree = addEdge(tree, 2, 1);
	tree = addEdge(tree, 3, 1);
	tree = addEdge(tree, 4, 3);
	tree = addEdge(tree, 5, 2);
	tree = addEdge(tree, 6, 1);
	tree = addEdge(tree, 7, 2);
	tree = addEdge(tree, 8, 6);
	tree = addEdge(tree, 9, 8);
	tree = addEdge(tree, 10, 8);

	printTreeDetails(tree);
	printf("Cuts = %d.\n", breakTree(tree,1));
}


int main()
{
	//test();
	vector<tNode> tree = parseInput();
	cout << breakTree(tree, 1);

	return 0;
}