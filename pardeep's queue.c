#include<stdio.h>
void main()
{
    int t,n,a[20],i,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        i = 0;
        while(m>0)
        {
            m -= a[i%n];
            i++;
        }
        printf("%d\n",((i-1)%n)+1);
    }
}
