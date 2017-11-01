#include<stdio.h>
#define MAX 10
int arr[MAX][2];
int front = -1 , rear = -1;

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
void insert(int item , int prio)
{
    if(front == 0 && rear == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = rear = 0;
    else
        rear++;
    arr[rear][0] = item;
    arr[rear][1] = prio;
}
int delH()
{
    if(rear == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    int i ,item, j , max = 100;
    for(i = front; i <= rear; i++)
    {
        if(max > arr[i][1])
            max = arr[i][1];
    }
    for(i = front; i <=rear; i++)
    {
        if(arr[i][1] == max)
        {
            item = arr[i][0];
            for(j = i; j < rear; j++)
            {
              arr[i][0] = arr[i+1][0];
              arr[i][1] = arr[i+1][0];
            }
            rear--;
            return item;
        }
    }
}
int delL()
{
    if(rear == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    int i ,item, max = 0 , j;
     for(i = front; i <= rear; i++)
    {
        if(max < arr[i][1])
            max = arr[i][1];
    }
    for(i = front; i <=rear; i++)
    {
        if(arr[i][1] == max)
        {
            item = arr[i][0];
            for(j = i; j < rear; j++)
            {
              arr[i][0] = arr[i+1][0];
              arr[i][1] = arr[i+1][0];
            }
            rear--;
            return item;
        }
    }
}
void display()
{
    if(rear == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    int i;
    printf("\nItem\tPriority\n");
    for(i = front; i <= rear ; i++)
    {
        printf("%d\t%d\n",arr[i][0],arr[i][1]);
    }
}
