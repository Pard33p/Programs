#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;

void main()
{
    int i;
    char s[10];
    printf("Enter the string : ");
    scanf("%s",s);
    for(i = 0 ; s[i] != NULL ; i++)
        push(s[i]);
    printf("Reversed String : ");
    for(i = 0 ; s[i] != NULL ; i++)
        printf("%c",pop());
    printf("\n");
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
int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp;
    int item;
    item = top->info;
    temp = top;
    top = top->link;
    free(temp);
    return item;
}
void display()
{
    if(top == NULL)
    {
            printf("No Stack To Display\n");
            return ;
    }
    struct node *ptr;
    ptr = top;
    while(ptr)
    {
        printf("\n%d\n",ptr->info);
        ptr = ptr->link;
    }

}

