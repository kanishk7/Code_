#include "template.h"

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

int main()
{
    int c[10];
//    srand(time(NULL));
    randomizeArr(c,10);
	printArr(&c[5],10);
    return 0;
}

