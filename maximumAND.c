#include<stdio.h>
void main()
{
    int t;
    long long int a , b , ans;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%lld%lld",&a , &b);
        if(b % 2 == 0)
           ans = (b - 2) & (b - 1);   //can also be written as (ans = b -2 ;)
         else
            ans = (b - 1) & b;    // can also be written as (ans = b - 1;)
         if(ans >= a)          // if ans is in range [a , b] then print ans
            printf("%lld\n",ans);
         else                                  //otherwise a & b will be maximum
            printf("%lld\n",a & b);
    }
}
