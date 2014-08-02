#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

void initialize()
{
	srand(time(NULL));

}

void experimentVector()
{
	int i;
	vector<int> v(10);
	vector<int>::iterator current = v.begin();
	srand(time(NULL));

	cout << "Printing with loop variable." << endl;
	for(i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 9999;
		cout << v[i] << "\t" <<endl;
	}

	cout << "Printing with iterator." << endl;
	while(current != v.end())
	{
		cout << *current << endl;
		current++;
	}
}

void experimentStack()
{

}

int main()
{
	cout << "Hello World." << endl;
	int i;
	cout << "Starting the experimentVector." << endl;

	experimentVector();
	experimentStack();

	return 0;
}
