#include<stdio.h>
#define MAX 10
int cq_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item);
int del();
int peek();
int isEmpty();
int isFull();
void display();
void main()
{
    int choice,item;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display the front element\n");
        printf("4.Display all queue elements\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter item to be inserted : ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            item = del();
            printf("Deleted item is %d\n",item);
            break;
        case 3:
            printf("Item at the front is %d\n",peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
}
void insert(int item)
{
    if(isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    if(rear == MAX-1)
        rear = 0;
    else
       rear = rear+1;
    cq_arr[rear] = item;
}
int del()
{
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = cq_arr[front];
    if(front == rear)
    {
        front = -1;
         rear = -1;
    }
    else if(front == MAX-1)
        front = 0;
    else
        front = front+1;
    return item;
}
int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return cq_arr[front];
}
int isEmpty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if((front==0 && rear==MAX-1) || (front == rear+1))
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    i = front;
    if(front <= rear)
    {
    while(i<=rear)
        printf("%d ",cq_arr[i++]);
    }
    else
    {
        while(i <= MAX-1)
            printf("%d ",cq_arr[i++]);
        i = 0;
        while(i <= rear)
            printf("%d ",cq_arr[i++]);
    }
    printf("\nPress any key to return ");
    scanf("%d",&i);
}


