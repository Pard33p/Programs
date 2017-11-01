#include<stdio.h>
struct  node
{
    int info;
    struct node *lchild , * rchild;
    int height;
};
struct node * insert(struct node * ptr , int key);
void preorder(struct node * ptr);
void inorder(struct node * ptr);
int height(struct node * ptr);
int getBalance(struct node * ptr);
int max (int a , int b);
struct node * leftRotate(struct node * root);
struct node * rightRotate(struct node * root);
int main()
{
    struct node * root = NULL;
    int choice , item , n;
    while(1)
    {
        printf("\n1.Create AVL\n2.Insert\n3.Delete\n4.Display(PreOrder)\n5.Display(InOrder)\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number of nodes : ");
            scanf("%d",&n);
            while(n--)
            {
                printf("Enter the key : ");
                scanf("%d",&item);
                root = insert(root , item);
            }
            break;
        case 2:
            printf("Enter the key : ");
            scanf("%d",&item);
            root = insert(root , item);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        default:
            exit(0);
        }
    }
}

struct node * insert(struct node * ptr , int key)
{
    //1.Normal BST Insertion
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
      //2.Update height of this ancestor node
     ptr->height = max(height(ptr->lchild) , height(ptr->rchild)) + 1;
     //3.Get its Balance factor
      int balance = getBalance(ptr);
     //if this node becomes unbalanced then there are 4 cases

      //Left Left case - perform single right rotation
      if(balance > 1 && key < ptr->lchild->info)
            return rightRotate(ptr);
       //Right Right case - perform single left rotation
      if(balance < -1 && key > ptr->rchild->info)
            return leftRotate(ptr);
       //Left Right Case
      if(balance > 1 && key > ptr->lchild->info)
      {
          ptr->lchild = leftRotate(ptr->lchild);
          return rightRotate(ptr);
      }
      //Right Left Case
      if(balance < -1 && key < ptr->rchild->info)
      {
          ptr->rchild = rightRotate(ptr->rchild);
          return leftRotate(ptr);
      }
      return ptr;// return unchanged node if it is balanced
}
void preorder(struct node * ptr)
{
    if(ptr == NULL)
        return;
    printf("%d(%d)  ",ptr->info,getBalance(ptr));
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node * ptr)
{
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d(%d)  ",ptr->info, getBalance(ptr));
    inorder(ptr->rchild);
}
int height(struct node * ptr)
{
    if(ptr == NULL)
        return 0;
    return ptr->height;
}
int max (int a , int b)
{
    return a > b ? a : b;
}
struct node * rightRotate(struct node * root)
{
      struct node * newRoot = root->lchild;
      root->lchild = newRoot->rchild;
      newRoot->rchild = root;
      //update heights
      root->height = max(height(root->lchild) , height(root->rchild)) + 1;
      newRoot->height = max(height(newRoot->lchild) , height(newRoot->rchild)) + 1;

      return newRoot;
}
struct node * leftRotate(struct node * root)
{
   struct node * newRoot = root->rchild;
   root->rchild = newRoot->lchild;
   newRoot->lchild = root;

    root->height = max(height(root->lchild) , height(root->rchild)) + 1;
    newRoot->height = max(height(newRoot->lchild) , height(newRoot->rchild)) + 1;

    return newRoot;
}
int getBalance(struct node * ptr)
{
    if(ptr == NULL)
        return 0;
    return height(ptr->lchild) - height(ptr->rchild);
}
