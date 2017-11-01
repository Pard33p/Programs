#include<stdio.h>
int main()
{
    int i , n , arr[20];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    printf("Sum of even numbers is %d\n",recSum(arr , n-1));
}
int recSum(int arr[] , int n)
{
    if(n < 0)
        return 0;
    if(arr[n] % 2 == 0)
        return (arr[n] + recSum(arr , n - 1));
    else
        return recSum(arr, n - 1);
}
