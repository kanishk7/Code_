//Q 31. Convert a hexadecimal string to an integer

#include "template.h"

long long int CharValue(char c)
{
	if(c >= '0' && c<='9')
		return (c-48);
	if(c >= 'a' && c<='f')
		return (c-87);
	if(c >= 'A' && c<='F')
		return (c-55);		
	else
	{
		printf("Invalid String. Exiting.\n");
		return;	
	}		
}

long long int htoi(char *s)
{
	int length = strlen(s);
	long long int value = 0, i = 1;
	int cur;
	for(cur = length-1; cur>=0; --cur)
	{
		value += i*CharValue(s[cur]);
		i = i*16;
	}
	printf("%lld.\n",value);
	return value;
}

int main()
{
	long long int decimal = htoi("DEADbeeF");
	return 0;
}

