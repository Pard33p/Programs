#include<stdio.h>
#define MAX 20
int arr[MAX];
void main()
{
    int n , i , beg , end , pivot;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    for(i = 0 ;i < n ;i++)
       scanf("%d",&arr[i]);
     quick(0,n-1);
     for(i = 0; i<n;i++)
        printf("%d ",arr[i]);
     printf("\n");
}
void quick(int low , int high)
{
    int pivot;
    if(low >= high)
        return;
    else
    {
        pivot = partition(low,high);
        quick(low , pivot-1);
        quick(pivot + 1, high);
    }
}
int partition(int beg , int end)
{
    int i, j, pivot,temp;
    pivot = arr[beg];
    i = beg + 1;
    j = end;
    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
        else
            i++;
    }
    arr[beg] = arr[j];
    arr[j] = pivot;
    return j;
}

