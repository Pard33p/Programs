#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,n;
    char s[20],s1[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        n = strlen(s);
        for(i=0,j=n-1;i<n && j>-1;i++,j--)
        {
            s1[i]=((s[i]-96)+(s[j]-96))%26;
              if(s1[i]==0)
                s1[i] = 26;
              s1[i]+=96;
        }
        for(i=0;i<n;i++)
           printf("%c",s1[i]);
        printf("\n");
    }


    return 0;
}
