#include <stdio.h>
#include <stdlib.h>

#define abs(x) x>0? x: -x


int main()
{
    float a1, a2, nf;
    int n;
    scanf("%d",&n);
    a1 = (float)n; nf = (float)n; a2 = (a1 + nf/a1)/2;
    while(abs(a1-a2) > 0.000001)
    {
        a1 = a2;
        a2 = (a1 + nf/a1)/2;
    }

    if(a2 == (int)a2)
    {
        printf("\nApproximate square root = %d.\n",(int)a2);
        return (int)a2;
    }

    printf("\nApproximate square root = %f.\n",a2);

    return (int)a2;
}
