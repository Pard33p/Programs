#include<stdio.h>
#include<conio.h>
int main()
{
    printf("Enter the line\n");

    recDisplay();
    return 0;
}
void recDisplay()
{
    fflush(stdin);
    char c;
    c = getche();
    if(c == '\r')
        return;
    recDisplay();
    printf("%c",c);

}
