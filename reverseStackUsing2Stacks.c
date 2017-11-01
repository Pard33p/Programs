#include<stdio.h>
#define MAX 10

int stack1[MAX],stack2[MAX];
int top1 = -1,top2 = -1;
 void main()
 {
     int n,i,item;
     printf("Enter the no. of elements : ");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         printf("\nEnter the element : ");
         scanf("%d",&item);
         push1(item);
     }
     printf("Stack Before Reversing :\n");
     display1();
     for(i = 0;i<n;i++)
     {
         item  = pop();
         push2(item);
     }
     printf("Stack After Reversing :\n");
     display2();
 }
void push1(int item)
{
    if(top1 == MAX-1)
    {
        printf("Stack Overflow\n");
        return ;
    }
    stack1[++top1] = item;
}
void push2(int item)
{
    if(top2== MAX-1)
    {
        printf("Stack Overflow\n");
        return ;
    }
    stack2[++top2] = item;
}

int pop()
{
    if(top1 == -1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack1[top1--];
}
void display1()
{
    if(top1 == -1)
    {
        printf("No Elements \n");
        return;
    }
    int i;
    for(i = top1;i>=0;i--)
       printf("\n%d\n",stack1[i]);
}
void display2()
{
    if(top2 == -1)
    {
        printf("No Elements \n");
        return;
    }
    int i;
    for(i = top2;i>=0;i--)
       printf("\n%d\n",stack2[i]);
}
