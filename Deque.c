#include<stdio.h>
#define MAX 10
int Q[MAX];
int front = -1;
int rear = -1;

void main()
{
    int choice , item ;
    while(1)
    {
        printf("\n1.Insert At End\n2.Delete At Beg\n3.Display\n4.Exit\n5.Insert At Beg\n6.Delete At End\n\n");
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
            display();
            break;
        case 5:
            printf("Enter the element : ");
            scanf("%d",&item);
            ins(item);
            break;
        case 6:
            printf("Deleted Element is %d\n",del());
            break;
        default:
            exit(0);
        }
    }
}
void enq(int item)
{
   if(isFull())
   {
       printf("Queue Overflow\n");
       return;
   }
   if(front == -1)
     front++;
   if(rear == MAX-1)
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
    {
        front = rear = -1;
    }
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
        return ;
    }
    int i;
    if(front <= rear)
    {
        for(i = front; i <= rear ; i++)
            printf("\t%d\n",Q[i]);
    }
    else
    {
        for(i = front; i < MAX; i++)
            printf("\t%d\n",Q[i]);
        i = 0;
        for(i = 0;i <= rear ; i++)
            printf("\t%d\n",Q[i]);
    }
}
int isEmpty()
{
    if((front == -1 && rear == -1))
        return 1;
    else
        return 0;
}
int isFull()
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1)  )
        return 1;
    else
    return 0;
}
void ins(int item)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
        front = MAX - 1;
    else
        front--;
     Q[front] = item;
}
int del()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        exit(0);
    }
    int item = Q[rear];
    if(rear == front)
        rear = front = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear--;
    return item;
}

