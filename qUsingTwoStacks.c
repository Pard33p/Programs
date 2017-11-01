#include<stdio.h>
#define MAX 10

int main()
{
    int top1 = -1 , top2 = -1 , stack1[MAX] ,stack2[MAX];
    int choice , item;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item : ");
            scanf("%d",&item);
            push(stack1 , &top1 , item);
            break;
        case 2:
            while(top1 > 0)
                push(stack2 , &top2 , pop(stack1 , &top1));
             printf("Element deleted is %d\n",pop(stack1 , &top1));
             while(top2 > -1)
                    push(stack1 , &top1 , pop(stack2 , &top2));
             break;
        case 3:
            display(stack1 , top1);
            break;
        default:
            exit(0);
        }

    }
}
void push(int stack[] , int *top , int n)
{
    if(*top == MAX - 1 )
    {
        printf("Queue Overflow\n");
        return;
    }
    stack[++(*top)] = n;
}
int pop(int stack[] , int *top)
{
    if(*top == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    return stack[(*top)--];
}
void display(int stack[] , int top)
{
    if(top == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    int i;
    for(i = 0; i <= top; i++)
        printf("%d\t",stack[i]);
    printf("\n");
}
