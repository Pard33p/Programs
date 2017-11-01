#include<math.h>
#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*top = NULL;
char postfix[20];
void main()
{
    int result,a,b,i;
    char symbol;
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    for(i = 0;postfix[i] != NULL;i++)
    {
        symbol = postfix[i];
        if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%')
        {
            a = pop()-'0';
            b = pop()-'0';
            switch(symbol)
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
        else
         push(symbol-'0');
    }
    printf("%d",pop());
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
