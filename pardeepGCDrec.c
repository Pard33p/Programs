#include<stdio.h>
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    else
        GCD(b,a%b);
}
void main()
{
    int a, b;
    printf("Enter a & b : ");
    scanf("%d%d",&a,&b);
    if(a < b)
    {
       int temp = a;
        a = b;
        b = temp;
    }
    printf("GCD of %d & %d is %d\n",a,b,GCD(a,b));
}
