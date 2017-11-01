#include<stdio.h>
int main()
{
     int n ;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int k , count = 0;
        k = n ^ (-n);
        while(k)
        {
            k = k & (k - 1);
            count++;
        }
        printf("%d\n",count);
    }
}
