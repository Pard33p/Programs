#include <stdio.h>

int main()
{
    int t;
    long int n,m;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&m);
        n--;
        long int count = 0,p = 0;
        while(n>0)
        {
            n-=p;
             if(p<m)
              p++;
            count++;
        }
        printf("%ld\n",count);
    }
    return 0;
}

