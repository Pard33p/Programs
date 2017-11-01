#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 20
char infix[MAX],postfix[MAX],stack[MAX];
int top = -1;
void push(char);
char pop();
void in2post(char infix[]);
int value(char []);
int priority(char);
void main()
{
    printf("Enter the expression : ");
    scanf("%s",infix);
    in2post(infix);
    printf("Postfix is %s",postfix);


}
void in2post(char infix[])
{
    int i = 0,p = 0;
    char symbol,new;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        if(symbol == '(')
            push(symbol);
        else if(symbol == ')')
        {
            while((new = pop())!='(')
                    postfix[p++] = new;
        }
        else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')
        {
            while( top != -1 && priority(stack[top]) >= priority(symbol))
                postfix[p++] = pop();
            push(symbol);
        }
        else
            postfix[p++] = symbol;
    }
    while(top != -1)
        postfix[p++] = pop();
    postfix[p] = '\0';
}
void push(char item)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top] = item;
}
char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    return stack[top--];

}
int priority(char item)
{
    switch(item)
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
    default:
        return 0;
    }
}
int value(char postfix[])
{

}
