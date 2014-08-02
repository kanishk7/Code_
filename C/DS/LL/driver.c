#include "template.h"

List initL()
{
	List l = (List)malloc(sizeof(struct list));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

swap(Node* a, Node* b)
{
	Node* temp = a;
	a = b;
	b = temp;
}

List sortL(List l)
{
	Node h = l->head, t = l->tail;
	if(l->size == 1)
		return l;
	if(l->size == 2)
	{
		if(l->head->d > l->head->next->d)	
		{
			int temp = l->head->d;
			l->head->d = l->head->next->d;
			l->head->next->d = temp;
		}
		return l;
	}
	Node m = l->head->next;
	

}


List insertL(List l, int d, char ch)
{
	Node nNode = (Node)malloc(sizeof(struct node));
	nNode->next = NULL;
	nNode->d = d;
	nNode->c = ch;
	Node temp = l->head;
	if(l->size == 0)
	{
		l->head = nNode;
		l->tail = nNode;
		l->size = 1;
		return l;
	}
	while(temp->next)
		temp = temp->next;
	nNode->prev = temp;
	l->tail = nNode;
	l->size++;
	temp->next = nNode;
	return l;
}

void printL(List l)
{
	printf("Printing list of size %d.\n",l->size);
	Node temp = l->head;
	while(temp)
	{
		printf("%d:%c\t",temp->d,temp->c);
		temp = temp->next;
	}
	printf("<EOLL>\n");
}

void freeNodes(Node n)
{
	while(n->next)
		freeNodes(n->next);
	free(n);
}

void destroyL(List l)
{
	if(l->size == 0)
		return;
	freeNodes(l->head);
}

int main()
{
	List l = initL();
	int size = 12, i, lt = 100;
	srand(time(NULL));
	for(i=0; i<size; ++i)
	{
		l = insertL(l,rand()%3,65+rand()%27);
	}
	printf("l->tail = %d:%c.\n",l->tail->d,l->tail->c);
	sortL(l);
	printL(l);
	//destroy(l);
	return 0;
}
