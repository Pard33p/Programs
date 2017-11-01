#include<stdio.h>
int main()
{
    int t , n , flag = 0;
    long int arr[1000] , i ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i < n ; i++)
            scanf("%lld",&arr[i]);
          flag = 0;
        while(1)
        {
            int c = 0;
            for(i = 0; i < n ; i++)
            {
                if(arr[i] % 2 == 0)
                {
                    arr[i] /= 2;
                    c = 1;
                    flag = !flag;
                    break;
                }
            }
           if(c == 0)
            break;

        }
        flag == 0 ? printf("Alan\n") : printf("Charlie\n");
    }
}
