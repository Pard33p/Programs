#include <stdio.h>

int main()
{
    long int n;
    scanf("%ld",&n);
    long long int a , check = 0 , deg = 0;

    for(int i = 0 ; i <= n ; i++)
    {
        scanf("%lld",&a);
        if(a != 0)
          {
              check = a;
              deg = i;
          }
    }
    if(check == 0)
      printf("0 0\n");
    else
    {
      if(check > 0)
         printf("1 ");
      else
         printf("-1 ");
      if((check > 0 && (deg % 2 == 0)) || (check < 0 && (deg % 2 != 0))  )
         printf("1\n");
      else
         printf("-1\n");
    }
    return 0;
}

