#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start = NULL;
int match(char a, char b);
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
    int i;
    char exp[20] , symbol , c;
    printf("Enter the expression : ");
    scanf("%s",exp);
    for(i = 0; exp[i] != NULL; i++)
    {
        symbol = exp[i];
        if(symbol == '(' || symbol == '{' || symbol == '[' )
            push(symbol);
        else if(symbol == ')' || symbol == ']' || symbol == '}')
        {
            if(start == NULL)
            {
                printf("Right Parenthesis are more than left\n");
                exit(0);
            }
            else
            {
                c = pop();
                if(!match(c , symbol))
                {
                    printf("Mismatched Parenthesis %c and %c\n",c,symbol);
                    exit(0);
                }
            }
        }
    }
    if(start != NULL)
    {
        printf("Left Parenthesis are more than right \n");
    }
    else
        printf("Balanced Parenthesis\n");
}
int match(char a, char b)
{
    if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') )
        return 1;
    else
        return 0;
}
