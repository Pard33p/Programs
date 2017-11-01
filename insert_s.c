#include<stdio.h>
struct node
{
    int info;
    struct node *link;
};
struct node *insert_s(struct node *start, int data);
void display(struct node *start);
void main()
{
    struct node *start;
    start = NULL;
    int i,n,data;
    printf("Create List :\n");
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter node: ");
        scanf("%d",&data);
        start = insert_s(start,data);
    }
    display(start);
}
struct node *insert_s(struct node *start, int data)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    if(start == NULL || data < start->info)
    {
        temp->link = start;
        start = temp;
        return start;
    }
    else
    {
        p = start;
        while(p->link != NULL && p->link->info < data)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}
void display(struct node *start)
{
    struct node *p;
    p = start;
    while(p != NULL)
    {
        printf("%d ",p->info);
        p = p->link;
    }
}
