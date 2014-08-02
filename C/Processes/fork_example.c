#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int globalVariable = 2; 

int main()
{
	printf("I do come here.\n");
	char sId[20];
	int iStackVariable = 20;
	pid_t pID = fork();
	if(pID == 0) //child
	{
		strcpy(sId,"Child Process.");
		globalVariable++;
		iStackVariable++;
	}
	else if(pID < 0) //failed to fork
	{
		printf("Failed to fork.\n");
		return -1;
	}
	else if(pID > 0)
		strcpy(sId,"Parent Process.");
		
	printf("Name of the process: %s. and Id = %d.\n",sId,(int)pID); 
    printf("Global variable: %d.\n", globalVariable);
	printf("Stack variable: %d.\n",iStackVariable);
    if(pID != 0)
    	getchar();
    
    
    return 0;
    
}	




