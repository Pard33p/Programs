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
int height(struct treenode * ptr);
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
        printf("\n1.Create Inorder List\n2.Create Preorder List\n3.Create Tree\n4.Display PreOrder\n5.Display InOrder\n6.Display PostOrder\n7.Height\n");
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
        case 7:
            printf("Height of Tree : %d\n",height(root));
            break;
        default:
            exit(0);
        }
    }
}
struct listnode * createList(struct listnode *start , char item)                      //create linked list
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
struct treenode *createTree(struct listnode * pre , struct listnode * in , int num)               //for creating tree
{
    struct treenode *temp;               //the tree node which is to be created and returned
    struct listnode *q;
    int i , j;
    if(num == 0)                               //if no element is to be created then return NULL
        return NULL;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->info = pre->info;               //as the first element of preorder is root node , so assign its value to temp
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(num == 1)                               //if only one node is to be created then return temp here
        return temp;
    q = in;
    for(i = 0; q->info != pre->info; i++)               //traverse the inorder until its element is equal to the root
        q = q->next;                                            //after this loop , q will point to root node and i  will be the no. of nodes left to root node
    temp->lchild = createTree(pre->next , in , i);  //for left child of root node , preorder will start from next to first element and inorder will start from starting
    for(j = 1; j <= i+1; j++)
        pre = pre->next;                                      //making preorder pointer to point the node after traversing nodes equal to i + 1
    temp->rchild = createTree(pre , q->next, num - i - 1);   //for root node's right child inorder will start from next to root node
    return temp;
}
void displayPre(struct treenode * root)
{
    if(root == NULL)
        return;
    printf("%c ",root->info);
    displayPre(root->lchild);
    displayPre(root->rchild);
}
void displayIn(struct treenode * root)
{
    if(root == NULL)
        return;

    displayIn(root->lchild);
    printf("%c ",root->info);
    displayIn(root->rchild);
}
void displayPost(struct treenode * root)
{
    if(root == NULL)
        return;

    displayPost(root->lchild);
    displayPost(root->rchild);
    printf("%c ",root->info);
}
int height(struct treenode * ptr)
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
