#include<stdio.h>
struct node
{
    int info;
    struct node * lchild , * rchild;
    int height;
};
int height(struct node * ptr)
{
    if(ptr == NULL)
        return 0;
    return ptr->height;
}
int max(int a , int b)
{
    return a > b ? a : b;
}
struct node * rotateRight(struct node * root)
{
   struct node * newRoot = root->lchild;
   root->lchild = newRoot->rchild;
   newRoot->rchild = root;

   newRoot->height = max(height(newRoot->lchild) , height(newRoot->rchild)) + 1;
   root->height = max(height(root->lchild) , height(root->rchild)) + 1;

   return newRoot;
}
struct node * rotateLeft(struct node * root)
{
   struct node * newRoot = root->rchild;
   root->rchild = newRoot->lchild;
   newRoot->lchild = root;

   newRoot->height = max(height(newRoot->lchild) , height(newRoot->rchild)) + 1;
   root->height = max(height(root->lchild) , height(root->rchild)) + 1;

   return newRoot;
}
struct node * insert(struct node * ptr , int key)
{
      if(ptr == NULL)
      {
          ptr = (struct node *)malloc(sizeof(struct node));
          ptr->info = key;
          ptr->lchild = NULL;
          ptr->rchild = NULL;
          ptr->height = 1;
          return ptr;
      }
      if(key < ptr->info)
        {
            ptr->lchild = insert(ptr->lchild , key);
        }
      else if(key > ptr->info)
        {
            ptr->rchild = insert(ptr->rchild , key);
        }

      ptr->height = max(height(ptr->lchild) , height(ptr->rchild)) + 1;

      int balance = getBalance(ptr);

      if(balance > 1 && key < ptr->lchild->info)
        return rotateRight(ptr);

      if(balance < -1 && key > ptr->rchild->info)
        return rotateLeft(ptr);

      if(balance > 1 && key > ptr->lchild->info)
      {
          ptr->lchild = rotateLeft(ptr->lchild);
          return rotateRight(ptr);
      }

      if(balance < -1 && key < ptr->rchild->info)
      {
          ptr->rchild = rotateRight(ptr->rchild);
          return rotateLeft(ptr);
      }
      return ptr;

}
int getBalance(struct node * ptr)
{
    if(ptr == NULL)
        return 0;
    return height(ptr->lchild) - height(ptr->rchild);
}
void preorder(struct node * ptr)
{
    if(ptr == NULL)
        return;
    printf("%d(%d)  ",ptr->info , getBalance(ptr));
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node * ptr)
{
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d(%d)  ",ptr->info , getBalance(ptr));
    inorder(ptr->rchild);
}


int main()
{
    struct node * root = NULL;
    int choice , key , n;
    while(1)
    {
        printf("\n1.Create AVL\n2.Insert\n3.Display(PreOrder)\n4.Display(InOrder)\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter number of nodes : ");
            scanf("%d",&n);
            while(n--)
            {
                printf("Enter the key : ");
                scanf("%d",&key);
                root = insert(root , key);
            }
            break;
        case 2:
            printf("Enter the key : ");
            scanf("%d",&key);
            root = insert(root , key);
            break;
        case 3:
            printf("\nPre Order Traversal is :\n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nInOrder Traversal is :\n");
            inorder(root);
            printf("\n");
            break;

        }
    }
}
