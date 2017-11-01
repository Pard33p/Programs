#include<stdio.h>
int main()
{
    int a , b;
    scanf("%d%d",&a,&b);
    printf("%d x %d is %d\n",a,b,mul(a,b));
}
int mul(int a , int b)
{
    if(a == 1)
         return b;
     if(a % 2 == 0)
        return mul(a/2 , b*2);
     else
        return b + mul(a/2 , b * 2);

}
