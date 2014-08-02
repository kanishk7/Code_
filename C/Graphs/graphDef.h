#ifndef GOPS_H
#define GOPS_H

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "queueDefs.h"

#define GRAPH_DENSITY 0.1
#define GRAPH_SIZE 200
#define STRLENGTH 4
#define INFINITE 999999
#define MAX_WEIGHT 100
#define SEED 7123
#define R_SEED rand();

static int id_no = 0;
static int no_of_edges = 0;
static int mallocctr = 0;
static int freectr = 0;

static int visited_nodes = 0;

struct vertex
{
    int id_no;
    char s[STRLENGTH+1];
};

typedef struct vertex* Vertex;

struct edge
{
    Vertex from;
    Vertex to;
    int weight;
};

typedef struct edge* Edge;

struct edgenode
{
    Edge e;
    struct edgenode *next;
};

typedef struct edgenode* EdgeNode;

struct vertexnode
{
    Vertex v;
    EdgeNode e;
};

typedef struct vertexnode* VertexNode;

struct adjlist
{
    VertexNode list[GRAPH_SIZE];
    int no_of_edges;
};

typedef struct adjlist AdjList;

struct adjmatrix
{
    int matrix[GRAPH_SIZE][GRAPH_SIZE];
};

typedef struct adjmatrix AdjMatrix;

void rand_s(int length, char *s);

struct node
{
    int vertex;
    struct vnode *next;
};

typedef struct node* IntNode;

typedef IntNode* IntNodeArr;

#endif
