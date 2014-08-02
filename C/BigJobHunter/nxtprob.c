#include <stdio.h>
#include <stdlib.h>

struct node
{
	int q;
	struct node *next;
};

typedef struct node* Node;

struct list
{
	Node head;
	int size;
};

typedef struct list* List;

List init()
{
	List l = (List)malloc(sizeof(struct list));
	l->head = NULL;
	l->size = 0;
	return l;
}

void printList(List l)
{
	Node temp = l->head;
	while(temp->next)
	{
		printf("%d\t", temp->q);
		temp = temp->next;
	}
	printf("%d\t<EOLL>\n",temp->q);
	return;
}

Node insert(List l, int data)
{
	Node temp = (Node)malloc(sizeof(struct node));
	temp->q = data;
	temp->next = NULL;
	if(l->size == 0)
	{
		l->head = temp;
		l->size = 1;
		return l->head;
	}
	Node t2;
	t2 = l->head;
	while(t2->next)
		t2 = t2->next;
	t2->next = temp;
	l->size++;
	return t2->next;
}

Node delete(List l, int value)
{
	Node temp = l->head, temp2 = l->head;
	if(l->head->q == value)
		if(l->size == 1)
			printf("Last node left. Cannot delete.\n");
		else
		{
			l->head = temp->next;
			free(temp);
			l->size--;
			return l->head;
		}
	while(temp->next)
	{
		if(temp->q == value)
		{
			temp2->next = temp->next;
			free(temp);
			l->size--;
			return temp2;
		}
		temp2 = temp;
		temp = temp->next;
	}
	if(temp->q == value)
	{
		temp2->next = NULL;
		l->size--;
		free(temp);
		return temp2;
	}
	//printf("Sorry. Could not locate %d.\n", value);
	return NULL;
}

void freeLL(Node head)
{
	if(head->next)
		freeLL(head->next);
	free(head);
}

void destroy(List l)
{
	if(l->size == 0)
		return;
	freeLL(l->head);
	free(l);
	return;
}

int kth_element(List l, int k)
{
	int i;
	Node temp = l->head;
	for(i=0; i<k; i++)
	{
		temp = temp->next;
	}
	printf("Next question to attempt = #%d. Press ENTER and get cracking, boyo.\n",temp->q);
	return temp->q;
}


int main()
{
	FILE *in;
	in = fopen("Done.txt","r");
	int i = 1, temp;
	List l = init();
	for(i=1; i<=112; i++)
		insert(l,i);
	//printf("Size of list is now %d.\n", l->size);
	//printList(l);
	while(!feof(in))
	{
		fscanf(in,"%d",&temp);
		delete(l,temp);
	}
	//printList(l);	
	if(!l->size)
	{
		printf("Congratulations. Big Job Hunter now stands finished.\n");
		printf("Your efforts have single-handedly culminated in this outcome.\nTake a bow.\n");
		printf("Exiting. :) \n");
		return 0;
	
	}
	printf("There are %d problems still left.\n", l->size);

	srand(time(NULL));
	int pos = rand()%(l->size+1);
	kth_element(l,pos);
	
	destroy(l);
	getchar();

	return 0;
}
