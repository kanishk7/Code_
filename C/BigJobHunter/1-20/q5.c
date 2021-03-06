#include "template.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void randomizeUniformArr(int a[], int size, int seed)
{
    int i, smp;
    int visited[size];
	srand(seed);

	for(i=0; i<size; i++)
		a[i] = i+1;

	for(i=0; i<size; i++)
		swap(&a[rand()%size], &a[rand()%size]);
    return;
}

void printArr(int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n<EOA>\n");
    return;
}

int main()
{
	int size = 20;
	int a[size];
	randomizeUniformArr(a,size,17);
	printArr(a,size);
	int even = 0, odd = 1;
	while(odd != size-1)
	{
		while(a[odd]%2 == 0)
		{
			odd = odd + 2;
			if(odd > size)
				goto end;
		}
		while(a[even]%2 == 1)
		{
			even = even + 2;
			if(even > size)
				goto end;	
		}
		swap(&a[odd],&a[even]);			
	}
	end:
	printf("YOLO.\n");
	printArr(a,size);

	return 0;
}






