#include <stdio.h>
#include <stdlib.h>

long long int factorial(int n)
{
    long long int factorial = 1;
    int i=1;
    for(i=1; i<=n; ++i)
        factorial*=i;
    return factorial;
}

int factorial2(int n){
    int factorial[] = {1,2,6,24,120,720,5040,40320,362880,3628800};
    return factorial[n-1];
}

const static int factorialArr[] = {1,2,6,24,120,720,5040,40320,362880,3628800};
int factorial3(int n)
{
    return factorialArr[n-1];
}

int factorion(int n)
{
    long long int sum = 0;
    int digit, original = n;
    while(n!=0)
    {
        digit = n%10;
        sum+=factorial3(digit);
        n = n/10;
    }
    if(original == sum)
        return 1;
    return 0;
}


int main()
{
    int i=0;
    for(i=32000000; i<=40000000; ++i)
        if(factorion(i))
            printf("Yay. %d is a factorion!\n",i);
    return 0;
}
