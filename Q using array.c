#include<stdio.h>
#define MAX 10
int q_arr[MAX];
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
    rear = rear+1;
    q_arr[rear] = item;
}
int del()
{
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = q_arr[front];
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
    return q_arr[front];
}
int isEmpty()
{
    if(front == -1 || front == rear+1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear == MAX-1)
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
    for(i = front;i <= rear ;i++)
        printf("%d ",q_arr[i]);
    printf("\nPress any key to return ");
    scanf("%d",&i);
}

