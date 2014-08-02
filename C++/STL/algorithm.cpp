#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

int main()
{
	vector<int> input;

	input.pb(16);
	input.pb(17);
	input.pb(289);
	input.pb(-56);
	input.pb(100);
	input.pb(160);

	vector<int>::iterator found; 

	found = find(input.begin(), input.end(), 1690);
	cout << *found << endl;

	if(found != input.end())
		cout << "Publish non-end value." << endl;


	return 0;
}
