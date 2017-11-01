#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
struct node *add(struct node *start);
struct node *create_list(struct node *start)
{
    int n,i;
    start = NULL;
   printf("\nEnter the size of list : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
       start = add(start);
   return start;
}
struct node *add(struct node *start)
{
    int item;
    printf("Enter the element : ");
    scanf("%d",&item);
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)  //if list is empty
    {
        temp->next = NULL;
        start = temp;
        return start;
    }
    p = start;
    while(p->next != NULL)
        p = p->next;
    temp->next = p->next;
    p->next = temp;
    return start;
}
void display(struct node *start)
{
    struct node *p;
    p = start;
    while(p != NULL)
    {
        printf("%d  ",p->info);
        p = p->next;
    }
    printf("\n");
}
struct node *loopMaker(struct node *start)
{
   struct node *p , *q;
   p = start;
   q = start->next->next->next;
   while(p->next)
        p = p->next;
   p->next = q;
   return start;
}
struct node *loopCheck(struct node *start)
{
   struct node *fast , *slow;
   fast = slow = start;
   while(fast && slow && fast->next)
   {
       fast = fast->next->next;
       slow = slow->next;
       if(fast == slow)
       {
           //printf("Loop Detected !!");
           return fast;
       }
   }
}
struct node *loopStart(struct node *start)
{
   struct node *slow = start , *fast;
      fast = loopCheck(start);
      while(fast != slow)
      {

          fast = fast->next;
          slow = slow->next;
      }
      return fast;
}
 int loc(struct node *start)
{
    int count = 0;
    struct node *slow = start , *fast , *p;
    fast = loopCheck(start);
    p = fast;
    do
    {
        count++;
        //printf("hello");
        p = p->next;
    }while(p != fast);
    return count;
}
int lonc(struct node *start)
{
    int count = 0;
    struct node *slow = start , *fast ;
    fast = loopCheck(start);
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
        count++;
    }
    return count;

}
struct node *remLoop(struct node *start)
{
   struct node *slow = start , *fast , *prev;
   fast = loopCheck(start);
   while(fast != slow)
   {
       prev = fast;
       fast = fast->next;
       slow = slow->next;
   }
   prev->next = NULL;
   return start;
}
void main()
{
    struct node *start = NULL,*fast,*startLoop;
    start = create_list(start);
    display(start);
    start = loopMaker(start);
    startLoop = loopStart(start);
    printf("\nLoop Starting at %d\n",startLoop->info);
    printf("\nLoop length : %d",loc(start));
    printf("\nNon - Loop length : %d\n",lonc(start));
    start = remLoop(start);
    fast = loopCheck(start);
    display(start);
    //fast = loopCheck(start);
}
