#include "treedef.h"

int max(int a, int b)
{
	return a>b?a:b;
}

void updateHeights(BsTree t);

static int Count = 0;

int maxof3(int a, int b, int c)
{
	if(a >= b && a >= c)
		return a;
	else if(b > c)
		return b;
	return c;
}

int Height(BstNode temp)
{
	if(temp)
		return temp->height;
	return 0;
}

BstNode leftrotate(BstNode temp, BsTree b)
{
	BstNode org_parent = temp->parent;
	if(temp->parent->parent)
	{
		BstNode grandparent = temp->parent->parent;
		temp->parent = grandparent;
		if(temp->data < grandparent->data)
			grandparent->left = temp;
		else
			grandparent->right = temp;
		temp->left = org_parent;
		org_parent->parent = temp;
		org_parent->right = NULL;
	}
	else
	{
		temp->parent = NULL;
		temp->left = org_parent;
		org_parent->parent = temp;
		org_parent->right = NULL;
		b->root = temp;
	}
	return temp;
}

BstNode rightrotate(BstNode temp, BsTree b)
{
	BstNode org_parent = temp->parent;
	if(temp->parent->parent)
	{
		BstNode grandparent = temp->parent->parent;
		temp->parent = grandparent;
		if(temp->data < grandparent->data)
			grandparent->left = temp;
		else
			grandparent->right = temp;
		temp->right = org_parent;
		org_parent->parent = temp;
		org_parent->left = NULL;
	}
	else
	{
		temp->parent = NULL;
		temp->right = org_parent;
		org_parent->parent = temp;
		org_parent->left = NULL;
		b->root = temp;
	}
	return temp;
}


BsTree Init_BSTree()
{
	BsTree bs = (BsTree)malloc(sizeof(struct bstree));
	bs->root = NULL;
	bs->size = 0;
	bs->height = 0;
	printf("A Binary Search Tree has been initialised.\n");
	return (BsTree)bs;	
}

int height(BstNode n)
{
	if(n->left == NULL && n->right == NULL)
		n->height = 1;
	else if(n->left == NULL)
		n->height = height(n->right)+1;
	else if(n->right == NULL)
		n->height = height(n->left)+1;
	else
		n->height = max(height(n->left),height(n->right)) + 1;
	return n->height;
}


void updateHeights(BsTree t)
{
	height(t->root);
}

BstNode Search(BsTree t, int val)
{
	BstNode temp = t->root;
	while(temp)
	{
		if(temp->data < val)
			temp = temp->right;
		else if(temp->data > val)
			temp = temp->left;
		else
			return temp;
	}
	printf("%d not found.\n",val);
	return NULL;
}

BstNode getleftmostchild(BstNode root)
{
	while(root->left)
		root = root->left;
	return root;
}

BstNode getrightmostchild(BstNode root)
{
	while(root->right)
		root = root->right;
	return root;
}


BstNode Delete(BsTree t, int val)
{
	BstNode temp = Search(t,val);
	if(temp->right == NULL && temp->left == NULL)
	{	
		if(temp->data < temp->parent->data)
			temp->parent->left = NULL; 
		else
			temp->parent->right = NULL;
	}
}

BstNode getfirstleftancestor(BstNode root)
{
	while(root->parent)
	{
		if(root->parent->data <= root->data)
			return root->parent;
		else
			root = root->parent;
	}
	return NULL;
}

BstNode getfirstrightancestor(BstNode root)
{
	while(root->parent)
	{
		if(root->parent->data >= root->data)
			return root->parent;
		else
			root = root->parent;
	}
	return NULL;
}

BstNode Successor(BstNode root)
{
	if(root->right)
		return getleftmostchild(root->right);
	if(root->parent)
		return getfirstrightancestor(root);
	printf("This node has no successors.\n");
	return NULL;
}

BstNode Predecessor(BstNode root)
{
	if(root->left)
		return getrightmostchild(root->left);
	if(root->parent)
		return getfirstleftancestor(root);
	return NULL;
}

BstNode getbstnode(int val)
{
	BstNode b = malloc(sizeof(struct bstnode));
	b->data = val;
	b->left = NULL;
	b->right = NULL;
	b->parent = NULL;
	b->morris = NULL;	
	return b;
}

void nodedestroy(BstNode n)
{
	if(n->left != NULL)
		nodedestroy(n->left);
	if(n->right != NULL)
		nodedestroy(n->right);
	free(n);
}

