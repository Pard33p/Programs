#include<stdio.h>
#include<math.h>
long long int power(long long int a , long long int b);
int main()
{
   long long int n ,i, result = 1 ,j = 2 ;
    scanf("%lld",&n);
    long long int arr[n];
    for(i = 0 ; i < n ; i++)
    {
         scanf("%lld",&arr[i]);
    }

    for(i = 0; i < n ;)
    {
        if(prime(j))
        {
            result *= power(j , arr[i]);
            i++;
        }
        j++;
    }
    long long int product = result;
    for(i = 2 ; i <= result/2 ; i++)
    {
        if(result % i == 0 )
            product *= i;
    }
    long long int num = product , num_fact = 1;
    for(i = 2 ; i * i <= product; i++)
    {
        long long int powCount = 0;
        while( num % i == 0)
        {
            num /= i;
            powCount++;
        }
      num_fact =((num_fact %  (power(10 , 9) + 7))* ((powCount + 1)  %  (power(10 , 9) + 7))) %  (power(10 , 9) + 7);
    }
    if(num > 1)
        num_fact *= 2;
    printf("%lld\n", num_fact);
}
int prime(long long int n)
{
    long int i;
    for(i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
long long int power(long long int a , long long int b)
{
     long long int temp;
     if(b == 0)
        return 1;
     temp = power(a , b/2);
     if(b % 2 == 0)
        return temp * temp;
     else
        return temp * temp * a ;
}
