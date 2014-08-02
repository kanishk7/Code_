#ifndef STACKDEF_H
#define STACKDEF_H

struct stacknode
{
	int data;
	struct stacknode *next;
};

typedef struct stacknode* StackNode;

struct stack
{
	StackNode top;
	int size;
};

typedef struct stack* Stack;

#endif
