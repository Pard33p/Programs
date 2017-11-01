#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start1 = NULL,*start2 = NULL;
void insEnd(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start1 == NULL)
    {
        temp->link = NULL;
        start1 = temp;
        return;
    }
    struct node *p;
    p = start1;
    while(p->link)
        p = p->link;
    temp->link = NULL;
    p->link = temp;
    return;
}
void display(struct node *start)
{
    struct node *p = start;
    while(p)
    {
        printf("%d ",p->info);
        p = p->link;
    }
}
void negPos()
{
    struct node *p = start1, *temp;
    while(start1->info < 0)
    {
        temp = start1;
        start1 = start1->link;
        if(start2 == NULL)
            {
                start2 = temp;
                temp->link = NULL;
            }
         else
         {
             struct node *q = start2;
             while(q->link != NULL)
                q = q->link;
             temp->link = NULL;
             q->link = temp;
         }
    }
    p = start1;
    while(p->link != NULL)
    {
        if(p->link->info < 0)
        {
            temp = p->link;
            p->link = temp->link;
           if(start2 == NULL)
            {
                start2 = temp;
                temp->link = NULL;
            }
         else
         {
             struct node *q = start2;
             while(q->link != NULL)
                    q = q->link;
             temp->link = q->link;
             q->link = temp;
         }

        }
        if(p->link == NULL)
            break;
        p = p->link;
    }
}
void shift(int item,int n)
{
        struct node *p = start1,*temp;
        if(start1->info == item)
        {
            temp = start1;
            start1 = start1->link;
        }
        else
        {
            while(p->link->info != item && p->link != NULL)
            p = p->link;
            temp = p->link;
            p->link = temp->link;
        }
        while(n--)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
}
void main()
{
    int n, item;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    while(n--)
    {
        printf("\nEnter the element : ");
        scanf("%d",&item);
        insEnd(item);
    }
    display(start1);
    /*negPos();
    printf("\n");
    display(start2);
    printf("\n");*/
    printf("\nEnter the element you want to shift : ");
    scanf("%d",&item);
    printf("\nEnter the n : ");
    scanf("%d",&n);
    shift(item,n);
    display(start1);
}
