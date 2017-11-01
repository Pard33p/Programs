#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(div(n , 1) == n)
        printf("Yes, It is Perfect Number\n");
    else
        printf("No, It is not Perfect Number\n");
}
int div(int n , int k)
{
    if(k  > n / 2)
        return 0;
    if(n % k == 0)
    {
        return (k + div(n , k+1));
    }
    else
        return (div(n , k + 1));
}

