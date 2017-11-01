#include<stdio.h>
long int fib(long int n);
int main()
{
    long int n , i;
    printf("n : ");
    scanf("%ld",&n);
    for(i = 0; i < n ; i++)
        printf("%ld ",fib(i));
    printf("\n");

    return 0;
}
long int fib(long int n)
{
    if(n == 0 || n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
