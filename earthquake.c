#include<stdio.h>
int main()
{
    long int n , k , q , l , r, index , i , j;
    scanf("%ld%ld",&n , &k);
    char s[n] , c;
    scanf("%s",s);
    while(k--)
    {
        scanf("%ld",&q);
        if(q == 1)
        {
            scanf("%ld",&index);
            scanf(" %c",&c);
            index--;
            s[index] = c;
        }
        else if (q == 2)
            {
                scanf("%ld%ld",&l,&r);
                l--;
                r--;
            int flag = 0;
            for(i = l , j = r; i <= r && j >= l ; i++ , j--)
            {
                if(s[i] != s[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                printf("Yes\n");
            else
                printf("No\n");
            }
    }

    return 0;
}
