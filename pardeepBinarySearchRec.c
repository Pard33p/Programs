#include<stdio.h>
int flag = 0;
void main()
{
    int arr[20] , item, n , i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i = 0; i<n ;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element you want to search : ");
    scanf("%d",&item);
    search(arr,0,n-1,item);
    if(flag == 0)
        printf("Element Not Found\n");
}
void search(int arr[] , int low, int high , int item)
{
    int mid;
    mid = low + (high - low)/2;
    if(arr[mid] == item)
    {
        printf("Item found at position %d\n",mid+1);
        flag = 1;
        return;
    }
    else if(low < high)
    {
        search(arr,low,mid-1,item);
        search(arr,mid+1,high,item);
    }
    else
        return;
}
