#include<stdio.h>
static count = 0;
void main()
{
    int a , b;
    printf("Enter a & b : ");
    scanf("%d%d",&a, &b);
    CountPrime(a,b);
    printf("No. of prime no. between %d & %d are %d\n\n",a,b,count);
}
void CountPrime(int a , int b)
{
    int i ,  flag = 0;
    for(i = 2; i *i <= a; i++)
    {
        if(a % i == 0)
            flag = 1;
    }
    if(flag == 0)
        count++;
    if(a == b)
            return;
    else
          CountPrime(a+1 , b);

}
