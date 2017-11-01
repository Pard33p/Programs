#include<stdio.h>
long int arr[100];
long int count = 0;
long int partition(long int beg ,long int end);
int main()
{
    long int n , t , i;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i = 0; i < n ; i++)
            scanf("%ld",&arr[i]);
         quick(0 , n-1);
          for(i = 0; i < n ; i++)
            printf("%ld ",arr[i]);
         printf("%ld\n",count);
    }
}


void quick(long int low ,long int high)
{
    long int pivot;
    if(low >= high)
        return;
    else
    {
        pivot = partition(low,high);
        quick(low , pivot-1);
        quick(pivot + 1, high);
    }
}
long int partition(long int beg ,long int end)
{
    long int i, j, pivot,temp;
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
            count++;

        }
        else
            i++;
         printf("Hello");
    }
    arr[beg] = arr[j];
    arr[j] = pivot;
    return j;
}
