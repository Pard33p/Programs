#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data, int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *sort_sel(struct node *start);
struct node *sort_sel_link(struct node *start);
struct node *sort_bubl(struct node *start);
//struct node *reverse(struct node *start);

void main()
{
    struct node *start = NULL;
    int choice,data,item,pos;
    while(1)
    {
        printf("\n\n\n1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to Empty List / Add at Beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Sort\n");
        printf("12.Largest Element\n");
        printf("13.Exit\n");
        printf("Enter ur Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search(start,data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start = addatbeg(start,data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start = addatend(start,data);
            break;
         case 7:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the element after which to insert : ");
             scanf("%d",&item);
             start = addafter(start,data,item);
             break;
         case 8:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the element before which to insert : ");
             scanf("%d",&item);
             start = addbefore(start,data,item);
             break;
         case 9:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the position at which to insert : ");
             scanf("%d",&pos);
             start = addatpos(start,data,pos);
             break;
         case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start = del(start,data);
            break;
         case 11:
            start = sort_sel_link(start);
            break;
         case 12:
            //max(start);
            break;
         case 13:
            exit(1);
         default:
            printf("Wrong Choice\n");

        }
    }
}
void display(struct node *start)
{
    int l;
    struct node *p;
    p=start;
    printf("\t");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\nPress 1 to return\n");
    scanf("%d",&l);
    printf("\n");
}
void count(struct node *start)
{
    struct node *p;
    int count=0;
    p = start;
    while(p!=NULL)
    {

        p=p->link;
        count++;
    }
    printf("No. of Element : %d\n",count);

}
void search(struct node *start, int data)
{
    struct node *p;
    int count=1;
    p=start;
    while(p!=NULL)
    {
        if(p->info==data)
        {
            printf("%d is present at %d\n",data,count);
        }
        p=p->link;
        count++;

    }
    printf("Element not found\n");
}
struct node *addatbeg(struct node *start,int data)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->info=data;
   temp->link=start;
   start=temp;
   return start;
}
struct node *addatend(struct node *start,int data)
{
 struct node *temp,*p;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info=data;
 p=start;
 while(p->link!=NULL)
 {
     p=p->link;
 }
 p->link=temp;
 temp->link=NULL;
 return start;
}
struct node *addafter(struct node *start,int data, int item)
{
     struct node *temp,*p;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info=data;
 p=start;
 while(p!=NULL)
 {
     if(p->info==item)
     {
         temp->link = p->link;
         p->link = temp;
         return start;
     }
     p=p->link;
 }
     printf("Failed\n");
     return start;


}
struct node *addbefore(struct node *start,int data,int item)
{
    struct node *temp,*p;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info=data;
 p=start;
 while(p->link!=NULL)
 {
     if(p->link->info==item)
     {
         temp->link = p->link;
         p->link = temp;
         return start;
     }
     p=p->link;
 }
     printf("Failed\n");
     return start;

}
struct node *addatpos(struct node *start,int data,int pos)
{
    struct node *temp,*p;
    int i;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(pos==1)
    {
        temp->link = start;
        start = temp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1 && p!=NULL;i++)
        p=p->link;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}
struct node *create_list(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start = NULL;
    if(n==0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start = addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start = addatend(start,data);
    }
    return start;
}
struct node *del(struct node *start,int data)
{
    struct node *temp,*p;
    //temp = (struct node *)malloc(sizeof(struct node));
    if(start->info == data)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            temp = p->link;
            p->link = temp->link ;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element not found\n");
    return start;
}
void max(struct node *start)
{
    struct node *p;
    int maxi=0;
    p = start;
    while(p != NULL)
    {
        if(p->info > maxi)
             maxi = p->info;
        p = p->link;

    }
    printf("largest element is %d\n",maxi);
}
struct node *sort_sel(struct node *start)
{
    struct node *p,*q;
    int temp;
    for(p = start;p->link != NULL;p = p->link)
    {
        for(q = p->link; q != NULL; q = q->link)
        {
            if(p->info > q->info)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }
    }
    return start;
}
struct node *sort_bubl(struct node *start)
{
    struct node *p,*q;
    int temp;
    for(p = start;p->link != NULL;p = p->link)
    {
        for(q = start; q->link != NULL; q = q->link)
        {
            if(q->info > q->link->info)
            {
                temp = q->info;
                q->info = q->link->info;
                q->link->info = temp;
            }
        }
    }
    return start;
}
struct node *sort_sel_link(struct node *start)
{
    struct node *t,*p,*q,*s,*r,*temp;

    for(r = p = start; p->link != NULL ;r = p, p = p->link)
    {
        for(s = q = p->link; q != NULL;s = q, q = q->link)
        {
            if(p->info > q->info)
            {
                temp = p->link;
                p->link = q->link;
                q->link = temp;
                s->link = p;
                if(p != start)
                    r->link = q;
                else
                    start = q;
                t = p;
                p = q;
                q = t;
            }
        }
    }
    return start;
}
