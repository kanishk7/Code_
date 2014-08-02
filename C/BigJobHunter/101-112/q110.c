/*
Q 20. 

You are given a 2D array of characters and a character pattern. WAP to find if pattern is present
in 2D array. Pattern can be in any way (all 8 neighbors to be considered) but you can’t use same character twice
while matching. Return 1 if match is found, 0 if not.

*/

#include "template.h"


int main()
{
	char s[3][3] = 
	{
		'a','b','c',
		'd','e','f',
		'g','h','i'
	};
	
	printf("%c %c\n",s[1][0],s[0][1]);
}
