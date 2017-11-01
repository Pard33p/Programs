#include<stdio.h>
int main()
{
    int a , b;
    scanf("%d%d",&a,&b);
    printf("%d %% %d is %d\n",a,b,mod(a,b));

}
int mod(int a , int b)
{
    if(a < b)
        return a;
    return mod(a-b , b);
}
