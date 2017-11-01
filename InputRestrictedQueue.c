#include<stdio.h>
#define MAX 10
int Q[MAX];
int front = -1 , rear = -1;

int main()
{
   int choice , item ;
   while(1)
   {
       printf("\n1.Enqueue\n2.Delete At Beginning\n3.Delete At End\n4.Display\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("Enter the element : ");
        scanf("%d",&item);
        enq(item);
        break;
       case 2:
        printf("Deleted Element is %d\n",deq());
        break;
       case 3:
        printf("Deleted Element is %d\n",deqEnd());
        break;
       case 4:
        display();
        break;
       default:
        exit(0);
       }
   }
    return 0;
}
void enq(int item)
{
    if(isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if(rear == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX -1)
        rear = 0;
    else
       rear++;
    Q[rear] = item;
}
int deq()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    int item = Q[front];
    if(front == rear)
        front = rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
    return item;
}
void display()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        return;
    }
    int i;
    if(front <= rear)
    {
        for(i = front ; i <= rear ; i++)
           printf("%d ",Q[i]);
        printf("\n");
    }
    else
    {
        for(i = front; i < MAX ; i++)
            printf("%d ",Q[i]);
        for(i = 0; i <= rear ;  i++)
            printf("%d ",Q[i]);
    }
}
int isEmpty()
{
    if(front == -1 )
        return 1;
    return 0;
}
int isFull()
{
    if((front == rear + 1) || (front == 0 && rear == MAX - 1))
        return 1;
    return 0;
}
int deqEnd()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        exit(0);
    }
    int item = Q[rear];
    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear--;
     return item;
}

