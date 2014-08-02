#ifndef LINKEDLISTDEF_H
#define LINKEDLISTDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct node
{
	int value;
	struct node *next;
};

typedef struct node* Node;

struct dnode
{
	int value;
	struct dnode *prev;
	struct dnode *next;
};

typedef struct dnode* DNode;





#endif
