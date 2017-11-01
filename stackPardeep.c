//stack implementation using array
#include<stdio.h>
#define MAX 10
int top = -1;
int stack[MAX];
void  main()
{
    int choice , item ;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element : ");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            printf("Popped Element is %d\n",pop());
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}
void push(int item)
{
    if(isFull())
    {
        printf("Stack Overflow !! \n");
        return;
    }
    stack[++top] = item;
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}
void display()
{
    if(isEmpty())
    {
        printf("Stack Empty\n");
        return;
    }
    int i;
    for(i = top; i>-1;i--)
        printf("\t%d\n",stack[i]);
    printf("\n");
}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
