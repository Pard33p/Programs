#include<stdio.h>
long long int fact(int n,int result);
void main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Factorial : %lld",fact(n,1));
}
long long int fact(int n,int result)
{
    if(n == 0)
      return result;
    else
        return fact(n-1, n * result );
}
