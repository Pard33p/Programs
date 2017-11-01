#include<stdio.h>
#include<string.h>

int main()
{
    int k=1,i,t,n,a,count=0;
    char s[10];
    scanf("%d",&t);
    while(t--)
    {
        count = 0;
        scanf("%s",s);
        n = strlen(s);
        for(i=0;i<n;i++)
        {

            if(s[i]=='.' || s[i]==',' || s[i]=='?' || s[i]=='!' )
            {
                if(k!=1)
                    count++;
                switch(s[i])
                {
                case '.':
                    count+=1;
                    break;
                case ',':
                    count+=2;
                    break;
                case '?':
                    count+=3;
                    break;
                case '!':
                    count+=4;
                    break;
                }
                k = 1;
            }
            else if(s[i]>='a' && s[i]<='c' )
            {
                if(k!=2)
                    count++;
                a = 'a';
                while(1)
                {
                    k=2;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='d' && s[i]<='f' )
            {
                if(k!=3)
                    count++;
                a = 'd';
                while(1)
                {
                    k=3;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='g' && s[i]<='i' )
            {
                if(k!=4)
                    count++;
                a = 'g';
                while(1)
                {
                    k=4;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

           else if(s[i]>='j' && s[i]<='l' )
            {
                if(k!=5)
                    count++;
                a = 'j';
                while(1)
                {
                    k=5;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='m' && s[i]<='o' )
            {
                if(k!=6)
                    count++;
                a = 'm';
                while(1)
                {
                    k=6;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='p' && s[i]<='s' )
            {
                if(k!=7)
                    count++;
                a = 'p';
                while(1)
                {
                    k=7;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='t' && s[i]<='v' )
            {
                if(k!=8)
                    count++;
                a = 't';
                while(1)
                {
                    k=8;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }

            else if(s[i]>='w' && s[i]<='z' )
            {
                if(k!=9)
                    count++;
                a = 'w';
                while(1)
                {
                    k=9;
                    count++;
                    if(s[i] == a )
                        break;
                    else
                      a++;

                }
            }
            else if(s[i]=='_')
            {
                if(k!=0)
                    count++;
                count++;
                k=0;
            }
        }
        printf("%d ",count);
    }



}
