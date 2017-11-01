#include<stdio.h>
void main()
{
   int n;
   scanf("%d",&n);

   printf("Sum is : %d\n",recSum(n));
}
int recSum(int n)
{
    int item;
    printf("\nEnter the number : ");
    scanf("%d",&item);
    if(n == 1)
        return item;
    return (item + recSum(n-1));
}
