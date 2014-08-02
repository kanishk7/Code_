#ifndef SORT_C
#define SORT_C

#include "sortdef.h"
#include <stdio.h>
#include <conio.h>
#define SHRINK 1.3 //Shrink factor for comb sort

int pivot(int a[], int l, int r, int option)
{
/*Choose the appropriate option for the pivot.

1. Average of L/R.
2. Random pivot
3. Average of L, R and Mid.
4.
5.

*/

    switch(option)
    {
    case 1:
        return (l+r)/2;
        break;
    case 2:
        return l+rand()%(r-l);
        break;
    case 3:
        if(a[l] < a[(l+r)/2])
            if(a[(l+r)/2] < a[r])
                return (l+r)/2;
            else if(a[r] < a[l])
                    return l;
                 else
                    return r;
        else if(a[(l+r)/2] > a[r])
                return (l+r)/2;
             else
                return a[l]>a[r]? r:l;
        return (l+r)/2;
        break;
    default:
        return (l+r)/2;
    }
}



void qs(int a[], int l, int r)
{
    if(l == r || l>r)
        return;

    if((r-l) == 1)
    {
        if(a[l] > a[r])
            swap(&a[l],&a[r]);
        return;
    }

    int index = pivot(a,l,r,2);
    swap(&a[index],&a[l]);
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
    if(l != rt)
        swap(&a[l],&a[rt]);
    qs(a,l,rt-1);
    qs(a,rt+1,r);
    return;
}



void quicksort(int a[], int size)
{
    qs(a,0,size-1);
    return;
}



void msort(int a[], int b[], int l, int r)
{
    int left_start, left_end, right_start, right_end,i;
    left_start =l;
    left_end = (int)(l/2 + r/2);
    right_start = left_end + 1;
    right_end = r;
    if(l == r)
        return;

    msort(a,b,left_start,left_end);
    msort(a,b,right_start, right_end);
    merge(a,b,left_start, left_end, right_start, right_end);

    for(i=left_start; i<=right_end; ++i)
        a[i] = b[i];

}


void mergesort(int a[], int size)
{
    int b[size];
    msort(a,b,0,size-1);
    int i;
    for(i=0; i<size; ++i)
        a[i] = b[i];
}

void merge(int a[], int b[], int l1, int u1, int l2, int u2)
{

    int size1 = u1-l1, size2 = u2-l2, lc = l1, rc = l2,i,j;
    int bc = l1;
    while(lc <= u1 && rc <= u2)
    {
        if(a[lc] <= a[rc])
        {
            b[bc] = a[lc];
            lc++;
            bc++;
        }
        else
        {
            b[bc] = a[rc];
            bc++;
            rc++;
        }
    }
    if(lc == u1+1)
    {
        for(i=rc; i<=u2; i++ )
        {
            b[bc] = a[rc];
            bc++; rc++;
        }
    }
    else
    {
        for(i=lc; i<=u1; i++ )
        {
            b[bc] = a[lc];
            bc++; lc++;
        }
    }
    return;
}


void selectionsort(int a[], int size)
{
    int i,j,min;
    for(i=0; i<size; ++i)
    {
        min = a[i];
        for(j=i+1; j<size; j++)
        {
            if(min > a[j])
            {
                min = a[j];
                swap(&a[j],&a[i]);
            }
        }
    }
    return;
}

void insertionsort(int a[], int size)
{
    int i,j,temp,k;
    FILE *out;
    out = fopen("stream.txt","w");

    for(i=1; i<size; ++i)
    {
        temp = a[i];
        for(j=0; j<i; j++)
            if(a[j] > temp)
                break;
        for(k=i; k>j; --k )
            a[k] = a[k-1];
        a[j] = temp;
    }
}


void bubblesort(int a[], int size)
{
    int i,j;
    int flag = 1;
    printf("Array size = %d.\n",size);
    for(i=0; i<size; i++)
    {
        flag = 0;
        for(j=0; j<(size-1-i); j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
    return;
}

void combsort(int a[], int size)
{
    int i,j,gap;
    gap = size/SHRINK;
    int flag = 1;
    printf("Array size = %d.\n",size);
    while(flag == 1 || gap > 1)
    {
        flag = 0;
        for(i=0; i<(size-gap); i++)
        {
            if(a[i]>a[i+gap])
            {
                swap(&a[i],&a[i+gap]);
                flag = 1;
            }
        }
        gap = gap/SHRINK;
    }
    return;
}

void cocktailsort(int a[], int size)
{
    int i,j;
    int flag = 1;
    printf("Array size = %d.\n",size);
    for(i=0; i<size; i++)
    {
        flag = 0;
        for(j=0; j<(size-1-i); j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }

        for(j=size-2-i; j>=0; j--)
        {
            if(a[j] < a[j-1])
            {
                swap(&a[j], &a[j-1]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            break;
        }
    }
    return;
}



void swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
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

#if 0


int main()
{
    int c[50];
    srand(time(NULL));
    randomizeArr(c,50);
    quicksort(c,sizeof(c)/4);
    return 0;
}

#endif

void pA(int a[], int L, int R)
{
    printf("%d-%d:",L,R);
    int i;
    for(i=L; i<=R; i++)
    {
        printf("%d ",a[i]);
    }
    printf("<EOA>\n");
    return;
}

void randomizeArr(int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
        a[i] = rand()%500;
    return;
}



#endif
