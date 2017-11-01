#include<stdio.h>
long int partition(long int arr[] , long int low , long int high);
void quick(long int arr[] , long int low , long int high);

int main()
{
    long int n  ,i, arr[10] , nq , q , count = 0 ,flag = 0 , temp ;
    scanf("%ld",&n);
    for(i = 0; i < n ; i++)
    {
        scanf("%ld",&arr[i]);
    }
    quick(arr , 0 , n-1);
    scanf("%ld",&nq);
    while(nq--)
    {
        scanf("%ld",&q);
        for(i = n-1 ; i > -1 && arr[i] > q; i--)
        {
            if(arr[i] % q == 0)
                count++;
        }
        printf("%ld\n",count);
    }
    /*for(i = 0; i< n ; i++)
        printf("%d ",arr[i]);*/
}
void quick(long int arr[] , long int low , long int high)
{
    int pivloc;
    if(low >= high)
        return;
    pivloc = partition(arr , low, high);
    quick(arr , low , pivloc - 1);
    quick(arr , pivloc + 1 , high);
}
long int partition(long int arr[] , long int low , long int high)
{
    long int temp , i , j , pivot;
    i  =low + 1;
    j = high;
    pivot = arr[low];
    while(i <= j)
    {
        while((arr[i] < pivot) && (i < high))
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else
            i++;
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}
