#include <stdio.h>
#include <stdlib.h>
#define SIZE 2000
#define RANGE 500


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
    int i;
    for(i=0; i<size; i++)
        a[i] = rand()%RANGE;
    return;
}

int setlength(int a[], int length[], int pred[], int index)
{
    int i, max = 1, maxindex = -1;
    for(i=0; i<index; i++)
    {
        if(max < (length[i]+1))
        {
            if(a[index] > a[i])
            {
                max = length[i] + 1;
                maxindex = i;
                //printf("max = %d and maxindex = %d.\n", max, maxindex);
                continue;
            }
        }
    }
    length[index] = max;
    pred[index] = maxindex;
}

int getsequence(int length[], int pred[], int a[], int size, int succ[])
{
    int max_length = 0, i, max_index = -1, start_index;
    for(i=0; i<size; i++)
        if(max_length < length[i])
        {
            max_length = length[i];
            max_index = i;
        }

    int current = max_index, temp;

    while(pred[current] != -1)
    {
        temp = current;
        current = pred[temp];
        succ[current] = temp;
    }
    printf("\nLength of the sequence = %d. ", max_length);

    return current;
}

printSequence(int a[], int succ[], int start)
{
    printf("Longest increasing subsequence is:\n");
    int current = start;
    printf("%d\t", a[current]);
    while(succ[current] != -1)
    {
        current = succ[current];
        printf("%d\t", a[current]);
    }
    printf("<EOS>..\n");
}

int main()
{
    int a[SIZE];
    srand(1729);
    randomizeArr(a, SIZE);
   // printArr(a, SIZE);
    int i;
    printf("\n\n");

    int pred[SIZE];
    int length[SIZE], succ[SIZE];
    for(i=0; i<SIZE; i++)
        succ[i] = -1;
    length[0] = 1;
    pred[0] = -1;

    for(i=1; i<SIZE; i++)
        setlength(a,length,pred,i);

    int start = getsequence(length, pred, a, SIZE, succ);
    printSequence(a, succ, start);


    return 0;
}
