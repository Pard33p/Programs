#include <stdio.h>
#include<ctype.h>
int prime(int);
int main()
{
    int n,t,a,b,i,c1,c2;
    char s[500];
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        scanf("%s",s);
        for(i=0;i<n;i++)
        {
            c1 = 0; c2 = 0;
                a = s[i];
                b = s[i];
                while(1)
                {
                    a++;
                    c1++;
                    if(prime(a) && isalpha(a))
                        break;
                }
                while(1)
                {
                    b--;
                    c2++;
                     if(prime(b) && isalpha(b))
                        break;
                }
                if(c1>c2)
                    s[i] = b;
                 else if(c2>c1)
                    s[i] = a;
                 else
                    s[i] = a<b?a:b;

        }
        printf("%s\n",s);
    }
    return 0;
}
int prime(int n)
{
    int i,c=1;
    for(i = 2;i<n;i++)
    {
        if(n%i == 0)
          {
              c = 0;
              break;
          }
    }
    if(c == 0)
      return 0;
    else
      return 1;

}


