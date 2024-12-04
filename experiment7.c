#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};

struct node *create()
{
    int x;
    printf("enter element:");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    printf("enter element for %d",x);
    newnode->left=create();
    printf("enter element for %d",x);
    newnode->right=create();
    return newnode;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
      printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void Inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d",root->data);
    Inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
void display(struct node *root,int space)
{
    if(root==NULL)
    {
        return;
    }
    int index=5;
    space+=index;
    display(root->right,space);
    printf("\n");
    for(int i=index;i<space;i++)
    {
        printf(" ");
    }
    printf("%d\n",root->data);
    display(root->left,space);
}
void main()
{
    struct node *root=create();
    display(root,0);
}

