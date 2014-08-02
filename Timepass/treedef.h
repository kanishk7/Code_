struct dataset
{
    int n;
    char s[20];
};

typedef struct dataset Dataset;

struct node
{
    Dataset data;
    struct node *next;
};

typedef struct node* Node;

struct btnode
{
    Dataset data;
    struct btnode *left;
    struct btnode *right;
    int height;
};

typedef struct btnode* BTnode;

struct tnode
{
    Dataset data;
    struct node *children;
    int height;
};

typedef struct tnode* Tnode;


