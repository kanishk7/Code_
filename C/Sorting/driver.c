#include "sortdef.h"
#define MAX_ELEMENTS 400000
#define TINY 10
#define SMALL 75
#define MEDIUM 1000
#define LARGE 20000
#define LARGER 270000

int main()
{
    int a[LARGER];
    srand(7);
    randomizeArr(a,sizeof(a)/4);

    clock_t start = clock();
    //printArr(a,sizeof(a)/4);
    combsort(a,sizeof(a)/4);
    //printArr(a,sizeof(a)/4);
    printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

    return 0;
}

int main2()
{
    FILE *out;
    out = fopen("sort_analysis.txt","w");
    int t[TINY];
    int s[SMALL];
    int m[MEDIUM];
    int l[LARGE];
    int lr[LARGER];

    fprintf(out,"============================================================================");
    fprintf(out,"=============================SORT ANALYSIS==================================");


    return 0;

}

