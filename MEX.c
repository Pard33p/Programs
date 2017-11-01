#include<stdio.h>
int main()
{
    int t;
    long int n , arr[100000] , k , i , j;
    scanf("%d",&t);
    while(t--)
    {
        int flag = 0;
        scanf("%ld%ld",&n , &k);
        for(i = 0; i < n; i++)
            scanf("%ld",&arr[i]);
        mergeSort(arr , 0 , n-1);
        for(i = 0, j = 0 ; j < n;  )
        {
            if(arr[j] == arr[j - 1] && j > 0)
                j++;
            else
            {
                   if(i != arr[j] )
                  {
                      if(k == 0)
                        break;
                     k--;
                  }
                 else
                {
                    j++;
                }
                i++;
              }
        }

        while(k > 0 )
        {
            i++;
            k--;
        }
       printf("%ld\n",i);

    }
}
void mergeSort( long int arr[] , long  int low , long int high)           //to recursively divide the array into two halves
{
    if(low < high)
    {

         long int mid = low + (high - low)/2;

        mergeSort(arr , low, mid);                       //first sub - array
        mergeSort(arr , mid + 1 , high);                //second sub - array

        merge(arr , low , mid , high);                 //merge the sorted arrays
    }
}
void merge(long  int arr[] ,long  int low, long int mid , long int high )
{
    long int n1 , n2;
    n1 = mid - low + 1;                        //number of elements in first sub array
    n2 = high - mid;                           //number of elements in second sub array
    long int L[n1] , R[n2] , i , j , k;

    for(i = 0; i < n1 ; i++)
        L[i] = arr[low + i];                     //copy elements of left sub array in temporary array L
    for(i = 0; i < n2 ; i++)
        R[i] = arr[mid + 1  + i];                //copy elements of right sub array in temporary array R
    i = 0;                                           //starting index of L
    j = 0;                                           //starting index of R
    k = low;                                       //starting index of array
    while( i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)               //if some elements left in left array, copy them in array
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)              //if some elements left in right array, copy them in array
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//and yes ! you've done it
