/* sscanf example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main ()
{
  char sentence []="Rudolph is 12 years old";
  char str [5];
  int i=0;

    fgets(str,5,stdin);
    printf("%s\n",str);
    fflush(stdin);
    gets(str);
    printf("%s",str);

    return strlen(str);

}
