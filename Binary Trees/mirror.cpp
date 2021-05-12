#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << "--s";
    inorder(root->right);
}

Node *mirrorify(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left)
        mirrorify(root->left);

    if (root->right)
        mirrorify(root->right);

    return root;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    cout << "Original tree is : \t";
    inorder(root);
    cout << endl;

    Node *mirror_root = mirrorify(root);

    cout << "Mirror tree is : \t";
    inorder(mirror_root);
    cout << endl;
}