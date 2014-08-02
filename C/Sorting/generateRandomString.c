#ifndef RANDOM
#define RANDOM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void rand_s(int length, char *s)
{
    srand(id_no);
    int i;
    char a[length];
    for(i=0; i<length; i++)
    {
        a[i] = (char)(rand()%26 + 97);
    }
    strcpy(s,a);
}

int main()
{
    char lol[10];
    strcpy(lol,rand_s(10));
    puts(lol);
    return 0;
}

#endif
