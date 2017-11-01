#include<stdio.h>
#include<string.h>
#define MAX 10
char pop();
void display();
int top = -1;
void push(char);
int match(char,char);
char stack[MAX];

void main()
{
    char s[MAX],temp;
    int i;
    printf("Enter the expression : ");
    gets(s);
    for(i = 0;i < strlen(s);i++)
    {
      if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                    push(s[i]);
      if(s[i]==')' || s[i]=='}' || s[i]==']')
      {
          if(top==-1)
          {
              printf("Right parentheses are more than left\n");
              return 0;
          }
          else
          {
              temp = pop();
              if(!match(temp,s[i]))
              {
                  printf("Mismatched parenthesis are :");
                  printf("%c and %c\n",temp,s[i]);
                  return 0;
              }

          }
      }
      printf("1\n");
    }
    if(top==-1)
    {
        printf("Balanced Parenthesis\n");
        return 1;
    }
    else
    {
        printf("Left parenthesis are more than right parenthesis\n");
        display();
        return 0;
    }

}
int match(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    return 0;

}
char pop()
{
    char item;
    if(top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    item = stack[top];
    top = top-1;
    return item;

}
void push(char item)
{
    if(top == MAX-1){
        printf("Stack Overflow");
        exit(1);
    }
    top = top+1;
    stack[top] = item;

}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i = top;i > -1;i--)
        printf("%c\n",stack[i]);
    printf("Press any key to return ");
    scanf("%d",&i);
}

