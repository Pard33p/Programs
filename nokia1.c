#include<stdio.h>
#include<string.h>
void check(char , int);
char s[10];
int k = 1,count = 0;
int main()
{
    int i,t,n,a;
    scanf("%d",&t);
    while(t--)
    {
        count = 0;
        k = 1;
        scanf("%s",s);
        n = strlen(s);
        for(i=0;i<n;i++)
        {

            if(s[i]=='.' || s[i]==',' || s[i]=='?' || s[i]=='!' || s[i]=='1')
            {
                if(k!=1)
                    count++;
                k = 1;
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
                case '1':
                    count+=5;
                    break;
                }

            }
            else if((s[i]>='a' && s[i]<='c') || s[i]=='2')
            {
                if(k!=2)
                    count++;
                if(s[i]=='2')
                    count+=4;
                else
                   check('a',i);
                k = 2;
            }

            else if((s[i]>='d' && s[i]<='f') || s[i]=='3' )
            {
                if(k!=3)
                    count++;
                if(s[i]=='3')
                    count+=4;
                else
                   check('d',i);
                k = 3;
            }

            else if((s[i]>='g' && s[i]<='i') || s[i]=='4' )
            {
                if(k!=4)
                    count++;
                if(s[i]=='4')
                    count+=4;
                else
                    check('g',i);
                k = 4;
            }

           else if((s[i]>='j' && s[i]<='l') || s[i]=='5' )
            {
                if(k!=5)
                    count++;
                if(s[i]=='5')
                    count+=4;
                else
                    check('j',i);
                k = 5;
            }

            else if((s[i]>='m' && s[i]<='o') || s[i]=='6' )
            {
                if(k!=6)
                    count++;
                 if(s[i]=='6')
                    count+=4;
                else
                  check('m',i);
               k = 6;
            }

            else if((s[i]>='p' && s[i]<='s') || s[i]=='7' )
            {
                if(k!=7)
                    count++;
                if(s[i]=='7')
                    count+=5;
                 else
                   check('p',i);
                k = 7;
            }

            else if((s[i]>='t' && s[i]<='v') || s[i]=='8')
            {
                if(k!=8)
                    count++;
                 if(s[i]=='8')
                    count+=4;
                  else
                    check('t',i);
                 k = 8;
            }

            else if((s[i]>='w' && s[i]<='z') || s[i]=='9' )
            {
                if(k!=9)
                    count++;
                 if(s[i]=='9')
                    count+=5;
                 else
                    check('w',i);
                k = 9;
            }
            else if(s[i]=='_' || s[i]=='0')
            {
                if(k!=0)
                    count++;
                if(s[i]=='0')
                    count+=2;
                else
                    count++;
                k=0;
            }
        }
        printf("%d ",count);
    }
}
void check(char a,int i)
{
    while(1)
    {
     count++;
     if(s[i] == a )
         break;
     else
         a++;
    }
}
