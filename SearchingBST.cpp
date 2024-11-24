#include <iostream>
using namespace std;
// Creation of Node
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
Node *Insert(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        Node *temp = new Node(target);
        return temp;
    }
    if (target < root->data) // left side
        root->left = Insert(root->left, target);
    else
        root->right = Insert(root->right, target);
    return root;
}

bool search(Node *root, int target)
{
    if (root == NULL)
        // return 0;
        cout << "!!Element not found in BST!!";
    if (root->data == target)
        // return 1;
        cout << "!!Element found in BST!!";
    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}
int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
        root = Insert(root, arr[i]);

    cout << "\nSearching Element is : 16" << " ";
    cout << endl;
    cout << search(root, 16) << endl;
}