#include<stdio.h>
#include<stdlib.h>
struct treenode                          //for tree
{
    char info;
    struct treenode *lchild;
    struct treenode *rchild;
};
struct listnode                              //for preorder and inorder lists
{
    char info;
    struct listnode *next;
};
struct treenode * stack[20];
int top = -1;
void push(struct treenode * p)
{
    if(top == 19)
        return;
    stack[++top] = p;
}
struct treenode * pop()
{
   if(top == -1)
        exit(0);
   return stack[top--];
}
void displayPre(struct treenode * root);
void displayIn(struct treenode * root);
void displayPost(struct treenode * root);
struct treenode *createTree(struct listnode * pre , struct listnode * in , int num);
struct listnode * createList(struct listnode *start , char item);

int main()
{
    struct listnode *inorder = NULL , *preorder = NULL;
    struct treenode *root = NULL;
    int choice , n , num;
    char item;
    while(1)
    {
        printf("\n1.Create Inorder List\n2.Create Preorder List\n3.Create Tree\n4.Display PreOrder\n5.Display InOrder\n6.Display PostOrder\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number of elements : ");
            scanf("%d",&n);
            num = n;
            while(n--)
               {
                   printf("Enter the element : ");
                   fflush(stdin);
                   scanf("%c",&item);
                   inorder = createList(inorder , item);
               }
             break;
        case 2:
            printf("Enter the number of elements : ");
            scanf("%d",&n);
            while(n--)
               {
                   printf("Enter the element : ");
                   fflush(stdin);
                   scanf("%c",&item);
                   preorder = createList(preorder , item);
               }
               break;
        case 3:
            root = createTree(preorder , inorder , num);
            break;
        case 4:
            displayPre(root);
            break;
        case 5:
            displayIn(root);
            break;
        case 6:
            displayPost(root);
            break;
        default:
            exit(0);
        }
    }
}
struct listnode * createList(struct listnode * start  , char item)
{
      struct listnode * temp = (struct listnode *)malloc(sizeof(struct listnode));
   temp->info = item;
   if(start == NULL)
   {
       temp->next = NULL;
       start = temp;
       return start;
   }
   struct listnode *p;
   p = start;
   while(p->next)
     p = p->next;
   temp->next = NULL;
   p->next = temp;
   return start;
}
struct treenode * createTree(struct listnode * pre , struct listnode * in , int num)
{
    struct treenode * temp;
    struct listnode * q;
    int i , j;
    if(num == 0)
        return NULL;
    temp = (struct treenode * )malloc(sizeof(struct treenode));
    temp->info = pre->info;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(num == 1)
        return temp;
    q = in;
    for(i = 0 ; q->info != pre->info ; i++)
        q = q->next;
    temp->lchild = createTree(pre->next , in , i);
    for(j = 1; j<= i+1; j++)
        pre = pre->next;
    temp->rchild = createTree(pre , q->next , num - i - 1);
    return temp;
}
void displayPre(struct treenode * root)
{
    if(root == NULL)
    {
        printf("Tree Empty\n");
        return;
    }
    push(root);
    struct treenode *ptr ;
    while(top != -1)
    {
       ptr = pop();
       printf("%c ",ptr->info);
       if(ptr->rchild != NULL)
            push(ptr->rchild);
       if(ptr->lchild != NULL)
            push(ptr->lchild);
    }
    printf("\n");
}
void displayIn(struct treenode * root)
{
    if(root == NULL)
    {
        printf("Tree Empty\n");
        return;
    }
    struct treenode *ptr = root;
    while(1)
    {
        while(ptr->lchild != NULL)
            {
                push(ptr);
                ptr = ptr->lchild;
            }
        while(ptr->rchild == NULL)
        {
            printf("%c ",ptr->info);
            if(top == -1)
                return;
            ptr = pop();
        }
        printf("%c ",ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}

void displayPost(struct treenode * root)
{
    if(root == NULL)
    {
        printf("Tree Empty\n");
        return;
    }
    struct treenode *ptr = root , *q = root;
    while(1)
    {
        while(ptr->lchild != NULL)
        {
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild == q)
        {
            printf("%c ",ptr->info);
            q = ptr;
            if(top == -1)
                return;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
}
