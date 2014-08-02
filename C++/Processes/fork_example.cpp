#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int globalVariable = 2; 

int main()
{
	string sIdentifier;
	int iStackVariable = 20;
	pid_t pID = fork();
	if(pID == 0) //child
	{
		sIdentifier = "Child Process: ";
		globalVariable++;
		iStackVariable++;
	}
	else if(pID < 0) //failed to fork
	{
		cerr << "Failed to fork." << endl;
		return -1;
	}
	else
		sIdentifer = "Parent Process: ";
		
	cout << sIdentifier; 
    cout << " Global variable: " << globalVariable;
    cout << " Stack variable: "  << iStackVariable << endl;	
    
    return 0;
    
}	




