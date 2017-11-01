#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start = NULL;
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow\n");
        return ;
    }
    temp->info = item;
    temp->link = start;
    start = temp;
}
int pop()
{
    if(start == NULL)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    struct node *temp = start;
    int item;
    item = temp->info;
    start = start->link;
    free(temp);
    return item;
}
void display()
{
    if(start == NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    struct node *p = start;
    while(p)
    {
        printf("\t%d\n",p->info);
        p = p->link;
    }
    printf("\n");
}
void main()
{
    int dec;
    printf("Enter the decimal number : ");
    scanf("%d",&dec);
    while(dec > 0)
    {
        push(dec%8);
        dec /= 8;
    }
    printf("Octal : ");
    while(start != NULL)
        printf("%d",pop());
    printf("\n");
}
