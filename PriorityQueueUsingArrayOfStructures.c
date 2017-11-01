#include<stdio.h>
#define MAX 10
struct queue
{
    int info;
    int priority;
} arr[MAX] ;
int rear = -1;

int main()
{

    int choice , item , prio;
    while(1)
    {
        printf("\n1.Insert\n2.Delete(Highest Priority)\n3.Delete(Lowest Priority)\n4.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item : ");
            scanf("%d",&item);
            printf("Enter its Priority : ");
            scanf("%d",&prio);
            insert(item , prio);
            break;
        case 2:
            printf("Deleted Item is : %d\n",delH());
            break;
        case 3:
            printf("Deleted Item is : %d\n",delL());
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}
void insert(int item , int priority)
{
    if(isFull())
    {
        printf("Queue Full\n");
        return;
    }
    rear++;
    arr[rear].info = item;
    arr[rear].priority = priority;
}
int delH()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        exit(0);
    }
    int min = MAX , i;
    for(i = 0; i <= rear ; i++)
    {
        if(arr[i].priority < min )
            min = arr[i].priority;
    }
    //printf("Highest priority : %d",min);
    int item  ,  j;
    for(i = 0; i <= rear ; i++)
    {
        if(arr[i].priority == min)
        {
            item = arr[i].info;
            for(j = i ; j < rear ; j++)
            {
                arr[j] = arr[j+1];
            }
            rear--;
            return item;
        }
    }
}
int delL()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        exit(0);
    }
    int min = -1 , i;
    for(i = 0; i <= rear ; i++)
    {
        if(arr[i].priority > min )
            min = arr[i].priority;
    }
    int item , j;
    for(i = 0; i <= rear ; i++)
    {
        if(arr[i].priority == min)
        {
            item = arr[i].info;
            for(j = i ; j < rear ; j++)
            {
                arr[j] = arr[j+1];
            }
            rear--;
            return item;
        }
    }
}
void display()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        return ;
    }
    int i ;
    printf("\nItem\tPriority\n");
    for(i = 0 ; i <= rear ; i++)
    {
        printf("%d\t%d\n",arr[i].info , arr[i].priority);
    }
}
int isEmpty()
{
    if(rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear == MAX -1 )
        return 1;
    return 0;
}
