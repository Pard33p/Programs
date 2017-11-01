#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;
int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    int item = top->info;
    top = top->link;
    return item;
}
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    temp->info = item;
    temp->link = top;
    top = temp;
}
void display()
{
    struct node *p = top;
    while(p)
    {
        printf("%d",p->info);
        p = p->link;
    }
}
void main()
{
    long int decimal;
    printf("Enter the decimal : ");
    scanf("%ld",&decimal);
    long int d = decimal;
    while(decimal)
    {
        push(decimal%2);
        decimal /= 2;
    }
    printf("\nBinary : ");
    while(top)
        printf("%d",pop());
     while(d)
    {
        push(d%8);
        d/= 8;
    }
    printf("\nOctal : ");
    while(top)
        printf("%d",pop());
     printf("\n");
}
