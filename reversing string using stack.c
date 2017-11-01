#include<stdio.h>
#include<string.h>
#define MAX 10
char pop();
int top = -1;
void push(char);

char stack[MAX];

void main()
{
    char s[MAX];
    int i;
    printf("Enter the string : ");
    scanf("%s",s);
    for(i = 0;i < strlen(s);i++)
         push(s[i]);
    for(i = 0;i < strlen(s);i++)
        s[i] = pop();
    printf("\nReversed String : %s\n\n\n",s);

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
