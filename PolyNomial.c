#include<stdio.h>
struct node
{
    int exp;
    int coeff;
    struct node *link;
};
struct node *create(struct node *start,int n);
struct node *ins(struct node *start, int ex , int co);
struct node *insM(struct node *start, int ex, int co);
void display(struct node *start);
struct node *mul(struct node *start1,struct node *start2);
struct node *add(struct node *start1,struct node *start2);
void main()
{
    struct node *start1 = NULL,*start2 = NULL,*start3 = NULL,*start4 = NULL;
    int choice,n;
    while(1)
    {
        printf("1.Create List 1\n2.Create List 2\n3.Add\n4.Multiply\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the highest degree : ");
            scanf("%d",&n);
            while(n>=0)
            {
                start1 = create(start1,n);
                 n--;
            }
            display(start1);
            break;
        case 2:
            printf("\nEnter the highest degree : ");
            scanf("%d",&n);
            while(n>=0)
            {
                start2 = create(start2,n);
                 n--;
            }
            display(start2);
            break;
        case 3:
            start3 = add(start1,start2);
            display(start3);
            break;
        case 4:
            start4 = mul(start1,start2);
            display(start4);
            break;
        default:
            exit(0);
        }
    }
}

struct node *create(struct node *start,int n)
{
    struct node *p; int c;
         printf("\nEnter the coefficient of x^%d : ",n);
         scanf("%d",&c);
         struct node *temp;
         temp = (struct node *)malloc(sizeof(struct node));
         temp->coeff = c;
         temp->exp = n;
         if(start == NULL)
         {
             temp->link = NULL;
             start = temp;
         }
         else
         {
             p = start;
             while(p->link != NULL)
                p = p->link;
             temp->link = NULL;
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
       printf(" %dx^%d ",p->coeff,p->exp);
         if(p->link != NULL)
            printf("+");
       p = p->link;
    }
  printf("\n");
}
struct node *add(struct node *start1,struct node *start2)
{
   struct node *start3 = NULL,*p1 = start1,*p2 = start2;
   while(p1 != NULL && p2 != NULL)
   {
       if(p1->exp > p2->exp)
       {
           start3 = ins(start3,p1->exp,p1->coeff);
           p1 = p1->link;
       }
       else if(p2->exp > p1->exp)
       {
           start3 = ins(start3,p2->exp,p2->coeff);
           p2 = p2->link;
       }
       else if(p2->exp == p1->exp)
       {
           start3 = ins(start3,p1->exp,p1->coeff + p2->coeff);
           p1 = p1->link;
           p2 = p2->link;
       }
   }
   while(p1 != NULL)
   {
       start3 = ins(start3,p1->exp,p1->coeff);
       p1 = p1->link;
   }
   while(p2 != NULL)
   {
       start3 = ins(start3,p2->exp,p2->coeff);
       p2 = p2->link;
   }
   return start3;
}
struct node *ins(struct node *start, int ex , int co)
{
    struct node *p;
    p = start;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->exp = ex;
    if(start == NULL)
    {
        temp->link = NULL;
        start = temp;
        return start;
    }
    while(p->link != NULL)
        p = p->link;
    temp->link = NULL;
    p->link = temp;
    return start;
}
struct node *mul(struct node *start1,struct node *start2)
{
   struct node *p1 = start1 , *p2 = start2 ,*p ,*start3 = NULL;
   p = p2;
   while(p1 != NULL)
   {
       p2 = p;
       while(p2 != NULL)
       {
           start3 = insM(start3,p1->exp + p2->exp , p1->coeff * p2->coeff);
           p2 = p2->link;
       }
       p1 = p1->link;
   }

  return start3;
}
struct node *insM(struct node *start, int ex, int co)
{
    if(start == NULL)
    {
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = co;
        temp->exp = ex;
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
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->exp = ex;
    while(p->link != NULL)
      p = p->link;
    temp->link = NULL;
    p->link = temp;
    return start;

}