BstNode lca(BstNode temp, BstNode a, BstNode b)
{
	if(temp->data > a->data && temp->data > b->data)
		return lca(temp->left,a,b);
	else if(temp->data < a->data && temp->data < b->data)
		return lca(temp->right,a,b);
	return temp;

}

BstNode LeastCommonAncestor(BstNode a, BstNode b, BsTree t)
{
	return lca(t->root,a,b);
}

BsTree makeThreaded(BsTree t)
{
//Finish
	BstNode temp = getleftmostchild(t->root);
	BstNode next = temp;
	while(next)
	{
		next = Successor(temp);
		if(temp->right == NULL)
			temp->morris = next;
	}
	return t;
}

void BstDestroy(BsTree b)
{
	if(b->root == NULL)
		return;
	nodedestroy(b->root);
	free(b);
}

BstNode BSTinsert(BsTree b, int val)
{
	int right;
	if(b->size == 0)
	{
		b->root = (BstNode)malloc(sizeof(struct bstnode));
		b->root->left = NULL;
		b->root->height = 1;
		b->root->right = NULL;
		b->root->morris = NULL;
		b->root->parent = NULL;		
		b->root->data = val;
		b->size = 1;
		return b->root;
	}
	BstNode temp = b->root, temp_parent = b->root;
	while(temp != NULL)
	{
		if(val < temp->data)
		{
			temp_parent = temp;
			temp = temp->left;
			right = 0;
		}
		else
		{
			temp_parent = temp;
			temp = temp->right;
			right = 1;
		}
	}
	
	temp = (BstNode)malloc(sizeof(struct bstnode));
	temp->left = NULL;
	temp->right = NULL;
	temp->morris = NULL;
	temp->parent = temp_parent;
	temp->height = 1;
	temp->data = val;	
	if(right)	
		temp_parent->right = temp;
	else
		temp_parent->left = temp;		
	
	while(temp->parent)
	{
		temp->parent->height = max(1+temp->height, temp->parent->height);			
		if(temp->parent)
			temp = temp->parent;
		else
			break;
	}
	return (BstNode)temp;
}

void null_error()
{
	printf("Sorry. This node is empty.\n");
}

void traverse_nodes(BstNode t, int *occ, int k)
{
	if(t == NULL)
		return;
	int V = t->data;
	if(!occ[V])
	{
		occ[V] = 1;
	}
	if(k > V)
		if(occ[k-V])
		{
			printf("(%d,%d)\n",V,(k-V));
			Count++;
		}

	traverse_nodes(t->left,occ,k);
	traverse_nodes(t->right,occ,k);	
}

int printSumPair(BsTree b, int k)
{
	Count = 0;
	int occ[k];
	int i;
	for(i=0; i<k; i++)
		occ[i] = 0;

	traverse_nodes(b->root, occ, k);
	return Count;
}

void traverse(BsTree b)
{
	int c;
//	printf("I'll be your guide: temp.\nSee, that's funny because I'm a temporary variable.\n");
//	printf("They'll kill me right after this. :(\n");
//	printf("Anyways..\n");
	printf("Okay. We're here at the root. It's value is %d.\n", b->root->data);	
	BstNode temp = b->root;
	while(1)
	{
		BstNode backup = temp;
		printf("Where to? Enter 1(left) 2(right) 3(parent) 4(successor) 5(predecessor) 6(height) 7(Largest node) 8(search) 9(left rotation) 10(right rotation) 99(exit):: ");
		scanf("%d",&c);
		if(c == 1)
			if(temp->left)
				temp = temp->left;
			else
				{null_error(); continue;}
		else if(c == 2)
			if(temp->right)
				temp = temp->right;
			else
				{null_error(); continue;}
		else if(c == 3)
			temp = temp->parent;
		else if(c == 4)
			temp = (BstNode)Successor(temp);
		else if(c == 5)
			temp = (BstNode)Predecessor(temp);
		else if(c == 6)	
		{
			printf("Height = %d.\n",temp->height);
			continue;
		}
		else if(c == 7)
			temp = (BstNode)getrightmostchild(temp);
		else if(c == 8)
		{
			printf("Enter the value you want to search:");
			int val;
			scanf("%d",&val);
			temp = Search(b,val);
		}
		else if(c == 9)
		{
			temp = leftrotate(temp,b);
		}
		else if(c == 10)
			temp = rightrotate(temp,b);
		else if(c == 99)
			break;
		else
			continue;
		
		if(temp == NULL)
		{
			printf("Requested Node was unavailable. Reverting to original node.\n");
			temp = backup;
			continue;
		}
		printf("**We are here at the requested node. Value is = %d.**\n",temp->data);		
	}
}

