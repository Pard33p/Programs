#include<stdio.h>
void insert(int num , int arr[] , int *size);
int del(int arr[] , int *size);
void restoreUp(int arr[] , int loc);
void restoreDown(int arr[] , int i , int size);
void buildHeap(int arr[] , int size);

int main()
{
    int i, n , arr[20];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        printf("Enter element : ");
        scanf("%d",&arr[i]);
    }
    heapSort(arr , n);
    for(i = 1; i <= n ; i++)
        printf("%d  ",arr[i]);
}

void insert(int num , int arr[] , int * size)
{
    (*size)++;
    arr[*size] = num;
    restoreUp(arr , *size);
}

void restoreUp(int arr[] , int loc)
{
    int k = arr[loc];
    int parLoc = loc / 2;

    while(arr[parLoc] < k && parLoc >= 1)
    {
        arr[loc] = arr[parLoc];
        loc = parLoc;
        parLoc = loc/2;
    }
    arr[loc] = k;
}

int del(int arr[] , int *size)
{
   int max = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    restoreDown(arr , 1 , *size);
    return max;
}
void restoreDown(int arr[] , int i , int size)
{
    int lchild = 2 * i;
    int rchild = lchild + 1;
    int num = arr[i];

    while(rchild <= size)
    {
        if(num >= arr[lchild] && num >= arr[rchild])
        {
            arr[i] = num;
            return;
        }
        else if(arr[lchild] > arr[rchild])
        {
            arr[i] = arr[lchild];
            i = lchild;
        }
        else
        {
            arr[i] = arr[rchild];
            i = rchild;
        }
        lchild = i * 2;
        rchild = lchild + 1;
    }
    if(lchild == size && num < arr[lchild])
    {
        arr[i] = arr[lchild];
        i = lchild;
    }
    arr[i] = num;
}
void buildHeap(int arr[] , int size)
{
    int i;
    for(i = size/2 ; i >= 1 ; i--)
        restoreDown(arr , i , size);
}
void heapSort(int arr[] , int size)
{
    int max;
    buildHeap(arr , size);
   // printf("Heap is : ");
    while(size > 1)
    {
        max = del(arr , &size);
        arr[size + 1] = max;
    }
}
