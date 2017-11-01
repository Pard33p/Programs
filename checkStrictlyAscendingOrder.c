#include<stdio.h>
int main()
{
      int i , n , arr[20];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    if(check(arr, n-1))
        printf("Array is in ascending order \n");
    else
        printf("Array is not in ascending order\n");
}
int check(int arr[] , int n)
{
    if(n == 0)
        return 1;
    if(arr[n] > arr[n-1])
        return check(arr , n-1);
    else
        return 0;
}
