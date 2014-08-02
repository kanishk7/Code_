/*
Q7.
Implement the following function:- FindSortedArrayRotation, which takes as its input an array of
unique integers that has been first sorted in ascending order, then rotated by an unknown amount X where 0 <=
X <= (arrayLength - 1). An array rotation by amount X moves every element array[i] to array[(i + X) %
arrayLength]. The function FindSortedArrayRotation discovers and returns X by examining the array. Consider
performance, memory utilization and code clarity and elegance of the Solution when implementing the
function.
*/

#include "template.h"

#define x1 25
#define dx 7

static int size; 

void printArr(int a[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n<EOA>\n");
}

void generateSortedArr(int a[], int size)
{
	srand(time(NULL));
	int i, val = rand()%x1+1;
	for(i=0; i<size; i++)
	{
		a[i] = val;
		val = val+rand()%dx+1;
	}
}

int prev(int mid)
{
	return (mid+(size-1))%size;
}

int next(int mid)
{
	return (mid+1)%size;
}

int findX(int a[], int size)
{
	int low=0, mid, high=size-1;
	while(low < high)
	{
		mid = low + (high - low)/2;
//		printf("Low = %d. Mid = %d. High = %d.\n", low, mid, high);		
		if(a[prev(mid)] < a[mid] && a[next(mid)] < a[mid])
			return mid+1;
		if(a[mid] > a[high])
			low = mid+1;
		else
			high = mid;	
	}
	return 0;
}

void rotateArray(int a[], int size, int x)
{
	int i, b[size];
	if(x>size)
		printf("Warning! (X > size) you should not rotate by that much.\n");
	for(i=0; i<size; i++)
		b[i] = a[i];
	for(i=0; i<size; i++)
		a[(i+x)%size] = b[i];
}

int binsearch(int a[], int low, int high, int x)
{
	int i,j;
	int mid;
	
	while(low <= high)
	{
		mid = low + (high-low)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] < x)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

int BinSearch(int a[], int size, int x)
{
	return binsearch(a,0,size-1,x);
}

int value(int a[], int size, int x) 
{
	int i,j,low = 0, high = size - 1, mid;
	while(low < high)
	{
		if(a[low] <= a[high])
			return  binsearch(a,low,high,x);
		mid = low + (high-low)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] < x)
		{
			if(a[high] == x)
				return high;
			if(a[high] < x)
				high = mid - 1;
			else 
				low = mid + 1;
		}
		if(a[mid] > x)	
		{
			if(a[low] > x)
				low = mid+1;
			else if(a[low] == x)
				return low;
			else
				high = mid-1;
		}
	}
	return -1;
}

int main2()
{
	size = 10;
	int i;
	int a[size];
	generateSortedArr(a,size);
	printArr(a,size);
	scanf("%d",&i);
	printf("Index is = %d.\n",value(a,size,i));

	return 0;
}

int main()
{
//	return main2();
	size = 10;
	int i;
	int a[size];
	generateSortedArr(a,size);
//	printArr(a,size);	
	rotateArray(a,size,4);
	printArr(a,size);
	scanf("%d",&i);
	printf("Index is = %d.\n",value(a,size,i));
	return 0;
}
