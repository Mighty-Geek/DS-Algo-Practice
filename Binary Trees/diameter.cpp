#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

Node *newNode(int d)
{
    Node *new_node = new Node();
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_h = height(node->left);
        int right_h = height(node->right);

        return (1 + max(left_h, right_h));
    }
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int left_h = height(root->left);
    int right_h = height(root->right);

    int left_d = diameter(root->left);
    int right_d = diameter(root->right);

    return max(left_h + right_h + 1, max(left_d, right_d));
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(3);
    root->right->left = newNode(5);

    cout << "Diameter of binary tree : " << diameter(root);

    return 0;
}