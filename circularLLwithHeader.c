#include<stdio.h>
#include<string.h>
struct node
{
    int roll;
    char name[20];
    float marks;
    struct node *link;
};
struct node *last = NULL,*head;
void insEnd(int r,char nm[],float mark);
void display();
void main()
{
    int choice,n,item,r;
    float mark; char nm[20];
    head = (struct node *)malloc(sizeof(struct node));
    head->roll = 0;
    head->marks = 0;
    last = head;
    last->link = head;


    while(1)
    {
        printf("\n\n1.Create\n2.Display\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the no. of elements : ");
            scanf("%d",&n);
            while(n--)
            {
                printf("\nEnter the Roll No. : ");
                scanf("%d",&r);
                printf("\nEnter the Name : ");
                scanf("%s",nm);
                printf("\nEnter Marks : ");
                scanf("%f",&mark);
                insEnd(r,nm,mark);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            showHead();
            break;
        default:
            exit(0);
            }
    }
}
void insEnd(int r,char nm[],float mark)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->roll = r;
    strcpy(temp->name,nm);
    temp->marks = mark;

    temp->link = last->link;
    last->link = temp;
    last = temp;
    head->roll++;
    if(mark > head->marks)
        head->marks = mark;
}
void display()
{
    struct node *p;
    p = head->link;
    do
    {
        printf("\nRoll No. : %d",p->roll);
        printf("\nName : %s",p->name);
        printf("\nMarks : %f",p->marks);
        p = p->link;
    }while(p != last->link );


}
void showHead()
{
    printf("No. Of Students : %d",head->roll);
    printf("\nMaximum Marks : %0.2f\n",head->marks);
}
void insBeg()
{




}
