#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int sizeBST(Node *node)
{
    if (node == NULL)
        return 0;
    int ls = sizeBST(node->left);
    int rs = sizeBST(node->right);
    int ts = ls + rs + 1;
    return ts;
}
int sumBST(Node *node)
{
    if (node == NULL)
        return 0;
    int lsum = sumBST(node->left);
    int rsum = sumBST(node->right);
    int tsum = lsum + rsum + node->data;
    return tsum;
}
int minBST(Node *node)
{
    if (node->left != NULL)
        return minBST(node->left);
    else
        return node->data;
}
int maxBST(Node *node)
{
    if (node->right != NULL)
        return maxBST(node->right);
    else
        return node->data;
}
bool findIn(Node *node, int val)
{
    if (node == NULL)
        return false;
    if (val > node->data)
        findIn(node->right, val);
    else if (val < node->data)
        findIn(node->left, val);
    else
        return true;
}
Node *addNodeBST(Node *node, int new_val)
{
    if (node == NULL)
    {
        return new Node(new_val);
    }
    if (new_val > node->data)
    {
        node->right = addNodeBST(node->right, new_val);
    }
    else if (new_val < node->data)
    {
        node->left = addNodeBST(node->left, new_val);
    }
    else
    {
        // do nothing
    }
    return node;
}
Node *removeNodeBST(Node *node, int val)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (val > node->data)
    {
        node->right = removeNodeBST(node->right, val);
    }
    else if (val < node->data)
    {
        node->left = removeNodeBST(node->left, val);
    }
    else
    {
        if (node->left != NULL && node->right != NULL)
        {
            int lmax = maxBST(node->left);
            node->data = lmax;
            node->left = removeNodeBST(node->left, lmax);
            return node;
        }
        else if (node->left != NULL)
        {
            return node->left;
        }
        else if (node->right != NULL)
        {
            return node->right;
        }
        return NULL;
    }
    return node;
}
int sum = 0;
void replaceWithSumOfLarger(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    replaceWithSumOfLarger(node->right);
    int od = node->data;
    node->data = sum;
    sum += od;
    replaceWithSumOfLarger(node->left);
}
int lcaBST(Node *node, int val1, int val2)
{
    if (val1 < node->data && val2 < node->data)
    {
        return lcaBST(node->left, val1, val2);
    }
    else if (val1 > node->data && val2 > node->data)
    {
        return lcaBST(node->right, val1, val2);
    }
    else
    {
        return node->data;
    }
}
void printInRange(Node *node, int lo, int hi)
{
    if (node == NULL)
        return;
    if (lo < node->data && hi < node->data)
    {
        printInRange(node->left, lo, hi);
    }
    else if (lo > node->data && hi > node->data)
    {
        printInRange(node->right, lo, hi);
    }
    else
    {
        printInRange(node->left, lo, hi);
        cout << node->data << " ";
        printInRange(node->right, lo, hi);
    }
}
void targetSumBST(Node *root, Node *node, int target)
{
    if (node == NULL)
        return;
    targetSumBST(root, node->left, target);
    int comp = target - node->data;
    if (node->data < comp)
    {
        if (findIn(root, comp) == true)
        {
            cout << node->data << " " << comp << endl;
        }
    }
    targetSumBST(root, node->right, target);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->right = new Node(75);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->right = new Node(87);

    // cout << sizeBST(root) << endl;
    // cout << sumBST(root) << endl;
    // cout << minBST(root) << endl;
    // cout << maxBST(root) << endl;
    // cout << boolalpha << findIn(root, 54) << endl;
    // addNodeBST(root, 100);
    // cout << boolalpha << findIn(root, 100) << endl;
    // removeNodeBST(root, 12);
    // cout << boolalpha << findIn(root, 12) << endl;
    // cout << lcaBST(root, 37, 62);
    // printInRange(root, 20, 60);
    targetSumBST(root, root, 100);
    return 0;
}
