#ifndef QUEUE_C
#define QUEUE_C

#include "queueDefs.h"

static int queueops_malloc = 0;

void Enqueue(Queue q, Data d)
{
    printf("%d Enqueued.\n",d);
    QueueNode temp = (QueueNode)malloc(sizeof(struct queuenode));
    queueops_malloc+=(int)(sizeof(struct queuenode));
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
    QueueNode prevtail = q->tail;
    prevtail->next = temp;
    q->tail = temp;
}

Data Dequeue(Queue q)
{
    QueueNode temp = q->head;
    q->head = q->head->next;
    q->size--;
    Data d = temp->d;
    free(temp);
    queueops_malloc-=(int)(sizeof(struct queuenode));
    //printf("%d Dequeued.\n",d);
    return d;
}

int size(Queue q)
{
    return q->size;
}

int isEmpty(Queue q)
{
    if(q->size == 0)
        return 1;
    return 0;
}

Queue initialiseQueue()
{
    Queue q = (Queue)malloc(sizeof(struct queue));
    queueops_malloc+=(int)(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    printf("Queue has been initialised.\n");
    return q;
}

void freeENLLqueue(QueueNode n)
{
    if(n->next != NULL)
        freeENLLqueue(n->next);
    free(n);
    queueops_malloc-=(int)(sizeof(struct queuenode));
}

void printqueue(Queue q)
{
    if(q->size == 0)
    {
        printf("Empty Queue.\n");
        return;
    }
    QueueNode temp = q->head;
    printf("Printing Queue. \n");
    while(temp->next)
    {
        printf("%d\t",temp->d);
        temp = temp->next;
    }
    printf("%d.\t<EOL>\n",temp->d);
    return;
}


void destroyqueue(Queue q)
{
    if(q->size != 0)
        freeENLLqueue(q->head);
    free(q);
    queueops_malloc-=(int)(sizeof(struct queue));
    return;
}


#endif
