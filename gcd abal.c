#include <stdio.h>
long int gcd(long int a , long int b);
int main()
{
    long int n ,i, q , l , r;
    scanf("%ld",&n);
    long int arr[n];
    for( i = 0; i < n ; i++ )
      scanf("%ld",&arr[i]);
    long int max , index , temp;
    max = arr[n-1] > arr[n-2] ? gcd(arr[n-1], arr[n-2]) : gcd(arr[n-2] , arr[n-1]);
    index = n-2;
    temp = max;
    for( i = n-3; i >=0; i--)
    {
        temp = temp > arr[i] ? gcd(temp,arr[i]) : gcd(arr[i] , temp);
        if(temp > max)
          {
              max = temp;
              index = i;
          }
    }
    printf("%ld\n",index + 1);
    scanf("%ld",&q);
    while(q--)
    {
      scanf("%ld%ld",&l,&r);
      max = arr[r] > arr[r-1] ? gcd(arr[r], arr[r-1]) : gcd(arr[r-1] , arr[r]);
      temp = max;
      for( i = r-2; i >= l; i-- )
      {
         temp = temp > arr[i] ? gcd(temp,arr[i]) : gcd(arr[i] , temp);
        if(temp > max)
          {
              max = temp;
          }
      }
      printf("%ld\n",max);
    }
return 0;
}
long int gcd(long int a , long int b)
{
    if(b == 0)
      return a;
    return gcd(b , a%b);

}
