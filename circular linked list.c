#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *last);
void display(struct node *last);
void count(struct node *last);
void search(struct node *last, int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data, int item);
struct node *addbefore(struct node *last,int data,int item);
struct node *addtoempty(struct node *last,int data);
struct node *addatpos(struct node *last,int data,int pos);
struct node *del(struct node *last,int data);

void main()
{
    struct node *last = NULL;
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
        printf("11.Reverse\n");
        printf("12.Largest Element\n");
        printf("13.Exit\n");
        printf("Enter ur Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            last = create_list(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            count(last);
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search(last,data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            last = addatbeg(last,data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            last = addatend(last,data);
            break;
         case 7:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the element after which to insert : ");
             scanf("%d",&item);
             last = addafter(last,data,item);
             break;
         case 8:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the element before which to insert : ");
             scanf("%d",&item);
             last = addbefore(last,data,item);
             break;
         case 9:
             printf("Enter the element to be inserted : ");
             scanf("%d",&data);
             printf("Enter the position at which to insert : ");
             scanf("%d",&pos);
             last = addatpos(last,data,pos);
             break;
         case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            //last = del(last,data);
            break;
         case 11:
          //  last = reverse(last);
            break;
         case 12:
           // max(last);
            break;
         case 13:
            exit(1);
         default:
            printf("Wrong Choice\n");

        }
    }
}
void display(struct node *last)
{
    int l;
    struct node *p;
    p = last->link;
    printf("\t");
    do
    {
        printf("%d ",p->info);
        p = p->link;
    }while(p != last->link);

    printf("\nPress 1 to return\n");
    scanf("%d",&l);
    printf("\n");
}
void count(struct node *last)
{
    struct node *p;
    int count = 0;
    p = last->link;
    do
    {

        p = p->link;
        count++;
    }while(p != last->link);
    printf("No. of Element : %d\n",count);

}
void search(struct node *last, int data)
{
    struct node *p;
    int count=1;
    p = last->link;
    do
    {
        if(p->info==data)
        {
            printf("%d is present at %d\n",data,count);
        }
        p = p->link;
        count++;

    }while(p != last->link);

}
struct node *addatbeg(struct node *last,int data)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->info = data;
   temp->link = last->link;
   last->link = temp;
   return last;
}
struct node *addtoempty(struct node *last,int data)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->info = data;
   last = temp;
   last->link = last;
   return last;
}
struct node *addatend(struct node *last,int data)
{
 struct node *temp;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info=data;
 temp->link = last->link;
 last->link = temp;
 last = temp;
 return last;
}
struct node *addafter(struct node *last,int data, int item)
{
     struct node *temp,*p;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info = data;
 p = last->link;
 do
 {
     if(p->info == item)
     {
         temp->link = p->link;
         p->link = temp;
         return last;
     }
     p = p->link;
 }while(p != last->link);
     printf("Failed\n");
     return last;
}
struct node *addbefore(struct node *last,int data,int item)
{
    struct node *temp,*p;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->info = data;
 p = last->link;
 if(p->info == item)
 {
     last = addatbeg(last,data);
     return last;
 }
 do
 {
     if(p->link->info == item)
     {
         temp->link = p->link;
         p->link = temp;
         return last;
     }
     p = p->link;
 }while(p->link != last->link);
     printf("Failed\n");
     return last;

}
struct node *addatpos(struct node *last,int data,int pos)
{
    struct node *temp,*p;
    int i=1;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    if(pos==1)
    {
        temp->link = last->link;
        last->link = temp;
        return last;
    }
    p = last->link;
    do{
        p = p->link;
        i++;
    }while(i<pos-1 && p != last->link);
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        temp->link = p->link;
        p->link = temp;
    }
    return last;
}
struct node *create_list(struct node *last)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    last = NULL;
    if(n==0)
        return last;
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    last = addtoempty(last,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        last = addatend(last,data);
    }
    return last;
}
/*struct node *del(struct node *last,int data)
{
    struct node *temp,*p;
    //temp = (struct node *)malloc(sizeof(struct node));
    if(last->info == data)
    {
        temp = last;
        last = last->link;
        free(temp);
        return last;
    }
    p = last;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            temp = p->link;
            p->link = temp->link ;
            free(temp);
            return last;
        }
        p = p->link;
    }
    printf("Element not found\n");
    return last;
}

*/
