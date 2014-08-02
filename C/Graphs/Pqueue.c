#include <stdio.h>
#include <stdlib.h>
#include "queueDefs.h"

static int queueops_malloc = 0;

void compareTo(Data d1, Data d2)
{
/*Returns 1 if d1 > d2.
-1 if d1 < d2.
0 if d1 = d2.
*/




}


void PEnqueue(PQueue q, Data d)
{
    //printf("%d Enqueued.",d);
    PQueueNode temp = (PQueueNode)malloc(sizeof(struct pqueuenode));
    queueops_malloc+=(int)(sizeof(struct pqueuenode));
    temp->next = NULL;
    temp->d = d;
    if(q->size == 0)
    {
        q->size = 1;
        q->head = temp;
        q->tail = temp;
        return;
    }
    q->size++;
    PQueueNode prev, next;
    prev = q->head; next = q->head;
    if(d < prev->d)
    {
        temp->next = q->head;
        q->head = temp;
        return;
    }
    while(prev->next)
    {
        next = prev->next;
        if(d < next->d)
        {
            prev->next = temp;
            temp->next = next;
            return;
        }
        prev = prev->next;
    }
    prev->next = temp;
    q->tail = temp;
    return;

}

Data PDequeue(PQueue q)
{
    PQueueNode temp = q->head;
    q->head = q->head->next;
    q->size--;
    Data d = temp->d;
    free(temp);
    queueops_malloc-=(int)(sizeof(struct pqueuenode));
    printf("%d Dequeued.\n",d);
    return d;
}

int PQsize(PQueue q)
{
    return q->size;
}


void printPqueue(PQueue q)
{
    if(q->size == 0)
    {
        printf("Empty Queue.\n");
        return;
    }
    PQueueNode temp = q->head;
    printf("Printing Queue. \n");

    while(temp->next != NULL)
    {
        printf("%d\t",temp->d);
        temp = temp->next;
    }
    printf("%d. <EOL>\n",temp->d);
    return;
}


PQueue initialisePQueue()
{
    PQueue q = (PQueue)malloc(sizeof(struct queue));
    queueops_malloc+=(int)(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    printf("Queue has been initialised.\n");
    return q;
}

void freeENLLpqueue(PQueueNode n)
{
    if(n->next != NULL)
        freeENLLpqueue(n->next);
    free(n);
    queueops_malloc-=(int)(sizeof(struct pqueuenode));
}

void destroypqueue(PQueue q)
{
    if(q->size != 0)
        freeENLLpqueue(q->head);
    free(q);
    queueops_malloc-=(int)(sizeof(struct queue));
    return;
}




