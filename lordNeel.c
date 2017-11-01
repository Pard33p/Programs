#include<stdio.h>
int main()
{
    int t;
    long long int n , a[100],i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld" ,&n);
        for(i = 0; i < n ; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i = 1; i < n ; i++)
        {
            if(i % 2 != 0)
            {
                a[i] += a[0];

            }
            else
            {
                a[i] = 0;
            }
        }
        long long int sum = 0 , dif = 0;
        for(i = 0; i < n; i++)
        {
            if(i != n-1)
               {
                   dif = a[i] > a[i + 1] ? a[i] - a[i + 1] : a[i + 1] - a[i];
                   sum += dif ;
               }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
