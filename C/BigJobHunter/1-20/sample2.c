#include "template.h"

typedef struct {
  int num;
  void *nums;
  int size;
}Mystruct;

Mystruct *mystruct(int num, int size)
{ 
   //Is the following correct? Is there a more efficient way?
   Mystruct mystruct;
   mystruct.num = num;
   mystruct.size = size;
   mystruct.nums = malloc(num*sizeof(size));
   Mystruct *my;
   my = &mystruct;
   return my;
}

int main()
{
	Mystruct* a = mystruct(6,6);
	printf("%d %d.\n",a->num, a->size);
	return 0;
}
