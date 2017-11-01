#include<stdio.h>
struct node
{
    int info;
    struct node *link;
}*front = NULL , *rear = NULL;

int main()
{
   int choice , item ;
   while(1)
   {
       printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("Enter the element : ");
        scanf("%d",&item);
        enq(item);
        break;
       case 2:
        printf("Dequeued element is %d\n",deq());
        break;
       case 3:
        display();
        break;
       default:
        exit(0);
       }
   }
    return 0;
}
void enq(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(!temp)
    {
        printf("Queue Overflow\n");
        return;
    }
    temp->info = item;
    if(front == NULL)
    {
        front = temp;
        temp->link = NULL;
        rear = temp;
        return;
    }
    rear->link = temp;
    temp->link = NULL;
    rear = temp;
}
int deq()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    temp = front;
    int item = temp->info;
    front = front->link;
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
    struct node *p = front;
    while(p)
    {
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n");
}
