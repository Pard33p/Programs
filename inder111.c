#include<stdio.h>
main()
{
    int a[50],b[50];
    int x,y;
    printf("enter no. of stacks and at most balls\n");
    scanf("%d %d",&x,&y);
    printf("enter no. of balls in each stack\n");
    int c=0,d=0,e=0,c1=0,z=0;
    for(c=0;c<x;c++)
        scanf("%d",&a[c]);
        for(c=0;c<x;c++)
        { int i=0,count=0,sum=0;
        i=a[c];
            if(a[c]<=y)
            {
            for(d=c+1;d<x;d++)
                {
                if(a[d]<=y && count==0)
                    {sum=i+a[d];
                    count++;
                    }
                      else if(a[d]<=y && count!=0)
                      {sum=sum+a[d];}
                      else
                    break;}
                b[e]=sum;
                e++;
                c1++;
            }
            else
                continue;
        }

      int max=0;
        for(z=0;z<c1;z++)
        {
            if(b[z]>max)
                max=b[z];
            else continue;
        }
        printf("the max is:\n%d",max);

        }


