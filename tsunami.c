#include<stdio.h>
long long getCount(long long n);
int prime(long long int n);
int main()
{
    long long int t , l , r, i;
    scanf("%lld",&t);
    while(t--)
    {
        long long int result = 0 , count;
        scanf("%lld%lld",&l,&r);
        for(i = l; i <= r; i++)
        {
            count = getCount(i);

            if(prime(count))
                result++;
        }
        printf("%lld\n",result);
    }
}
long long getCount(long long n)
{
    long long count = 0;
    while(n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int prime(long long int n)
{
    if(n == 1)
        return 0;
    int flag = 0;
    long long int i;
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        return 0;
    else
        return 1;
}
