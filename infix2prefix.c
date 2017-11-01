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
        printf("%d\n",p->info);
        p = p->link;
    }
}
int priority(char c);
char infix[20],prefix[20];
void main()
{
    char c,s; int i,j = 0;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    //push(')');
    int n = strlen(infix);
    //infix[n] = '(';
    //infix[n+1] = NULL;
    for(i = n-1;i>=0;i--)
    {
        c = infix[i];
        if(c == ')')
            push(c);
        else if(c == '(')
        {
              while((s = pop()) != ')')
              {
                  prefix[j++] = s;
              }
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
        {

            while(priority(c) <= priority(top->info) && top != NULL)
                prefix[j++] = pop();
            push(c);
        }
        else
            prefix[j++] = c;
    }
    while(top!= NULL)
        prefix[j++] = pop();
    prefix[j] = '\0';
   n = strlen(prefix);
   for(i = n-1;i>=0;i--)
        printf("%c",prefix[i]);
}
int priority(char c)
{
    switch(c)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

