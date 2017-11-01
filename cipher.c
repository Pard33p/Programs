#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char  dec[2000] , enc[2000] , i , s[2000] , q;
    int n ,key[2000] , t;
    scanf("%d",&t);
    while(t--)
    {
        fflush(stdin);
        scanf("%s%s%d",dec , enc , &n);
        for(i = 0; i < n ; i++)
        {
            if(isalpha(dec[i]))
              {
                  if(isupper(dec[i]))
                     {
                         dec[i] -= 64;
                         enc[i] -= 64;
                     }
                   else
                   {
                       dec[i] -= 96;
                       enc[i] -= 96;
                   }
                    key[i] = enc[i] - dec[i];
                    if(key[i] <= 0)
                          key[i] += 26;
              }
        }
              fflush(stdin);
              scanf("%d",&q);
              for(i = 0; i< q; i++)
              {
                  int p = -1 , j;
                  fflush(stdin);
                  scanf("%[^\n]s",s);
                  int len = strlen(s);
                  for(j = 0; j < len ; j++)
                  {
                      int flag = 0;
                      if(isalpha(s[j]))
                      {
                          if(isupper(s[j]))
                             {
                                 flag = 1;
                                 s[j] -= 64;
                             }
                          else
                             s[j] -= 96;
                          s[j] -= key[(++p) % n];
                          if(s[j] <= 0)
                             s[j] += 26;
                          if(flag)
                            s[j] += 64;
                          else
                            s[j] += 96;
                      }

                  }
                  printf("%s",s);
                  printf("\n");
              }
        }

}

