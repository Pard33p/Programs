#include<stdio.h>
#include<string.h>
int main()
{
    char s[100][100] ;
    int t ,i, n,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i < 2*n ; i++)
            scanf("%s",s[i]);

        for(i = 0; i < 2 * n; i += 2)
        {
            for(j = i + 1; j < 2 * n;)
            {
                if(strcmp(s[i]  , s[j]) == 0)
                {
                    char temp[100];
                    strcpy(temp , s[i]);
                    strcpy(s[i] , s[j-1]);
                    strcpy(s[j-1] , temp);
                    strcpy(temp , s[j]);
                    strcpy(s[j] , s[i + 1]);
                    strcpy(s[i + 1] , temp);
                    j = i + 1;
                }
                else
                    j += 2;
            }
        }
        for(i = 0; i < 2*n ; i+= 2)
            printf("%s-%s ",s[i] , s[i + 1]);
        printf("\n");
    }
}
