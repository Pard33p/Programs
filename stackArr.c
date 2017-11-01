#include<stdio.h>
#define MAX 10
int stack[MAX] , top = -1;

void main()
{
   int choice,item;
   while(1)
   {
       printf("\n1.Push\n2.Pop\n3.Display\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("Enter the element to push : ");
        scanf("%d",&item);
        push(item);
        break;
       case 2:
         printf("Popped Element is : %d\n",pop());
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
        printf("Stack Overflow\n");
        return ;
    }
    stack[++top] = item;
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("No Stack To Show\n");
        return;
    }
    for(i = top; i>-1;i--)
        printf("%d\n",stack[i]);
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
