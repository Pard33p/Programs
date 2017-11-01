#include<stdio.h>
int main()
{
    int t , n , i ,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long int count = 0;
        for(i = 1; i < n; i++)
        {
            for(j = i + 1; j <= n ; j++)
            {
               // printf("{ %d , %d }\n",i,j);
                if((i ^ j) <= n)
                    count++;
            }
        }
        printf("%ld\n",count);
    }
}
