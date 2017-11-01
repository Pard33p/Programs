#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start = NULL;
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow\n");
        return ;
    }
    temp->info = item;
    temp->link = start;
    start = temp;
}
int pop()
{
    if(start == NULL)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    struct node *temp = start;
    int item;
    item = temp->info;
    start = start->link;
    free(temp);
    return item;
}
void display()
{
    if(start == NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    struct node *p = start;
    while(p)
    {
        printf("\t%d\n",p->info);
        p = p->link;
    }
    printf("\n");
}
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
