#include<stdio.h>
void sieve(int n);
int sum = 0;
int main()
{
    int t , l ,r, i;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d%d",&l,&r);
        for(i = l; i <= r ; i++)
        {
            sieve(i);
        }
        printf("%d\n",sum);
    }
}
void sieve(int n)
{
    int prime[n + 1] , i , j;
    for(i = 0; i < n+1; i++)
        prime[i] = 1;
    for(i = 2 ; i * i <= n; i++)
    {
        if(prime[i] == 1)
        {
            for(j = i * 2; j <= n; j+= i)
                prime[j] = 0;
        }
    }
    for(i = 2; i <=n; i++)
    {
        if(prime[i] == 1 && n % i == 0)
            {

                if(i / 10 == 0)
                    sum += i;
                else
                {
                    int k = i;
                    while(k > 0)
                    {
                        sum += k % 10;
                        k /= 10;
                    }
                }
            }
    }
}
