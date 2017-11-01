#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*start = NULL;
int priority(char c);
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
    int i , j = 0;
   char infix[20] , postfix[20] , c , s;
   printf("Enter the infix expression : ");
   scanf("%s",infix);
   for(i = 0; infix[i] != NULL ; i++)
   {
       c = infix[i];
       if(c == '(')
            push(c);
       else if(c == ')')
       {
          while((s = pop()) != '(')
                    postfix[j++] = s;
       }
       else if( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
       {
           while(priority(start->info) >= priority(c) )
               postfix[j++] = pop();
           push(c);
       }
       else
        postfix[j++] = c;
   }
   while(start != NULL)
      postfix[j++] = pop();
   postfix[j] = '\0';
   printf("Postfix : %s\n",postfix);
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
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;

    }
}
