#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;
    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
};

BST *insert(BST *root, int val)
{
    if (!root)
        return new BST(val);
    if (val > root->data)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);

    return root;
}

void inorder(BST *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BST *search(BST *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    else
        return search(root->left, key);
}

int main()
{
    BST *root = new BST(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    // inorder(root);
    BST *res = search(root, 100);
    if (res)
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    return 0;
}