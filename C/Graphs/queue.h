#ifndef QUEUE_H
#define QUEUE_H

#include "queueDefs.h"

extern void Enqueue(Queue q, Data d);
extern Data Dequeue(Queue q);
extern int size(Queue q);
extern Queue initialiseQueue();

#endif
