#include<stdio.h>
int main()
{
      int i , n , arr[20];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    printf("Sum of array elements is %d\n",recSum(arr ,0 , n-1 ));
}
int recSum(int arr[] , int low , int high)
{
    if( low == high)
        return arr[low];
    return recSum(arr , low , (low + high)/2 ) + recSum(arr , 1 + (low+high)/2 , high);
}
