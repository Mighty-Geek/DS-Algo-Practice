#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *right, *left;
    node(int d)
    {
        data = d;
        right = left = NULL;
    }
};

void showq(queue<node *> gq)
{
    queue<node *> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front()->data;
        g.pop();
    }
    cout << '\n';
}

void printLeft(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
            // showq(q);
        }
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->right = new node(15);
    root->right->left = new node(12);
    root->right->right->left = new node(14);
    root->right->right->right = new node(32);

    printLeft(root);

    return 0;
}
