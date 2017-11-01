#include<stdio.h>
#define MAX 10

int stack[MAX];
int top = MAX;
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
            printf("Enter the element  to push : ");
            scanf("%d",&item);
            push(item);
            break;
         case 2:
            printf("Popped item is %d\n",pop());
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
    stack[--top] = item;
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top++];
}
void display()
{
    if(isEmpty())
    {
        printf("No Elements \n");
        return;
    }
    int i;
    for(i = top;i<=MAX-1;i++)
       printf("\n%d\n",stack[i]);
}
int isEmpty()
{
    if(top == MAX)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == 0)
        return 1;
    else
        return 0;
}
