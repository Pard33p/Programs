#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;
char infix[20],postfix[20];
int priority(char c);
void main()
{
    char s,symbol;
    int i,j = 0;
  printf("Enter the infix expression : ");
  scanf("%s",infix);

  for(i = 0;infix[i] != NULL;i++)
  {
      symbol = infix[i];
      if(symbol == '(')
            push(symbol);
      else if(symbol == ')')
      {
          while((s = pop()) != '(' && top != NULL)
                  {
                     postfix[j++] = s;
                  }
      }
      else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%')
      {
          if(top != NULL)
           {
             while((priority(top->info) >= priority(symbol))  && top != NULL)
            {
                postfix[j++] = pop();
            }
           }
          push(symbol);
      }
      else
      {
          postfix[j++] = symbol;
      }
  }
while(top != NULL)
    postfix[j++] = pop();
printf("%s\n",postfix);

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

