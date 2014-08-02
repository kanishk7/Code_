#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"



int main(void){
	HEAP h;
	printf("\n!%d!\n",MAXHEAP);
	int a[MAXHEAP];
	randomizeArr(a,MAXHEAP);
	int i;
	h.size=0;
	for(i=0;i<MAXHEAP;i++)
	{
			insert(&h,(DATA)a[i]);
			printf("%d ",a[i]);
    }
	printf("\ncreated heap of size: %d\n",h.size);

	while(h.size)
		printf("%d ",(int)gettop(&h));
	printf("\nextracted data from heap, size now: %d\n",h.size);
	return 0;
}


int left(HEAP *h,int i){ /* computes and returns i's left child index */
	if(i>h->size||i<1){
		printf("left: impossible index %d\n",i);
		exit(1);
	}
	if(i*2 > h->size)
		return 0; /* i on lowest layer has no left child */
	return i*2; /* return index of left child */
}

int right(HEAP *h,int i){ /* computes and returns i's right child index */
	if(i>h->size||i<1){
		printf("right: impossible index %d\n",i);
		exit(1);
	}
	if(i*2+1 > h->size)
		return 0; /* i on lowest layer has no right child */
	return i*2+1; /* return index of right child */
}


int parent(HEAP *h,int i){ /* computes and returns i's parent index */
	if(i>h->size||i<1){
		printf("parent: impossible index %d\n",i);
		exit(1);
	}
	if(i==1)
		return 0; /* top has no parent */
	else
		return i/2;
}

int cmp(DATA a,DATA b){ /* compares a and b,
			   returns -1 if(a<b),
			   returns 0  if(a == b) or
			   return  +1 if(a>b) */
	if(a<b) return -1;
	else if(a==b) return 0;
	else return 1;
}

DATA gettop(HEAP *h){ /* returns and removes top element from heap */
	DATA top,last;
	int i,j,k;
	if(h->size == 0){ /* error case for empty heap */
		printf("gettop: empty heap\n");
		exit(1);
	}
	top=h->a[1];
	if(h->size == 1){ /* special case for heap with only 1 node */
		h->size--;
		return top; /* heap is now empty */
	} else {
		/* unlink and store last node in heap */
		last=h->a[h->size--];
		/* need to rearrange heap following extract, */
		i=1;
		while(1){
			j=left(h,i);
			k=right(h,i);
			if(j && k){ /* i has both left and right children */
				if(cmp(last,h->a[j])<0 &&
				   cmp(last,h->a[k])<0)
					break; /* heap OK so quit loop */
				if(cmp(h->a[j],h->a[k])<=0){
					/* move hole down to left */
					h->a[i]=h->a[j];
					i=j;
				} else {
					/* move hole down to right */
					h->a[i]=h->a[k];
					i=k;
				}
			} else if(j){ /* i has a left but no right child */
				if(cmp(last,h->a[j])<0)
					break; /* heap OK, quit loop */
				/* move hole to left */
				h->a[i]=h->a[j];
				i=j;
			} else  /* node i now at bottom of heap */
				break;
		}
		/* replace unlinked last node in hole now at lowest layer */
		h->a[i]=last;
		return top;
	}
}


void insert(HEAP *h, DATA d){ /* inserts d into heap */
	int i,j;
	if(h->size==0){ /* special case of empty heap */
		h->size++;
		h->a[1]=d;
	} else {
		h->size++; /* create hole at bottom of heap */
		i=h->size;
		while(1){ /* move hole to position where d can be inserted */
			j=i;
			i=parent(h,i);
			if(!i){ /* hole must now be at top so insert here */
				h->a[1]=d;
				return;
			}
			if(cmp(d,h->a[i])>=0){
				/* heap OK so insert below parent here */
				h->a[j]=d;
				return;
			}
			/* bubble parent value down, and hole up */
			h->a[j]=h->a[i];
		}
	}
}



void printArr(int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("<EOA>\n");
    return;
}

void randomizeArr(int a[], int size)
{
    printf("Creating array of size %d.\n",size);
    int i;
    for(i=0; i<size; i++)
        a[i] = rand()%500;
    return;
}


