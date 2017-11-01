#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
struct node *create_list(struct node *start);
struct node *odd(struct node **start1);
void display(struct node *start);
struct node *add(struct node *start);
int no_of_occ(struct node *start,int item);
struct node *rev(struct node *start);
struct node *swap_adj_using_info(struct node *start);
struct node *swap_adj_using_link(struct node *start);
struct node *swap_first_last(struct node *start);
struct node *swap_first_last_info(struct node *start);
struct node *move_largest(struct node *start);
struct node *del_N(struct node *start);
struct node *move_1_to_last(struct node *start);
struct node *move_last_to_1st(struct node *start);
struct node *move_n_pos(struct node *start);
struct node *del(struct node *start);
struct node *rem_dupl(struct node *start);
struct node *add_bef_aft(struct node *start);
void main()
{
    struct node *start = NULL;
    int choice,item;

    while(1)
    {
        printf("\n\n1.Create New List\n2.Display\n3.No. Of Occurence\n4.Reverse\n5.Swap Adjacent Elements(using info)\n6.Swap Adjacent Elements(using links)");
        printf("\n7.Swap 1st and Last element(using links)\n8.Swap 1st and Last element(using info)\n9.Move Largest Element to Last\n10.Delete All Nodes Having value N\n11.Move 1st element to last");
        printf("\n12.Move Last element to 1st\n13.Move element n positions\n14.Delete\n15.Insert nodes before and after a given node\n16.Remove Duplicate\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Enter the element : ");
            scanf("%d",&item);
            printf("%d occurs %d times\n",item,no_of_occ(start,item));
            break;
        case 4:
            start = rev(start);
            break;
        case 5:
            start = swap_adj_using_info(start);
            break;
        case 6:
            start = swap_adj_using_link(start);
            break;
        case 7:
            start = swap_first_last(start);
            break;
        case 8:
            start = swap_first_last_info(start);
            break;
        case 9:
            start = move_largest(start);
            break;
        case 10:
            start = del_N(start);
            break;
        case 11:
            start = move_1_to_last(start);
            break;
        case 12:
            start = move_last_to_1st(start);
            break;
        case 13:
            start = move_n_pos(start);
            break;
        case 14:
            start = del(start);
            break;
        case 15:
            start = add_bef_aft(start);
            break;
        case 16:
            start = rem_dupl(start);
            break;
        default:
            exit(0);
        }
    }
}
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
int no_of_occ(struct node *start,int item)
{
    struct node *p;
    int count = 0;
    p = start;
    while(p!=NULL)
    {
        if(p->info == item)
            count++;
        p = p->next;
    }
    return count;
}
struct node *rev(struct node *start)
{
   struct node *p,*next1,*prev;
   prev = NULL;
   p = start;
   while(p!=NULL)
   {
       next1 = p->next;   //storing p->next because it will be required to move ahead
       p->next = prev;    //changing link of current node to previous node
       prev = p;          //now previous points to current node because current node will become previous node in next pass
       p = next1;         //move to next node
   }
   start = prev;  //IMPORTANT - when loop ends, prev becomes first node , so start points to it.
   return start;
}
struct node *swap_adj_using_info(struct node *start)
{
   struct node *ptr;
   int temp;
   ptr = start;
   while(ptr->next!=NULL)
   {
       temp = ptr->info;
       ptr->info = ptr->next->info;
       ptr->next->info = temp;
       ptr = ptr->next->next;
       if(ptr==NULL)      //for even list
        break;
   }
   return start;
}
struct node *swap_adj_using_link(struct node *start)
{
 struct node *p,*q,*r;
 r = p =start;
 while(p->next != NULL)
 {
     q = p->next;
     p->next = q->next;
     q->next = p;
     if(p!=start)
        r->next = q;
     else
        start = q;
     r = p;
     if(p->next != NULL)
        p = p->next;
 }
 return start;
}
struct node *swap_first_last(struct node *start)
{
    struct node *p,*q,*temp;
    temp = start;
    p = start;
    while(p->next->next != NULL)
        p = p->next;
    q = p->next;
    q->next = start->next;
    start = q;
    p->next = temp;
    temp->next = NULL;
        return start;
}
struct node *swap_first_last_info(struct node *start)
{
    int temp;
    struct node *p;
    p = start;
    while(p->next != NULL)
        p = p->next;
    temp = p->info;
    p->info = start->info;
    start->info = temp;
    return start;

}
struct node *move_largest(struct node *start)
{
   struct node *p,*q;
   int temp;
   for(p = start;p->next!=NULL;p=p->next)
   {
       q = p->next;
       if(p->info > q->info)
       {
           temp = p->info;
           p->info = q->info;
           q->info = temp;
       }
   }
    return start;
}
struct node *del_N(struct node *start)
{
    int item;
    struct node *p;
   printf("Enter the element to delete : ");
   scanf("%d",&item);
   if(start->info == item)
   {
       start = start->next;
   }
   p = start;
   while(p->next != NULL)
   {
       if(p->next->info == item)
       {
           p->next = p->next->next;
           continue;
       }
       p = p->next;
   }
   return start;
}
struct node *move_1_to_last(struct node *start)
{
    struct node *p,*temp;
    temp = start;
    p = start;
    start = start->next;

