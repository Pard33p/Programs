#include<stdio.h>
struct node
{
    int exp;
    int coeff;
    struct node *link;
};
struct node *ins(struct node *start,int co,int ex);
struct node *mul(struct node *,struct node *);
struct node *create(struct node *start,int co,int ex);
void display(struct node *start);
struct node *add(struct node *,struct node *);
void main()
{
    int d1,item,d2;
    struct node *start1 = NULL,*start2 = NULL,*start3 = NULL,*start4 = NULL;
    printf("Enter the degree of 1st Polynomial : ");
    scanf("%d",&d1);
    while(d1 >-1)
    {
        printf("\nEnter the coefficient of x^%d : ",d1);
        scanf("%d",&item);
        start1 = create(start1,item,d1);
        d1--;
    }
     printf("\nEnter the degree of 2nd Polynomial : ");
    scanf("%d",&d2);
    while(d2 >-1)
    {
        printf("\nEnter the coefficient of x^%d : ",d2);
        scanf("%d",&item);
        start2 = create(start2,item,d2);
        d2--;
    }
    printf("\n1st Polynomial : ");
    display(start1);
    printf("\n2nd Polynomial : ");
    display(start2);
    printf("\nAddition : ");
    start3 = add(start1,start2);
    display(start3);
    printf("\nMultiplication : ");
    start4 = mul(start1,start2);
    display(start4);
}
struct node *create(struct node *start,int co,int ex)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->exp = ex;
   temp->coeff = co;
   if(start == NULL)
   {
       temp->link = NULL;
       start = temp;
       return start;
   }
   else
   {
      struct node *p = start;
       while(p->link != NULL)
        p = p->link;
       temp->link = NULL;
       p->link = temp;
       return start;
   }
}
void display(struct node *start)
{
    struct node *p;
    p = start;
    while(p != NULL)
    {
        printf("%dx^%d ",p->coeff,p->exp);
        if(p->link != NULL)
            printf("+ ");
        p = p->link;
    }
    printf("\n");
}
struct node *add(struct node *start1,struct node *start2)
{
    struct node *p1,*p2,*start = NULL;
    p1 = start1;
    p2 = start2;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp > p2->exp)
        {
            start = create(start,p1->coeff,p1->exp);
            p1 = p1->link;
        }
        else if(p2->exp > p1->exp)
        {
            start = create(start,p2->coeff,p2->exp);
            p2 = p2->link;
        }
        else if(p1->exp == p2->exp )
        {
            start = create(start,p1->coeff + p2->coeff,p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    return start;

}
struct node *mul(struct node *start1,struct node *start2)
{
   struct node *start = NULL,*p,*p1,*p2;
   p1 = start1;
   p2 = p = start2;
   while(p1 != NULL)
   {
       p2 = p;
       while(p2 != NULL)
       {
           start = ins(start,p1->coeff * p2->coeff,p1->exp + p2->exp);
           p2 = p2->link;
       }
       p1 = p1->link;
   }
   return start;
}
struct node *ins(struct node *start,int co,int ex)
{
    if(start == NULL)
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = co;
        temp->exp  = ex;
        temp->link = NULL;
        start = temp;
        return start;
    }
    struct node *p = start;
    while(p != NULL)
    {
        if(p->exp == ex)
        {
            p->coeff += co;
            return start;
        }
        p = p->link;
    }
    p = start;
    while(p->link != NULL)
        p = p->link;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff  = co;
    temp->exp = ex;
    temp->link = NULL;
    p->link = temp;
    return start;
}
