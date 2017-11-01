#include<stdio.h>
int delRoot(int arr[] , int *size);
void restoreDown(int arr[] , int i , int size);
void buildHeap(int arr[] , int size);
void heapSort(int arr[] , int size);

int main()
{
    int n , arr[100] , i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i = 1;i <= n ; i++)
        scanf("%d",&arr[i]);
    printf("\nUnsorted Array : \n");
    display(arr , n);
    printf("\nSorted Array : \n");
    heapSort(arr , n);
    display(arr , n);
}
int delRoot(int arr[] , int *size)
{
    int k = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    restoreDown(arr , 1 , *size);
    return k;
}
void buildHeap(int arr[] , int size)
{
    int i;
    for(i = size/2; i>=1; i--)
        restoreDown(arr , i , size);
}
void heapSort(int arr[] , int size)
{
    int max;
    buildHeap(arr , size);
    while(size > 1)
    {
        max = delRoot(arr , &size);
        arr[size+1] = max;
    }
}
void restoreDown(int arr[] , int i , int size)
{
    int lchild = 2 * i , rchild = lchild + 1 , num = arr[i];
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
        lchild = 2 * i;
        rchild = lchild + 1;
    }
    if(lchild == size && num < arr[lchild])
    {
        arr[i] = arr[lchild];
        i = lchild;
    }
    arr[i] = num;
}
void display(int arr[] , int size)
{
    int i;
    printf("\n");
    for(i = 1; i <= size ; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

