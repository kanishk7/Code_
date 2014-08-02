#ifndef GOPS_C
#define GOPS_C

#include "graphDef.h"
#include "graphOps.h"

VertexNode newVertex()
{
    VertexNode V = malloc(sizeof(struct vertexnode));
    mallocctr+=(int)(sizeof(struct vertexnode));
    V->v = malloc(sizeof(struct vertex));
    mallocctr+=(int)(sizeof(struct vertex));
    V->v->id_no = id_no;
    srand(SEED);
    rand_s(STRLENGTH,V->v->s);
    V->e = NULL;
    printf("Vertex initialised by values %d and %s.\n",V->v->id_no, V->v->s);
    id_no++;
    return V;
}

void addtoedgeLL(EdgeNode E, VertexNode V)
{
    EdgeNode temp = V->e;
    if(V->e == NULL)
    {
        V->e = E;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = (EdgeNode)malloc(sizeof(struct edgenode));
    mallocctr+=(int)(sizeof(struct edgenode));
    temp->next = E;

    return;
}

EdgeNode newEdge(AdjMatrix am, AdjList al, VertexNode from, VertexNode to, int weight, int undirected)
{
    EdgeNode E = (EdgeNode)malloc(sizeof(struct edgenode));
    mallocctr+=(int)(sizeof(struct edgenode));
    E->e = (Edge)malloc(sizeof(struct edge));
    mallocctr+=(int)(sizeof(struct edge));
    E->e->from = from->v;
    E->e->to = to->v;
    E->e->weight = weight;
    E->next = NULL;
    addtoedgeLL(E,from);
    no_of_edges++;
    if(undirected)
        newEdge(am,al,to,from,weight,0);

    return E;
}

void freeENLL(EdgeNode e)
{
    if(e->next != NULL)
        freeENLL(e->next);
    free(e->next);
    freectr+=(int)(sizeof(EdgeNode));
    free(e->e);
    freectr+=(int)(sizeof(struct edge));
    free(e);
    freectr+=(int)(sizeof(struct edgenode));
}

void destroy(VertexNode V)
{
	if(V->e)
	    freeENLL(V->e);
	if(V->v)
	    free(V->v);
    freectr+=(int)(sizeof(struct vertex));
    if(V)
	    free(V);
    freectr+=(int)(sizeof(struct vertexnode));
}

void edgepopulator(AdjList al, AdjMatrix am, float density)
{
    //getchar();
    srand(time(NULL));
    int i,j;
    for(i=0; i<GRAPH_SIZE; ++i)
        for(j=i+1; j<GRAPH_SIZE; ++j)
            if(rand()%10 < density*10)
                newEdge(am,al,al.list[i],al.list[j],(rand()%MAX_WEIGHT)+1,rand()%2);
}

void printAdjMatrix(int am[GRAPH_SIZE][GRAPH_SIZE])
{
    printf("\n\t");
    int i,j;
    for(i=0; i<GRAPH_SIZE; i++)
    {
        printf("%d\t",i+1);
    }
    printf("\n-----");
    for(i=0; i<GRAPH_SIZE; i++)
    {
        printf("--------",i);
    }
    printf("\n");
    for(i=0; i<GRAPH_SIZE; i++)
    {
        printf("%d\t",i);
        for(j=0; j<GRAPH_SIZE; j++)
            am[i][j] == INFINITE? printf("NE\t"): printf("%d\t",am[i][j]);
        printf("\n");
    }

    return;
}


void fillAdjMatrix(AdjList al, int am[GRAPH_SIZE][GRAPH_SIZE])
{
    int i,j;
    EdgeNode temp;
    for(i=0; i<GRAPH_SIZE; i++)
    {
        temp = al.list[i]->e;
        if(temp == NULL)
            continue;
        else
        {
            while(42)
            {
                am[temp->e->from->id_no][temp->e->to->id_no] = temp->e->weight;
                if(temp->next == NULL)
                    break;
                else
                    temp = temp->next;
            }
        }
    }
    for(i=0; i<GRAPH_SIZE; i++)
        am[i][i] = 0;
}

void rand_s(int length, char *s)
{
    srand(id_no);
    int i;
    char a[length+1];
    for(i=0; i<length; i++)
    {
        a[i] = (char)(rand()%26 + 97);
    }
    a[length] = '\0';
    strcpy(s,a);
}

#endif
