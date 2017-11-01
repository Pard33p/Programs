#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;
int match(char a,char b);
void main()
{
    int i;
    char exp[20],symbol;
    printf("Enter the expression : ");
    scanf("%s",exp);
    for(i = 0; exp[i] != NULL;i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                    push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            symbol = pop();
            if(!match(symbol,exp[i]))
            {
                printf("Mismatched Parenthesis are %c and %c\n ",symbol,exp[i]);
                exit(0);
            }
        }
    }
    if(top != NULL)
       printf("Left Parenthesis are more than right\n");
    else
        printf("Expression is valid\n");
}
int match(char a,char b)
{
    if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')  )
        return 1;
    else
        return 0;
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
        printf("Right Parenthesis are more than left\n");
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
