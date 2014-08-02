#ifndef QUEUEDEFS_H
#define QUEUEDEFS_H

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int Data;

struct pqueuenode
{
    Data d;
    //EdgeNode e;
    struct pqueuenode *next;
};

typedef struct pqueuenode* PQueueNode;

struct pqueue
{
    PQueueNode head;
    PQueueNode tail;
    int size;
};

typedef struct pqueue* PQueue;

struct queuenode
{
    Data d;
    struct queuenode *next;
};

typedef struct queuenode* QueueNode;

struct queue
{
    QueueNode head;
    QueueNode tail;
    int size;
};

typedef struct queue* Queue;

#endif
