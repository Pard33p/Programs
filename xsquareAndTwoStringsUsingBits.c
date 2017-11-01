#include<stdio.h>
void main()
{
    char s1[20] , s2[20];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        char p;
        int mask1 , mask2 , flag = 0 , i ;
        mask1 = mask2 = 0;
        for(i = 0; i < strlen(s1) ; i++)
            mask1 = mask1 | (1 << (s1[i] - 'a'));    //let mask is having 26 bits , each representing an alphabet. if certain alphabet is present in string , set the bit in mask corresponding to that alphabet.
        for(i = 0; i < strlen(s2) ; i++)
            mask2 = mask2 | (1 << (s2[i] - 'a'));   //for example if a is present in string then set the 1st bit in mask and so on..
         for(p = 'a' ; p <= 'z' ; p++)
         {
             if(mask1 & (1 << (p - 'a') ))   //if same bit is set in mask1 and mask2 then print yes .
             {
                 if(mask2 & (1 << (p - 'a')))
                 {
                     printf("Yes\n");
                     flag = 1;
                     break;
                 }
             }
         }
         if(!flag)
            printf("No\n");
    }
}
