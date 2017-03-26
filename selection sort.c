//selection sort
#include<stdio.h>
void main()
{
    int i,j,l,a[10]={3,2,6,4,9,7,10,23,22,25};
    int *p;
    p=a;
    for(i=0;i<10;i++)
    {
        for(j=i;j<10;j++)
        {
            if(a[i]>a[j])
            {
                l=a[i];
                a[i]=a[j];
                a[j]=l;
            }
        }


    }
  for(i=0;i<10;i++)
  {
      printf("%d ",*p);
      p++;


  }
}
