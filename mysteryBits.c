#include<stdio.h>
#include<conio.h>
void main()
{
    long long int n , count = 0;
   while(scanf("%lld\n",&n) == 1)
    {
        count = 0;
       while(n)
      {
        n = n & (n - 1);
        count++;
      }
      printf("%lld\n",count);
    }
}
