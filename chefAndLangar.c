#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char s[100000];
    long int x , y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        scanf("%ld%ld",&x,&y);
        long int n = strlen(s) , a = 0, b = 0 , i ;
        for(i = 0; i < n ; i++)
        {
            if(s[i] == 'a')
                a++;
            else
                b++;
        }
        char prev;
        int flag;
        if(s[0] == 'a')
            flag = 1;
        else
            flag = 0;
        while(a && b)
        {
            if(flag == 1)
            {
                printf("a");
                a--;
                prev = 'a';
            }
            else
            {
                printf("b");
                b--;
                prev = 'b';
            }
            flag = !flag;
        }
        if(b == 0 )
        {
            if(prev == 'b' && a)
            {
               printf("a");
               a--;
            }
            while(a)
            {
                printf("*a");
                a--;
            }
        }
        else
        {
            if(prev == 'a' && b)
            {
                printf("b");
                b--;
            }
            while(b)
            {
                printf("*b");
                b--;
            }
        }
        printf("\n");
    }
}
