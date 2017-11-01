#include<stdio.h>
struct treenode
{
    int info;
    struct treenode * lchild;
    struct treenode * rchild;
};

struct treenode * insert(struct treenode * root , int item);
struct treenode * min(struct treenode * ptr);
struct treenode * del(struct treenode * root , int key);
struct treenode * search(struct treenode * ptr , int key);
struct treenode * max(struct treenode * ptr);
struct treenode * caseA(struct treenode * root , struct treenode * parent , struct treenode * ptr);
struct treenode * caseB(struct treenode * root , struct treenode * parent , struct treenode * ptr);
struct treenode * caseC(struct treenode * root , struct treenode * parent , struct treenode * ptr);
void preorder(struct treenode * root);
void postorder(struct treenode * root);
void inorder(struct treenode * root);
int main()

{
    struct treenode * root = NULL;
    int choice , item , n;
    while(1)
    {
        printf("\n1.Create BST\n2.Display(PreOrder)\n3.Display(InOrder)\n4.Display(PostOrder)\n5.Search\n6.Max\n7.Min\n8.Delete\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the no. of nodes : ");
            scanf("%d",&n);
            while(n--)
            {
                printf("\nEnter the node : ");
                scanf("%d",&item);
                root = insert(root , item);
            }
            printf("BST created successfully ! ! \n");
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the node to be searched : ");
            scanf("%d",&item);
            struct treenode * temp;
            temp = search(root , item);
            if(temp == NULL)
                printf("Node not found\n");
            else
                printf("Node found %d\n",temp->info);
            break;
        case 6:
            //struct treenode * temp;
            temp = max(root);
            if(temp != NULL)
                  printf("Max node is %d\n",temp->info);
            break;
        case 7:
            //struct treenode * temp;
            temp = min(root);
            if(temp != NULL)
                  printf("Min node is %d\n",temp->info);
            break;
        case 8:
            printf("Enter the node : ");
            scanf("%d",&item);
            root = del(root , item);
            break;
        default:
            exit(0);
        }

    }
}
struct treenode * insert(struct treenode * root , int item)
{
   struct treenode *temp , *ptr , *par;
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
           printf("Duplicate key\n");
           return;
       }
   }
   temp = (struct treenode *)malloc(sizeof(struct treenode));
   temp->info = item;
   temp->lchild = NULL;
   temp->rchild = NULL;
   if(par == NULL)
       root = temp;
    else if(item < par->info)
        par->lchild = temp;
    else
        par->rchild = temp;
    return root;

}
void preorder(struct treenode * root)
{

    if(root == NULL)
    {
        return;
    }
    struct treenode * ptr = root;
    printf("%d ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct treenode * root)
{
    if(root == NULL)
    {
        return;
    }
     struct treenode * ptr = root;
    inorder(ptr->lchild);
    printf("%d ",ptr->info);
    inorder(ptr->rchild);
}
void postorder(struct treenode * root)
{
    if(root == NULL)
    {
        return;
    }
     struct treenode * ptr = root;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->info);
}
struct treenode * search(struct treenode * ptr , int key)
{
   if(ptr == NULL)
        return NULL;
   else if(key == ptr->info)
        return ptr;
   else if(key < ptr->info)
        return search(ptr->lchild , key);
   else
       return search(ptr->rchild , key);
}
struct treenode * max(struct treenode * ptr)
{
   if(ptr == NULL)
        return NULL;
   else if(ptr->rchild == NULL)
        return ptr;
   else
      return max(ptr->rchild);
}
struct treenode * min(struct treenode * ptr)
{
    if(ptr == NULL)
        return NULL;
    else if(ptr->lchild == NULL)
        return ptr;
    else
        return min(ptr->lchild);
}
struct treenode * del(struct treenode * root , int key)
{
  struct treenode * parent , *ptr ;
  ptr = root;
  parent = NULL;
  while(ptr != NULL)
  {
      if(key == ptr->info)
        break;
      parent = ptr;
      if(key < ptr->info)
        ptr = ptr->lchild;
      else
        ptr = ptr->rchild;
  }
  if(ptr == NULL)
    printf("Key Not Present\n");
  else if(ptr->lchild != NULL && ptr->rchild != NULL)
    root = caseC(root , parent , ptr);
  else if(ptr->lchild != NULL)
    root = caseB(root , parent , ptr);
  else if(ptr->rchild != NULL)
    root = caseB(root , parent , ptr);
  else
    root = caseA(root , parent , ptr);

}
struct treenode * caseA(struct treenode * root , struct treenode * parent , struct treenode * ptr)
{
  if(parent == NULL)
        root = NULL;
  else if(ptr == parent->lchild)
        parent->lchild = NULL;
  else
       parent->rchild = NULL;
  free(ptr);
  return root;
}
struct treenode * caseB(struct treenode * root , struct treenode * parent , struct treenode * ptr)
{
   struct treenode * child;
   if(ptr->lchild != NULL)
        child = ptr->lchild;
   else
        child = ptr->rchild;
   if(parent == NULL)
      root = child;
   else if(ptr == parent->lchild)
       parent->lchild = child;
   else
     parent->rchild = child;
   free(ptr);
   return root;
}
struct treenode * caseC(struct treenode * root , struct treenode * parent, struct treenode * ptr)
{
//    bool k;
   struct treenode *succ , *parsucc;
   parsucc = ptr;
   succ = ptr->rchild;
   while(succ->lchild)
   {
       parsucc = succ;
       succ = succ->lchild;
   }
   ptr->info = succ->info;
   if(succ->lchild == NULL && succ->rchild == NULL)
      root = caseA(root , parsucc , succ);
   else
     root = caseB(root , parsucc , succ);
   return root;
}
