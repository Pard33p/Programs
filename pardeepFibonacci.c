#include<stdio.h>
int fibonacci(int n)
{
    if(n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
void main()
{
    int n;
    printf("Enter the n : ");
    scanf("%d",&n);
    printf("%d\n",fibonacci(n-1));
}
