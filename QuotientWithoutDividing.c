#include<stdio.h>
int main()
{
    int a , b;
    scanf("%d%d",&a,&b);
    printf("%d / %d is %d\n",a,b,quo(a,b));
}
int quo(int a , int b)
{
    if(a < b)
        return 0;
    return 1 + quo(a-b , b);
}
