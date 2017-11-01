#include<stdio.h>
void main()
{
    int i , n;
    scanf("%d",&n);
    for(i = 1; i <= n ; i++)
        printf("%d ",fib(i , 0 , 1));

}
int fib(int n , int a , int b)
{
    if(n == 0 || n == 1)
        return b;
    else
        return fib(n - 1 , b , a + b);
}