    while(p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->next = NULL;

    return start;
}
struct node *move_last_to_1st(struct node *start)
{
  struct node *p,*temp;
  p = start;
  while(p->next->next != NULL)
    p = p->next;
  temp = p->next;
  p->next = NULL;
  temp->next = start;
  start = temp;
  return start;
}
struct node *move_n_pos(struct node *start)
{
 struct node *p,*t,*q,*r;
 int item,n;
 printf("\nEnter the node : ");
 scanf("%d",&item);
 printf("n : ");
 scanf("%d",&n);
 if(start->info == item)
   {
     r = start;
     p = start;
   }
 else
{
 p = start;
 while(p->next!=NULL)
 {
     if(p->next->info == item)
     {
         r = p;
         break;
     }
     p = p->next;
 }
 p = r->next;
 }

 while(p->next!=NULL && n--)
 {
     q = p->next;
     p->next = q->next;
     q->next = p;
     if(r == start)
        start = q;
     else
        r->next = q;

     t = p;
     p = q;
     q = t;

     r = p;
     p = p->next;
 }
 return start;
}
struct node *del(struct node *start)
{
  struct node *p,*temp;
  int item;
  printf("Enter the element to delete : ");
  scanf("%d",&item);
  p = start;
  while(p!=NULL)
   {
       if(p->info == item)
        break;
       p = p->next;
   }
   temp = p->next;
   p->info = temp->info;
   p->next = temp->next;
   free(temp);
   return start;
}
struct node *add_bef_aft(struct node *start)
{
  struct node *p,*q,*temp1,*temp2;
  temp1 = (struct node * )malloc(sizeof(struct node));
  temp2 = (struct node * )malloc(sizeof(struct node));
  int item,a,b,t;
  printf("Enter the node : ");
  scanf("%d",&item);
  printf("\nEnter the nodes to be inserted before and after the given node : ");
  scanf("%d%d",&a,&b);
  p = start;
  while(p!=NULL)
  {
      if(p->info == item)
        break;
      p = p->next;
  }
  temp1->info = a;
  temp2->info = b;
  temp1->next = p->next;
  p->next = temp1;
  temp2->next = temp1->next;
  temp1->next = temp2;
  t = p->info;
  p->info = temp1->info;
  temp1->info = t;
  return start;
}
struct node *rem_dupl(struct node *start)
{
  struct node *p,*prev,*temp;
  p = start->next;
  prev = start;
  while(p!=NULL)
  {
      if(p->info == prev->info)
      {
          //temp = p;
          prev->next = p->next;
          //free(temp);
      }
      else
         prev = p;
      p = p->next;
  }
  return start;
}

