#include<stdio.h>
int stack_low[20] , stack_high[20];
int top = -1;

void main()
{
     int arr[] = {3,2,0,1,67,45,4} , i;
    quick(arr,7,0,6);
    for(i = 0 ; i < 7 ; i++)
        printf("%d " , arr[i] );      //prints sorted array
    printf("\n");
}
void quick(int arr[],int n,int low,int high)
{
    if(n > 1)          //if array is having more than 1 element then proceed (otherwise already sorted)
    {
        top++;                          //push the low and high index of array to the stack_low and stack_up respectively
        stack_low[top] = low;
        stack_high[top] = high;
        while(top != -1)
        {
            int beg,end,pivot;
            beg = stack_low[top];       //pop the values from stack_low and stack_up and assign them to beg and end respectively
            end = stack_high[top];
            top--;
            pivot = partition(arr,n,beg,end);   // call the function partition and store the value returned by it to pivot
            if(beg < pivot-1)            //if the left sub-array has more than 1 element then
            {                                   // push the beg to stack_low and pivot-1 to stack_up
                top++;
                stack_low[top] = beg;
                stack_high[top] = pivot-1;
            }
            if(end > pivot +1)       //if the right sub-array has more than 1 element then
            {                               //push the pivot+1 to stack_low and end to stack_up
                top++;
                stack_low[top] = pivot + 1;
                stack_high[top] = end;
            }
        }
    }
}
int partition(int arr[],int n, int low, int high)
{
    int pivot = low, i = low + 1 , j = high , temp;   //setting starting index of array as the pivot index , i = second index of array(or sub-array) and j = highest index if array
    while(i <= j)
    {
        while(( arr[i] < arr[pivot] )  &&   (i <= high) )            //increments i until the element at i is less than the pivot element
            i++;
        while(arr[j] > arr[pivot])           //decrements j until the element at j is greater than pivot element
            j--;
        if(i < j)                             //if i is less than j then swap the those elements and increment and decrement i and j respectively . Otherwise increment i
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
    pivot = j;
    //swap the element at j and pivot and return the pivot
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return pivot;
}
