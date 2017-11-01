#include <stdio.h>
int prime(int i);
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(prime(i))
          printf("%d ",i);
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
