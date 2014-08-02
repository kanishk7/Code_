#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* max array size for heap */
#define MAXHEAP 100

/* DATA could be any record */
typedef int DATA;

typedef struct heap {
	DATA a[MAXHEAP]; /* array element 0 unused */
	int size; /* size is number of nodes within heap */
} HEAP;


DATA gettop(HEAP *h); /* returns and removes top element from heap */
void insert(HEAP *h, DATA d); /* inserts record d into heap */
int left(HEAP *h,int i); /* computes and returns i's left child index or 0 */
int right(HEAP *h,int i); /* computes and returns i's right child index or 0 */
int parent(HEAP *h,int i); /* computes and returns i's parent index or 0 */
int cmp(DATA a,DATA b); /* compares a and b, similarly to strcmp() */
void randomizeArr(int a[], int size);
void printArr(int a[], int size);

#endif
