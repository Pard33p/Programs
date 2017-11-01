#include<stdio.h>
int main()
{
   long int t ,i ,test,j , n , m;
    scanf("%ld",&test);
    while(test--)
    {

        scanf("%ld",&n);
        int max[1000000] =  {0} , min[1000000];
        for(i = 0; i < n ; i++)
            min[i] = 999999;
        for(j = 0 ; j < n ;j++)
        {
            scanf("%ld",&m);
            while(m--)
            {
                scanf("%ld",&t);
                if(t > max[j])
                    max[j] = t;
                if(t < min[j])
                     min[j] = t;
            }
        }
        long int ans = 0 , temp;
        for(i = 0 ; i < n-1 ; i++)
        {
            temp = min[i] > max[i+1] ? min[i] - max[i+1] : max[i+1] - min[i];
            ans = ans + temp * (i+1);
        }
        printf("%ld\n",ans);
    }
}
