#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
void Preorder(Node*root){
    if(root==NULL)
    return;
    cout<<root->data;//Node
    Preorder(root->left);//left
    Preorder(root->right);//right
}
void Inorder(Node*root){
    if(root==NULL)
    return;
    Inorder(root->left);//left
    cout<<root->data;//Node
    Inorder(root->right);//right
}
void Postorder(Node*root){
    if(root==NULL)
    return;
    Postorder(root->left);//left
    Postorder(root->right);//right
    cout<<root->data;//Node
}
Node *BinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
    return NULL;

    Node *temp = new Node(x);
    // create left side
    cout << "Enter the left child of " << x << ":";
    temp->left = BinaryTree();
    // create right side
    cout << "Enter the right child of " << x << ":";
    temp->right = BinaryTree();
    return temp;
}
int main()
{   
    //tree creation
    cout << "enter the value of root node:";
    Node *root;
    root = BinaryTree();
    cout<<"-----------------------------------";
    //preorder traversal print
    cout<<"\nPreorder--> ";
    Preorder(root);
    //Inorder traversal print
    cout<<"\nInorder--> ";
    Inorder(root);
    //postorder traversal print
    cout<<"\nPostorder--> ";
    Postorder(root);
}