#include<stdio.h>
    int count = 1;
int main()
{
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    toh(n , 'A' , 'B' , 'C');
    return 0;
}
void toh(int n , char source , char temp , char dest)
{
    if(n == 1)
    {
        printf("\n%d. %c --> %c\n",count++,source , dest);
        return ;
    }
    toh(n - 1 , source , dest , temp);
     printf("\n%d. %c --> %c\n",count++,source , dest);
     toh(n - 1 , temp , source , dest);
}
