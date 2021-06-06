// Inorder, Preorder, Postorder traversal using recursion

// Inorder: left -> root -> right
// Preorder: root -> left -> right
// Postorder: left -> right -> root

// Time complexity: T(n) = T(k) + T(n-k-1) + c = O(n)
// Corner case 1: skewed tree k=0 T(n) = n(c+d) = theta(n)
// Corner case 2: left and right subtrees have equal nodes T(n) = theta(n) [master method]

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        data = d;
        left = right = NULL;
    }
};
TreeNode *insertNode(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    if (val > root->data)
    {
        root->right = insertNode(root->right, val);
    }
    else
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}
void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}
int main()
{
    TreeNode *root = new TreeNode(10);
    insertNode(root, 30);
    insertNode(root, 50);
    insertNode(root, 80);
    insertNode(root, 20);
    insertNode(root, 0);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0;
}