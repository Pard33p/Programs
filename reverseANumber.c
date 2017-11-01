#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",rev(n));
}

int rev(int n)
{
    if(n == 0)
        return 0;
     return  (n%10 * pow(10 , (int)(log10(n)))  + rev(n/10) );
}

