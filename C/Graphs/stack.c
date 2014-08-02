#include "stackDef.h"
#include <stdlib.h>
#include <stdio.h>

Stack init_stack()
{
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->size = 0;
	s->top = NULL;
	printf("Stack has been initialised.\n");
	return s;
}

void push(Stack s, int data)
{
	StackNode temp = (StackNode)malloc(sizeof(struct stacknode));
	temp->data = data;
	temp->next = s->top;
	s->top = temp; 
	s->size++;
	return;
}
int pop(Stack s)
{
	if(!StSize(s))
	{
		printf("Stack's fucking empty.\n");
		return -1;	
	}
	StackNode temp = s->top;
	int data = temp->data;
	s->top = temp->next;
	s->size--;
	free(temp);
	return data;
}

void freeStackNodes(StackNode s)
{
	if(s->next != NULL)
		freeStackNodes(s->next);
	free(s);
}

int StSize(Stack s)
{
	return s->size;
}

void StackDestroy(Stack s)
{
	if(!size(s))
		return;
	freeStackNodes(s->top);
	free(s);
	return;
}

int isStackEmpty(Stack s)
{
	if(s->size)
		return 0;
	return 1;
}














