#include<stdio.h>
struct node
{
    int info;
    int priority;
    struct node * link;
} * front = NULL;
int main()
{
    int choice , item , prio;
    while(1)
    {
        printf("\n1.Insert\n2.Delete(Highest Priority)\n3.Delete(Lowest Priority)\n4.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item : ");
            scanf("%d",&item);
            printf("Enter its Priority : ");
            scanf("%d",&prio);
            insert(item , prio);
            break;
        case 2:
            printf("Deleted Item is : %d\n",delH());
            break;
        case 3:
            printf("Deleted Item is : %d\n",delL());
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}
void insert(int item , int prio)
{
    struct node * temp , *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->priority = prio;
    if(front == NULL || front->priority > prio)
    {
        temp->link = front;
        front = temp;
        return;
    }
    ptr = front;
    while(ptr->link != NULL && ptr->link->priority <= prio)
       ptr = ptr->link;
     temp->link = ptr->link;
     ptr->link = temp;
}
int delH()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    struct node * temp = front;
    int item = temp->info;
    front = front->link;
    free(temp);
    return item;
}
int delL()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    struct node * p , * temp;
    p = front;
    while(p->link->link)
      p = p->link;
     temp = p->link;
     int item = temp->info;
     p->link = temp->link;
      free(temp);
      return item;
}
void display()
{
    if(front == NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    struct node * p = front;
    printf("\n");
    printf("Item\tPriority\n");
    while(p)
    {
        printf("%d\t%d\n",p->info,p->priority);
        p = p->link;
    }
}
