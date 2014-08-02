#ifndef SORTDEF_H
#define SORTDEF_H

#define STRLENGTH 10
#define SHRINK 1.3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "sort.c"
#include "heap.h"

typedef struct dataset
{
    int data;
    char s[STRLENGTH];
}Dataset;

void printArr(int a[], int sizelol);
void randomizeArr(int a[], int size);
void bubblesort(int a[], int size);
void insertionsort(int a[], int size);
void selectionsort(int a[], int size);
void combsort(int a[], int size);
void cocktailsort(int a[], int size);
void swap(int* a, int* b);
void printArr(int a[], int size);
void merge(int a[], int b[], int l1, int u1, int l2, int u2);
void msort(int a[], int b[], int l, int r);
void pA(int a[], int L, int R);


#endif
