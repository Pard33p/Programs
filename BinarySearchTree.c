#include<stdio.h>
struct node
{
    int info;
    struct node * lchild;
    struct node * rchild;
};
struct node * insert(struct node * root , int item);
void preorder(struct node *);
void inorder(struct node * );
struct node * delCase1(struct node * root , struct node * par , struct node * ptr);
struct node * delCase2(struct node * root , struct node * par , struct node * ptr);
struct node * delCase3(struct node * root , struct node * par , struct node * ptr);
int search(struct  node * ptr , int key);
struct node * del(struct node * root , int key);
int height(struct node * ptr);
int main()
{
    struct node * root = NULL;
    int choice , item , n;
    while(1)
    {
        printf("\n1.Create BST\n2.Insert\n3.Delete\n4.Display(Pre-order)\n5.Display(In-order)\n6.Height\n7.Search\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter no. of nodes : ");
            scanf("%d",&n);
            while(n--)
            {
                printf("Enter the node : ");
                scanf("%d",&item);
                root = insert(root , item);
            }
            printf("BST created successfully\n");
            break;
        case 2:
            printf("Enter the node : ");
            scanf("%d",&item);
            root = insert(root , item);
            printf("Node inserted successfully\n");
            break;
        case 3:
            printf("Enter the node to delete : ");
            scanf("%d",&item);
            root = del(root , item);
            printf("Node deleted successfully\n");
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            printf("Height : %d\n",height(root));
            break;
        case 7:
            printf("Enter the key to search : ");
            scanf("%d",&item);
            if(search(root , item))
                printf("Key Found\n");
            else
                printf("Key Not Found\n");
            break;
        default:
            exit(0);
        }
    }
}
struct node * insert(struct node * root , int item)
{
   struct node * temp , * par , * ptr;
   ptr = root;
   par = NULL;
   while(ptr != NULL)
   {
       par = ptr;
       if(item < ptr->info)
           ptr = ptr->lchild;
       else if(item > ptr->info)
           ptr = ptr->rchild;
       else
       {
           printf("Duplicate Item\n");
           return root;
       }
   }
   temp = (struct node *)malloc(sizeof(struct node));
   temp->info = item;
   temp->lchild = NULL;
   temp->rchild = NULL;
   if(par == NULL)
       root = temp;
   else if(item < par->info)
       par->lchild = temp;
   else if(item > par->info)
       par->rchild = temp;
   return root;
}
void preorder(struct  node * ptr)
{
    if(ptr == NULL)
        return;
    printf("%d  ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node * ptr)
{
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d  ",ptr->info);
    inorder(ptr->rchild);
}
struct node * del(struct node * root , int key)
{
   struct node * par , * ptr;
   ptr = root;
   par = NULL;
   while(ptr)
   {
       if(ptr->info == key)
          break;
       par = ptr;
       if(key < ptr->info)
          ptr = ptr->lchild;
       else
          ptr = ptr->rchild;
   }
   if(ptr == NULL)
   {
       printf("Key not found\n");
       return root;
   }
   if(ptr->lchild != NULL && ptr->rchild != NULL)
      root = delCase3(root , par , ptr);
   else if(ptr->lchild != NULL)
      root = delCase2(root , par , ptr);
   else if(ptr->rchild != NULL)
      root = delCase2(root , par , ptr);
   else
      root = delCase1(root , par , ptr);
   return root;
}
struct node * delCase1(struct node * root , struct node * par , struct node * ptr)
{
       if(par == NULL)
         root = NULL;
       else if(ptr == par->lchild)
         par->lchild = NULL;
       else
         par->rchild = NULL;
       free(ptr);
       return root;
}
struct node * delCase2(struct node * root , struct node * par , struct node * ptr)
{
   struct node * child;
   if(ptr->lchild != NULL)
        child = ptr->lchild;
   else
        child = ptr->rchild;
   if(par == NULL)
      root = child;
   else if(ptr == par->lchild)
      par->lchild = child;
   else
    par->rchild = child;
   free(ptr);
   return root;
}
struct node * delCase3(struct node * root , struct node * par , struct node * ptr)
{
   struct node * succ  , *parsucc ;
   parsucc = ptr;
   succ = ptr->rchild;
   while(succ->lchild)
   {
       parsucc = succ;
       succ = succ->lchild;
   }
   ptr->info = succ->info;
   if(succ->lchild == NULL && succ->rchild == NULL)
      root = delCase1(root , parsucc , succ);
   else
      root = delCase2(root , parsucc , succ);
   return root;
}
int height(struct node * ptr)
{
    int hLeft , hRight;
    if(ptr == NULL)
        return 0;
    hLeft = height(ptr->lchild);
    hRight = height(ptr->rchild);
    if(hLeft > hRight)
        return 1 + hLeft;
    else
        return 1 + hRight;
}
int search(struct  node * ptr , int key)
{
    if(ptr == NULL)
        return 0;
    if(ptr->info == key)
        return 1;
    else if(key < ptr->info)
        return search(ptr->lchild , key);
    else
        return search(ptr->rchild , key);
}
