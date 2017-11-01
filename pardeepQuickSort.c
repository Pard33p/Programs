#include<stdio.h>
#define MAX 20
int low[MAX] , high[MAX] , arr[MAX];
int top = -1;
void main()
{
    int n , i , beg , end , pivot;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    for(i = 0 ;i < n ;i++)
       scanf("%d",&arr[i]);
    top++;
    low[top] = 0;
    high[top] = n-1;
    while(top != -1)
    {
        beg = low[top];
        end = high[top];
        top--;
        pivot = partition(beg,end);
        if(beg < pivot-1)
        {
            top++;
            low[top] = beg;
            high[top] = pivot - 1;
        }
        if(end > pivot + 1)
        {
            top++;
            low[top] = pivot + 1;
            high[top] = end;
        }
    }
     for(i = 0; i<n;i++)
        printf("%d ",arr[i]);
     printf("\n");
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
