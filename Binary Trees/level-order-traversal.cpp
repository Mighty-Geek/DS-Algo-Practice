#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

/*
// O(n^2)

void printCurrLevel(Node *root, int level);
int height(Node *node);
Node *newNode(int data);

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (int i = 0; i <= h; i++)
    {
        printCurrLevel(root, i);
    }
}

void printCurrLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrLevel(root->left, level - 1);
        printCurrLevel(root->right, level - 1);
    }
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
*/

// using queue O(n)

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;

    q.push(root);

    while (q.empty() == false)
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

Node *newNode(int d)
{
    Node *new_node = new Node();
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(33);
    root->left->left = newNode(24);
    root->left->right = newNode(15);

    cout << "Level order traversal : \n";
    printLevelOrder(root);

    return 0;
}