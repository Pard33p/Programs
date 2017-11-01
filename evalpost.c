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
char postfix[20];
void main()
{
    int i,result,a,b;
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    for(i = 0;postfix[i] != NULL;i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
           push(postfix[i] - '0');
         else
         {
             a = pop();
             b = pop();
             switch(postfix[i])
             {
             case '+':
                result = b + a;
                break;
              case '-':
                result = b - a;
                break;
              case '*':
                result = b * a;
                break;
               case '/':
                result = b / a;
                break;
                case '%':
                result = b % a;
                break;
                case '^':
                result = pow(b,a);
                break;
             }
             push(result);
         }
    }
    printf("%d\n",pop());
}

