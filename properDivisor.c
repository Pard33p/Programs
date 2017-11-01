#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("\nSum of proper divisors is %d\n",div(n , 1));
}
int div(int n , int k)
{
    if(k  > n / 2)
        return 0;
    if(n % k == 0)
    {
        printf("%d ",k);
        return (k + div(n , k+1));
    }
    else
        return (div(n , k + 1));
}
