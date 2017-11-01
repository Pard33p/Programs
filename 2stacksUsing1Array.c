#include<stdio.h>
#define MAX 10

int stack[10];
int top1 = -1, top2 = MAX;

 void main()
 {
     int choice,item;
     while(1)
     {
         printf("\n1.Push A\n2.Pop A\n3.Display A\n4.Push B\n5.Pop B\n6.Display B\n");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
            printf("Enter the element  to push : ");
            scanf("%d",&item);
            push1(item);
            break;
         case 2:
            printf("Popped item is %d\n",pop1());
            break;
          case 3:
              display1();
              break;
           case 4:
            printf("Enter the element  to push : ");
            scanf("%d",&item);
            push2(item);
            break;
         case 5:
            printf("Popped item is %d\n",pop2());
            break;
          case 6:
              display2();
              break;
          default:
            exit(0);

         }
     }
 }
void push1(int item)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return ;
    }
    stack[++top1] = item;
}
int pop1()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top1--];
}
void display1()
{
    if(isEmpty())
    {
        printf("No Elements \n");
        return;
    }
    int i;
    for(i = top1;i>=0;i--)
       printf("\n%d\n",stack[i]);
}
void push2(int item)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return ;
    }
    stack[--top2] = item;
}
int pop2()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top2++];
}
void display2()
{
    if(isEmpty())
    {
        printf("No Elements \n");
        return;
    }
    int i;
    for(i = top2;i<MAX;i++)
       printf("\n%d\n",stack[i]);
}
int isEmpty()
{
    if(top1 == -1 && top2 == MAX)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top2 == top1+1)
        return 1;
    else
        return 0;
}
