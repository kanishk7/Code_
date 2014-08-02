#include "treedef.h"

int main()
{
	BsTree t = Init_BSTree();
	int i = 0;
	srand(145);
	
	for(i=0; i<50; i++)
		BSTinsert(t, rand()%200);

	//traverse(t);
	int S = 75;
	
	for(S = 75; S<125; S++)
	{
		printf("%d: %d\n",S,printSumPair(t,S));
	}

	//BstDestroy(t);
	return 0;
}

