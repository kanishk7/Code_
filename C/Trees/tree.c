#include "treedef.h"

static int mallocbts = 0;

Tree initialise_tree()
{
	Tree t = (Tree)(malloc)(sizeof(struct tree));
	mallocbts+=(int)(sizeof(struct tree));
	t->size = 0;
	t->root = NULL;
	return t;
}



void freeTreeNode(TreeNode n)
{
	if(n->children)
		freeTreeNode(n->children);
	if(n->next)
		freeTreeNode(n->next);
	free(n);
	mallocbts-=(int)(sizeof(struct treenode));
	return;
}

void destroy(Tree t)
{
	if(t->root)
		freeTreeNode(t->root);
	free(t);
	mallocbts-=(int)(sizeof(struct tree));
}

void insert(Tree t, int new_child, int d)
{
	TreeNode temp, swap;
	temp = (TreeNode)malloc(sizeof(struct treenode));
	temp->data = d;
	temp->children = NULL;
	temp->next = NULL;
	mallocbts+=(int)(sizeof(struct treenode));

}

