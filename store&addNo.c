#include<stdio.h>
struct node
{
    int info;
    struct node *link;
};
struct node *insEnd(struct node *start,int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)
    {
        temp->link = NULL;
        start = temp;
        return start;
    }
    struct node *p;
    p = start;
    while(p->link)
        p = p->link;
    temp->link = NULL;
    p->link = temp;
    return start;
}
void display(struct node *start)
{
    struct node *p = start;
    while(p)
    {
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n");
}
void main()
{
    struct node *start1 = NULL , *start2 = NULL ,*start3 = NULL;
    int a,b;
    printf("Enter the numbers : ");
    scanf("%d%d",&a,&b);
    while(a > 0 )
    {
      start1 = insEnd(start1,a%10);
        a /= 10;
    }
    while(b > 0)
    {
        start2 = insEnd(start2,b%10);
        b /= 10;
    }
    display(start1);
    display(start2);
    int carry = 0,sum = 0;
    struct node *p = start1 , *q = start2;
    while( p && q)
    {
        sum = p->info + q->info + carry;
        carry = sum/10;
        if(carry > 0)
            sum -= 10;
        start3 = insEnd(start3 , sum );
        p = p->link;
        q = q->link;
    }
    if(p == NULL && q == NULL && carry > 0)
        start3 = insEnd(start3,carry);
    while(p)
    {
        start3 = insEnd(start3,p->info + carry);
        carry = 0;
        p = p->link;
    }
    while(q)
    {
        start3 = insEnd(start3,q->info + carry);
        carry = 0;
        q = q->link;
    }

    display(start3);
}
