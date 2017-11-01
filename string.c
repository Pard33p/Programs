#include <stdio.h>

int main()
{
    char N[100000],M[100000];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",N,M);
        if(strcmp(N,M)==0 || (strcmp(N,"4")==0 && strcmp(M,"2")==0) || (strcmp(M,"4")==0 && strcmp(N,"2")==0))
          printf("YES\n");
        else
          printf("NO\n");
    }
    return 0;
}

