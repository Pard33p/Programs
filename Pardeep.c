#include<stdio.h>
struct node
{
    int info;
    struct node *link;

}*start = NULL;
void create();
void insBeg(int item);
void insEnd(int item);
void insPos(int item,int pos);
void display();
void delBeg();
void delSpecific(int item);
void swap(int,int);

int main()
{
   int choice,item,pos,item1,item2;
   while(1)
   {
       printf("\n\n1.Create New List\n2.Insert Element At Beginning\n3.Insert Element At End\n4.Insert Element At Given Position\n5.Display\n6.No. of Elements\n");
       printf("7.Delete at Beginning\n8.Delete Specific Element\n9.Delete the element at end\n10.Swap Any two Elements\n11.Reverse\n12.Bubble Sort\n13.Even at beginning\n\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
           create();
        break;
       case 2:
           printf("\nEnter the element : ");
           scanf("%d",&item);
           insBeg(item);
           break;
       case 3:
           printf("\nEnter the element : ");
           scanf("%d",&item);
           insEnd(item);
           break;
       case 4:
           printf("\nEnter the element : ");
           scanf("%d",&item);
           printf("\nEnter the position : ");
           scanf("%d",&pos);
           insPos(item,pos);
           break;
       case 5:
          display();
          break;
       case 6:
           printf("No. of Elements : %d\n",count());
           break;
       case 7:
        delBeg();
        break;
       case 8:
        printf("Enter the element to delete : ");
        scanf("%d",&item);
        delSpecific(item);
        break;
       case 9:
        delEnd();
        break;
       case 10:
           printf("Enter the elements you want to swap : ");
           scanf("%d%d",&item1,&item2);
           swap(item1,item2);
        break;
       case 11:
        rev();
        break;
       case 12:
        bubble();
        break;
       case 13:
        oddEven();
        break;
       default:
        exit(0);
       }
   }
return 0;
}
void create()
{
    start = NULL;
    int n,item;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    while(n--)
    {
        printf("\nEnter the element : ");
        scanf("%d",&item);
        insEnd(item);
    }

}
void insBeg(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = start;
    start = temp;


}
void display()
{
    struct node *p;
    if(start == NULL)
    {
        printf("NO LIST TO DISPLAY !!\n");
        return;
    }
    p = start;
    printf("\n");
    while(p != NULL){
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n");
}
void insEnd(int item)
{
    struct node *temp,*p;
    p = start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)
        insBeg(item);
    else
    {
    while(p->link != NULL)
        p = p->link;
    temp->link = p->link;
    p->link = temp;
    }
}
void insPos(int item,int pos)
{
    struct node *p,*temp;
    p = start;
    if(pos == 1)
        insBeg(item);
       else if(pos == 2)
    {
      temp = (struct node *)malloc(sizeof(struct node));
      temp->info = item;
      temp->link = p->link;
      p->link = temp;
    }
    else
    {
        pos -=2;
        while(pos-- && p!= NULL)
            p = p->link;
      temp = (struct node *)malloc(sizeof(struct node));
      temp->info = item;
       temp->link = p->link;
       p->link = temp;
    }
}
int count()
{
    struct node *p;
    p = start;
    int count = 0;
    while(p != NULL)
        {
            count++;
            p = p->link;
        }
     return count;
}
void delBeg()
{
    struct node *temp;
    temp = start;
    start = temp->link;
    free(temp);
}
void delSpecific(int item)
{
    struct node *p,*temp;
    if(start->info == item)
        delBeg();
    else
    {
        p = start;
        while(p->link != NULL)
        {
            if(p->link->info == item)
            {
                temp = p->link;
                p->link = temp->link;
                free(temp);
                return;
            }
        }
    }
}
void delEnd()
{
    struct node *p,*temp;
    p = start;
    while(p->link->link != NULL)
        p = p->link;
    temp = p->link;
    p->link = temp->link;
    free(temp);
}
void swap(int item1,int item2)
{
    struct node *p,*q,*r,*s,*temp;
    r = p = start;
    s = q = start;
    while(p!=NULL)
    {
        if(p->info == item1)
            break;
        r = p;
        p = p->link;
    }
    while(q!= NULL)
    {
        if(q->info == item2)
            break;
        s = q;
        q = q->link;
    }
    if(p == s)
    {
        p->link = q->link;
        q->link = p;
    }
    else
    {
        temp = p->link;
       p->link = q->link;
       q->link = temp;
       s->link = p;
    }
    if(p != start)
        r->link = q;
    else
        start = q;

}
void rev()
{
    struct node *p,*prev,*next;
    p = start;
    prev = NULL;
    while(p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
}
void bubble()
{
    struct node *p,*q=NULL,*r,*end,*t;
    p = r = start;
    for(end = NULL; end != start->link ;end = q)
    {
        for(p = start;p->link != end ;r = p,p = p->link)
        {

            q = p->link;
            if(p->info > q->info)
            {
                p->link = q->link;
                q->link = p;
                if(p == start)
                start = q;
                else
                r->link = q;
                t = p;
                p = q;
                q = t;
            }

        }
    }
}
void oddEven()
{
    struct node *p,*q,*last;
    int temp;
    p = start;
    while(p->link != NULL)
       p = p->link;
     last = p;
     while(start->info % 2 != 0)
     {
         p = start;
         start = start->link;
         last->link = p;
         p->link = NULL;
         last = p;
     }
     p = start;
     while(p->link != NULL)
     {
         if(p->info % 2 ==0 && p->link->info % 2 != 0 && p->link != NULL)
         {
             q = p->link;
             p->link = q->link;
             last->link = q;
             q->link = NULL;
             last = q;
         }

           p = p->link;
     }
}
