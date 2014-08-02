#ifndef ORDER_C
#define ORDER_C
#define SIZE 5

#include "sortdef.h"
#include "sort.c"
#include <stdio.h>

void generateArr(int a[], int size);

int qsel(int a[], int position, int l, int r)
{
    printf("A new QSel has begun.\n");
    pA(a,l,r);
    printf("Position = %d.\n",position);
    //getchar();
    if(l == r)
    {
        if(position == 0)
            return a[position];
        else
        {
            printf("Something went wrong. Position is illegal. It's = %d.\n",position);
            getchar();
        }
    }
    if(r-l == 1)
    {
        if(position == 1)
            return a[r];
        return a[l];
    }

    int pivot = l + rand()%(r-l+1);
    printf("Pivot initially is = %d. It is at %d.\n",a[pivot],pivot);
    int i = 0;
    swap(&a[l],&a[pivot]);
    int lt = l+1, rt = r;
    while(lt < rt)
    {
        while(a[lt] < a[l])
            lt++;
        while(a[rt] > a[l])
            rt--;
        if(lt < rt)
        {
            swap(&a[lt],&a[rt]);
            lt++;
            rt--;
        }
    }
    swap(&a[l],&a[rt]);
    //pA(a,l,r);
    printf("Pivot is = %d. It is at %d.\n",a[rt],rt);
    printf("Comparing %d < %d\n",position,rt-l);
    if(position < (rt-l))
    {
        printf("Sending further with position = %d between %d:%d.\n",position,l,rt-1);
        getchar();
        return qsel(a,position,l,rt-1);
    }
    else if(position > (rt-l))
    {
        printf("Sending further with position = %d between %d:%d.\n",position-rt+l-1,rt+1,r);
        getchar();
        return qsel(a,position-rt-1+l,rt+1,r);
    }
    else
        return a[position+l];

}

int quickselect(int a[], int size, int position)
{
    int posval = qsel(a,position-1,0,size-1);
    printf("\n\n%dth smallest element is = %d.\n\n",position,posval);
    return posval;
}

int main()
{
    int a[SIZE];
    srand(33);
    randomizeArr(a,SIZE);
    quickselect(a,SIZE,(int)SIZE/3);
    printArr(a,SIZE);
}

void generateArr(int a[],  int size)
{
    int i;
    for(i=0; i<size; ++i)
    {
        a[i] = i;
    }
}


#endif
