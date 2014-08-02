
#include "graphDef.h"
#include "graphOps.h"
#include "Pqueue.h"
#include "queueDefs.h"
#include "graphAlgos.h"

int abs(int x)
{
	return x<0? x*(-1): x;
}

int main()
{
    id_no = 0;
    int i,j;
    AdjList al;
    for(i=0; i<GRAPH_SIZE; i++)
    {
        al.list[i] = newVertex();
        //printf("(%d).\n",al.list[i]->v->id_no);
    }
    AdjMatrix am;
    for(i=0; i<GRAPH_SIZE; i++)
        for(j=0; j<GRAPH_SIZE; j++)
            am.matrix[i][j] = INFINITE;

    edgepopulator(al,am,GRAPH_DENSITY);

    printf("No. of vertices = %d. No. of edges = %d.\n",GRAPH_SIZE,no_of_edges);
    fillAdjMatrix(al,am.matrix);
    //printAdjMatrix(am.matrix);
    clock_t start = clock();
    visited_nodes;
    int question = 3;
	int answer = DepthFirstSearch(al,am,3,"ijlc",&visited_nodes);
	int dfs_count = visited_nodes;
	visited_nodes = 0;
	printf("%d.\n",BreadthFirstSearch(al,am,3,"ijlc",&visited_nodes));
	int bfs_count = visited_nodes;
	
	int g_size = GRAPH_SIZE;
	float g_density = GRAPH_DENSITY;
	
	printf("Under the following conditions..\n");
	printf("GRAPH_SIZE = %d.\n",g_size);
	printf("GRAPH_DENSITY = %f.\n", g_density);
	printf("Initial Distance = %d.\n", abs(answer-question));
	
	
	
	printf("Results DFS(%d) vs BFS(%d).\n",dfs_count, bfs_count);
	

    return 0;
}
