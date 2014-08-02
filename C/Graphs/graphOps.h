#ifndef GRAPHOPS_H
#define GRAPHOPS_H


VertexNode newVertex();
void addtoedgeLL(EdgeNode E, VertexNode V);
EdgeNode newEdge(AdjMatrix am, AdjList al, VertexNode from, VertexNode to, int weight, int undirected);
void freeENLL(EdgeNode e);
void destroy(VertexNode V);
void edgepopulator(AdjList al, AdjMatrix am, float density);
void printAdjMatrix(int am[GRAPH_SIZE][GRAPH_SIZE]);
void fillAdjMatrix(AdjList al, int am[GRAPH_SIZE][GRAPH_SIZE]);

#endif
