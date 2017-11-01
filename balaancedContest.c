#include<stdio.h>
int main()
{
    int t , n;
    long int p, ns;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%ld",&n,&p);
        long int cakewalk = 0 , diff = 0;
        while(n--)
        {
            scanf("%ld",&ns);
            if(ns <= p / 10)
                diff++;
            else if(ns >= p / 2)
                cakewalk++;
        }
        if(cakewalk == 1 && diff == 2)
            printf("yes\n");
        else
            printf("no\n");
    }


    return 0;
}
