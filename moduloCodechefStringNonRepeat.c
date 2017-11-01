#include<stdio.h>
int main()
{
    long int m , n , result;
    scanf("%ld%ld",&n,&m);
    if(n % 2 == 0)
           result = (((((n % m) * (n % m)) % m) % m) - (n % m) + m ) % m;
     else
            result = ((1 << n) % m - (2 % m) ) % m;
    printf("%ld\n",result);
}
