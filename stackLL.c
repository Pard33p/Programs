#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;

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
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    temp->info = item;
    temp->link = top;
    top = temp;
}
int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp;
    int item;
    item = top->info;
    temp = top;
    top = top->link;
    free(temp);
    return item;
}
void display()
{
    if(top == NULL)
    {
            printf("No Stack To Display\n");
            return ;
    }
    struct node *ptr;
    ptr = top;
    while(ptr)
    {
        printf("\n%d\n",ptr->info);
        ptr = ptr->link;
    }

}
