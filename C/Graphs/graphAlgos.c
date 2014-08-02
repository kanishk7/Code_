#ifndef GRAPHALGOS_H
#define GRAPHALGOS_H

#include "graphDef.h"
#include "stackDef.h"

printArrwithIndex(int a[GRAPH_SIZE])
{
	int i;
	for(i=0; i<GRAPH_SIZE; i++)
		printf("%d:%d\t",i,a[i]);
}

int BreadthFirstSearch(AdjList al, AdjMatrix am, int start_pt, char *s, int* visited_nodes)
{
	int visited[GRAPH_SIZE];
	int i,j;
	for(i=0; i<GRAPH_SIZE; i++)
		visited[i] = 0;
		
	if(strcmp(s,al.list[start_pt]->v->s) == 0)
		return start_pt;
	
	printf("Not the starting point, at least.\n");
		
	VertexNode temp;
	EdgeNode tempedge;
	int temp_id;
	
	Queue q = (Queue)initialiseQueue();
	Enqueue(q,start_pt);
	while(!isEmpty(q))
	{
		temp_id = Dequeue(q);
		(*visited_nodes)++;
		temp = al.list[temp_id];
		if(strcmp(s,temp->v->s) == 0)
			return temp_id;
		if(temp->e == NULL) 
			continue;
		else
		{
			tempedge = temp->e;
			if(!visited[tempedge->e->to->id_no])
			{
				Enqueue(q,tempedge->e->to->id_no);
				visited[tempedge->e->to->id_no] = 1;
			}
			while(tempedge->next)
			{
				if(!visited[tempedge->next->e->to->id_no])
				{
					Enqueue(q,tempedge->next->e->to->id_no);
					visited[tempedge->next->e->to->id_no] = 1;
				}
				tempedge = tempedge->next;
			}
		}
	}
	printf("Here.\n");
	
	return -1;
}

int DepthFirstSearch(AdjList al, AdjMatrix am, int start_pt, char *s, int* visited_nodes)
{
	int visited[GRAPH_SIZE];
	int i,j;
	for(i=0; i<GRAPH_SIZE; i++)
		visited[i] = 0;		
	if(strcmp(s,al.list[start_pt]->v->s) == 0)
		return start_pt;	
	printf("Not the starting point, at least.\n");		
	VertexNode temp;
	EdgeNode tempedge;
	int temp_id;
	
	Stack S = init_stack();
	push(S,start_pt);
	while(!isStackEmpty(S))
	{
		int temp_id = pop(S);
		printf("Popped %d.\n",temp_id);
		temp = al.list[temp_id];
		(*visited_nodes)++;
		//printArrwithIndex(visited);
		if(strcmp(s,temp->v->s) == 0)
			return temp_id;
		if(temp->e == NULL)
			continue;
		tempedge = temp->e;
		if(!visited[tempedge->e->to->id_no])
		{
			push(S,tempedge->e->to->id_no);
			visited[tempedge->e->to->id_no] = 1;
		}
		while(tempedge->next)
		{
			if(!visited[tempedge->next->e->to->id_no])
			{
				push(S,tempedge->next->e->to->id_no);
				visited[tempedge->next->e->to->id_no] = 1;
			}
			tempedge = tempedge->next;
		}
	}
	return -1;
}


#endif
