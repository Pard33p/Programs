#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start1 = NULL,*start2 = NULL;
struct node *create(struct node *start,int item);
void display(struct node *start);
void displayAcc2other(struct node *start1,struct node *start2);
void main()
{
    int choice,n,item;

    while(1)
    {
      printf("\n1.Create 1st List\n2.Create 2nd list\n3.Display 1st List\n4.Display 2nd List\n5.DISPLAY\n6.Exit\n\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
          printf("\nEnter the no. of elements : ");
          scanf("%d",&n);
           while(n--)
         {
        printf("\nEnter Element : ");
        scanf("%d",&item);
        start1 = create(start1,item);
         }
        break;
      case 2:
          printf("\nEnter the no. of elements : ");
          scanf("%d",&n);
           while(n--)
         {
        printf("\nEnter Element : ");
        scanf("%d",&item);
        start2 = create(start2,item);
         }
        break;
      case 3:
        display(start1);
        break;
      case 4:
        display(start2);
        break;
      case 5:
        displayAcc2other(start1,start2);
        break;
      default:
        exit(0);
      }
    }
}
struct node *create(struct node *start,int item)
{
    struct node *p,*temp;
     temp = (struct node *)malloc(sizeof(struct node));
        temp->info = item;
     if(start ==  NULL)
     {
        temp->link = NULL;
        start = temp;
        return start;
     }
     p = start;
     while(p->link != NULL)
        p = p->link;
     temp->link = p->link;
     p->link = temp;
     return start;
}
void display(struct node *start)
{
    if(start == NULL)
    {
        printf("\nList Empty\n");
        return;
    }
    struct node *p;
    p = start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n");
}
void displayAcc2other(struct node *start1,struct node *start2)
{
    struct node *p1,*p2;
    int count=1;
    p1 = start1;
    p2 = start2;
    while(p1!=NULL && p2!=NULL)
    {
        if(count == p1->info)
        {
            printf("%d ",p2->info);
            p1 = p1->link;
        }
        p2 = p2->link;
        count++;
    }
}
