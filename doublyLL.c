#include<stdio.h>
struct node
{
    int info;
    struct node *next,*prev;
}*start = NULL;

void main()
{
  int choice,item,data;
  while(1)
  {
      printf("\n1.Create\n2.Display\n3.Insert At Beginning\n4.Insert at end\n5.Insert after node\n6.Insert Before\n7.Swap Adjacent Elements\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
        create();
        break;
      case 2:
        display();
        break;
      case 3:
          printf("Enter the element : ");
          scanf("%d",&item);
        insBeg(item);
        break;
      case 4:
          printf("Enter the element : ");
          scanf("%d",&item);
        insEnd(item);
        break;
      case 5:

        printf("Enter the element to insert : ");
          scanf("%d",&item);
        printf("Enter the element after which u want to insert : ");
          scanf("%d",&data);
        insAfter(item,data);
        break;
      case 6:
        printf("Enter the element to insert : ");
          scanf("%d",&item);
        printf("Enter the element before which u want to insert : ");
          scanf("%d",&data);
        insBefore(item,data);
        break;
      case 7:
        swapAdj();
        break;
      default:
        exit(0);
      }
  }


}
void insEnd(int item)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        p = start;
        while(p->next != NULL)
          p = p->next;
        temp->next = NULL;
        temp->prev = p;
        p->next = temp;
    }
}
void create()
{
    int n,item;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    while(n--)
    {
        printf("\nEnter the element : ");
        scanf("%d",&item);
        insEnd(item);
    }


}
void display()
{
   struct node *p;
   p = start;
   while(p!= NULL)
   {
       printf("%d ",p->info);
       p = p->next;
   }
}
void insBeg(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = start;
    temp->prev = NULL;
    start = temp;
}
void insAfter(int item,int data)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    p = start;
    while(p!= NULL)
    {
        if(p->info == data)
        {
            temp->next = p->next;
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            break;
        }
        p = p->next;
    }
}
void insBefore(int item,int data)
{
    struct node *temp,*p;
    if(start->info == data)
        insBeg(item);

    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    p = start;
    while(p!= NULL)
    {
        if(p->info == data)
        {
            temp->next = p->prev->next;
            temp->prev = p->prev;
            p->prev = temp;
            p->prev->next = temp;
            break;
        }
        p = p->next;
    }
    }
}
void swapAdj()
{
    struct node *p,*q,*r;
    r = p = start;
    while(p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        p->prev = q;
        if(q->next != NULL)
            q->next->prev = p;
        q->next = p;
        if(p == start)
        {
            q->prev = NULL;
            start = q;
        }
        else
        {
            q->prev = r;
            r->next = q;
        }
        r = p;
        if(p->next == NULL)
            break;
        else
          p = p->next;
    }



}
