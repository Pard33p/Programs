#include<stdio.h>
void main()
{
    int k,i,j,a[]={9,8,7,6,5,4,3,2};
    for(i=0;i<8;i++)
    {
        for(j=0;j<7;j++)
        {
            if(a[j]>a[j+1])
            {
                k=a[j+1];
                a[j+1]=a[j];
                a[j]=k;
            }
        }
    }
   for(i=0;i<8;i++)
   {
       printf("%d ",a[i]);
   }

}
