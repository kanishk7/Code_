#ifndef TREEDEF_H
#define TREEDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGTH_TREEDEF 10

struct Data
{
	int n;
	char s[STR_LENGTH_TREEDEF];
};

struct treenode
{
	int data;
	struct treenode *children;
	struct treenode *next;
};

typedef struct treenode* TreeNode;

struct tree
{
	int size;
	TreeNode root;
};

typedef struct tree* Tree;

struct bstnode
{
	int data;
	int height;
	struct bstnode* left;
	struct bstnode* right;
	struct bstnode* parent;
	struct bstnode* morris;
};

typedef struct bstnode* BstNode;

struct bstree
{
	BstNode root;
	int size;	
	int height;
};

typedef struct bstree* BsTree;

#endif
