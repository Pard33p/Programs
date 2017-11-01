#include<iostream>
using namespace std;
class sets
{
    int siz;
    int *ptr;
public:
    void getdata(void);

};
void sets::  getdata(void)
    {  int i=0,a,*pt;
        cout<< "\n Enter the size::";cin>>siz;
        cout<< "\n Enter elements::";
        pt=ptr;
            ptr= new int[siz];
            while( i!=siz)
            {   cin>>a;
                *ptr=a;
                ptr++;
                i++;
            }
            ptr=pt;}

 sets sets::operator -(sets b)
 {  int i,j,k=0;
     for( i=0;i<siz;i++)
     {
         for( j=0;j<b.siz;j++)
         {
             if(ptr[i]==b.ptr[j])
                break;
         }
         if(j!=siz)
         {
               temp.ptr=new int;
         temp.ptr[k]=ptr[j];
         }

     }
     return temp;
 }
void sets::operator +( sets b )
{   int i=0;
    sets temp;
    while(i!=siz)
    {    temp.ptr=new int;
       ptr[i]=ptr[i];
    }


}
int main()
{
    sets s1,s2,s3;
    s1.getdata();
    s2.getdata();
    s3=s1-s2;

}
