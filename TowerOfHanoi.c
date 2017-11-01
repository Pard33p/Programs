#include<stdio.h>
static int count = 1;
int main()
{
    int n;
    char source = 'A' , temp = 'B' , dest = 'C';
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("Sequence is :\n");
    towerHanoi(n , source , temp , dest);
    return 0;
}
void towerHanoi(int n , char source , char temp , char dest)
{
    if(n == 1)
    {
        printf("%2d.%c --> %c\n",count++,source , dest);
        return;
    }
    towerHanoi(n - 1 , source , dest , temp);
    printf("%2d.%c --> %c\n",count++,source , dest);
    towerHanoi(n - 1 , temp , source , dest);
}
