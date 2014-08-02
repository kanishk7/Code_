#include "LinkedListDef.h"

Node initLL()
{
	Node n = (Node)malloc(sizeof(struct node));
	n->value = -999;
	n->next = NULL;
	return n;
}

Node inserttoLL(Node n, int val)
{
	if(n->value == -999)
	{
		n->value = val;
		n->next = NULL;
		return n;
	}
	Node temp = (Node)malloc(sizeof(struct node));
	temp->value = val;
	temp->next = NULL;
	while(n->next)
		n = n->next;
	n->next = temp;
	return temp;
}

void printLL(Node n)
{
	if(n)
		printf("%d\t",n->value);
	else
	{
		printf("Empty List.\n");
		return;
	}
	while(n->next)
	{
		printf("%d\t",n->next->value);
		n = n->next;
	}
	printf("<EOLL>\n");
}

void destroyLL(Node n)
{
	if(!n)
		return;
	Node temp = n->next;
	printf("Freeing %d.\n",n->value);
	free(n);
	n->next = NULL;
	if(temp)
		destroyLL(temp);
}

int main()
{
	int i;
	Node head = initLL();
	for(i=0; i<8; ++i)
		inserttoLL(head,rand()%3);
	printLL(head);
	destroyLL(head);
	printLL(head);
	return 0;
}
