#include<stdio.h>
long long int fact(int n);
void main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Factorial : %lld",fact(n));
}
long long int fact(int n)
{
    if(n == 0)
      return 1;
    else
        return n * fact(n-1);
}

