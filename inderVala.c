#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      long long int arr[1001];
      int n,i=0;
        scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i]%2!=0)
            arr[i]=0;
        }
        int counter=0,j=0;
        while(1)
        {
            int c=0;
            for(i=j;i<n;i++)
            {
                if(arr[i]!=0)
                {
                    c=1;
                if( arr[i]%2==0)
                {
                    arr[i]/=2;
                    j=i-1;
                    counter = !counter;
                    break;

                }
                else
                    arr[i]=0;
                }
            }
            if(!c)
            break;
        }
        if(counter==1)
         printf("Charlie\n");
         else
            printf("Alan\n");
    }
return 0;
}

