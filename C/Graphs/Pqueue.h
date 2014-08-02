#ifndef QUEUE_H
#define QUEUE_H

#include "queueDefs.h"

void PEnqueue(PQueue q, Data d);
Data PDequeue(PQueue q);
int PQsize(PQueue q);
Queue initialisePQueue();
void printPqueue(PQueue q);

#endif
