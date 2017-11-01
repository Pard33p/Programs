#include<stdio.h>
#include<string.h>
struct node
{
    int roll;
    char name[20];
    int perc;
    struct node *link;
}*last = NULL, *head;

void main()
{
                    int rollno; int p; char s[20],r;
    head = (struct node *)malloc(sizeof(struct node));
    head->roll = 0;
    last = head;
    head->link = head;
    int choice,n;
    while(1)
    {
        printf("\n\n1.Create Record\n2.Display\n3.Insert at beginning\n4.Insert after given student\n5.Delete\n6.Show Header\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number of students : ");
            scanf("%d",&n);
            head->roll = n;
            while(n--)
            {
                printf("\nEnter the roll no : ");
                scanf("%d",&rollno);
                printf("\nEnter the name : ");
                scanf("%s",s);
                printf("\nEnter the percentage of marks : ");
                scanf("%d",&p);
                insEnd(rollno,s,p);
            }
            break;
        case 2:
            display();
            break;
        case 3:
                printf("\nEnter the roll no : ");
                scanf("%d",&rollno);
                printf("\nEnter the name : ");
                scanf("%s",s);
                printf("\nEnter the percentage of marks : ");
                scanf("%d",&p);
                insBeg(rollno,s,p);
               break;
        case 4:

                printf("\nEnter the roll no : ");
                scanf("%d",&rollno);
                printf("\nEnter the name : ");
                scanf("%s",s);
                printf("\nEnter the percentage of marks : ");
                scanf("%d",&p);
                printf("\nEnter the roll no. after which you want to insert : ");
                scanf("%d",&r);
                insAfter(rollno,s,p,r);
                break;
        case 5:
            printf("Enter the roll no of student you want to delete : ");
            scanf("%d",&rollno);
            del(rollno);
            break;
        case 6:
            header();
            break;
        default:
            exit(0);

        }
    }





}
void insEnd(int rollno,char s[],int p)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->roll = rollno;
    strcpy(temp->name,s);
    temp->perc = p;
   if(head->link == head)
    {
        temp->link = last->link;
        head->link = temp;
        last = temp;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}
void display()
{
    struct node *p;
    int i = 1;
      p = head->link;
     while(p != last->link)
    {
        printf("\nStudent %d :\n",i++);
        printf("\nName : %s",p->name);
        printf("\nRoll No : %d",p->roll);
        printf("\nPercentage : %d\n",p->perc);
        p = p->link;
    }

}
void insBeg(int rollno,char s[],int p)
{
    struct node *temp;
    temp = (struct node * )malloc(sizeof(struct node));
    temp->roll = rollno;
    temp->perc = p;
    strcpy(temp->name,s);
    temp->link = head->link;
    head->link = temp;
}
void insAfter(int rollno,char s[],int p,int r)
{
    struct node *temp,*ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->roll = rollno;
    temp->perc = p;
    strcpy(temp->name,s);
    ptr = head->link;
    while(ptr != last->link)
    {
        if(ptr->roll == r)
        {
            temp->link = ptr->link;
            ptr->link = temp;
            break;
        }
        ptr = ptr->link;
    }
}
void del(int r)
{
    if(head->link->roll == r)
    {
        struct node *temp;
        temp = head->link;
        head->link = temp->link;
        free(temp);
        return;
    }
    struct node *p = head->link;
    while(p->link != last->link)
    {
        if(p->link->roll == r)
        {
            struct node *temp;
            temp = p->link;
            p->link = temp->link;
            free(temp);
        }
        p = p->link;
    }

}
void header()
{
    struct node *p;
    int count=0;
    p = head->link;
    while(p != last->link)
    {
        count++;
        p = p->link;
    }
    head->roll = count;
    printf("No. of students : %d\n",head->roll);
    head->perc = 0;
    p = head->link;
    while(p != last->link)
    {
       if(p->perc > head->perc)
            head->perc = p->perc;
       p = p->link;
    }
    printf("Maximum Marks : %d\n",head->perc);
}
