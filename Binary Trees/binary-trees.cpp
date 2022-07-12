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
class Pair
{
public:
    Node *node;
    int state;
    Pair(Node *n, int s)
    {
        node = n;
        state = s;
    }
};
class D_Pair
{
public:
    int ht;
    int d;
};
class BST_Pair
{
public:
    bool isBST;
    int mn;
    int mx;
};
void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    string str = "";
    str += root->left == NULL ? "." : to_string(root->left->data) + "";
    str += "<-" + to_string(root->data) + "->";
    str += root->right == NULL ? "." : to_string(root->right->data) + "";

    cout << str << endl;

    display(root->left);
    display(root->right);
}
int sizeBT(Node *node)
{
    if (node == NULL)
        return 0;
    int ls = sizeBT(node->left);
    int rs = sizeBT(node->right);
    int total_s = ls + rs + 1;
    return total_s;
}
int sumBT(Node *node)
{
    if (node == NULL)
        return 0;
    int lsum = sumBT(node->left);
    int rsum = sumBT(node->right);
    int total_sum = lsum + rsum + node->data;
    return total_sum;
}
int heightBT(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int lh = heightBT(node->left);
    int rh = heightBT(node->right);
    int total_h = (lh > rh) ? lh : rh;
    return total_h + 1;
}
int maxBT(Node *node)
{
    if (node == NULL)
        return INT_MIN;
    int lmax = maxBT(node->left);
    int rmax = maxBT(node->right);
    int mx = lmax > rmax ? lmax : rmax;
    int ans = mx > node->data ? mx : node->data;
    return ans;
}
void preorderTraversal(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
void inorderTraversal(Node *node)
{
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}
void postorderTraversal(Node *node)
{
    if (node == NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}
void levelorderTraversal(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        cout << endl;
    }
}
void iterativeTraversals(Node *node)
{
    stack<Pair *> st;
    st.push(new Pair(node, 1));

    string pre = "";
    string in = "";
    string post = "";

    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            pre += to_string(top->node->data) + " ";
            top->state++;
            if (top->node->left != NULL)
            {
                Pair *lp = new Pair(top->node->left, 1);
                st.push(lp);
            }
        }
        else if (top->state == 2)
        {
            in += to_string(top->node->data) + " ";
            top->state++;
            if (top->node->right != NULL)
            {
                Pair *rp = new Pair(top->node->right, 1);
                st.push(rp);
            }
        }
        else
        {
            post += to_string(top->node->data) + " ";
            st.pop();
        }
    }

    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
}
vector<int> pathNodeToRoot;
bool findElement(Node *node, int val)
{
    if (node == NULL)
        return false;
    if (node->data == val)
    {
        pathNodeToRoot.push_back(node->data);
        return true;
    }
    bool filc = findElement(node->left, val);
    if (filc)
    {
        pathNodeToRoot.push_back(node->data);
        return true;
    }
    bool firc = findElement(node->right, val);
    if (firc)
    {
        pathNodeToRoot.push_back(node->data);
        return true;
    }

    return false;
}
void printKLevelsDown(Node *node, int k)
{
    if (node == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << node->data << " ";
    }
    printKLevelsDown(node->left, k - 1);
    printKLevelsDown(node->right, k - 1);
}
void rootToLeafPath(Node *node, string path, int sum, int lo, int hi)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        sum += node->data;
        if (sum >= lo && sum <= hi)
        {
            cout << path + to_string(node->data);
        }
        return;
    }
    rootToLeafPath(node->left, path + to_string(node->data) + " ", sum + node->data, lo, hi);
    rootToLeafPath(node->right, path + to_string(node->data) + " ", sum + node->data, lo, hi);
}

Node *createLeftCloned(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    Node *lcr = createLeftCloned(node->left);
    Node *rcr = createLeftCloned(node->right);

    node->right = rcr;
    node->left = new Node(node->data);
    node->left->left = lcr;
    return node;
}
Node *createTreeBackFromLeftCloned(Node *node)
{
    if (node == NULL)
        return NULL;

    Node *lnn = createTreeBackFromLeftCloned(node->left->left);
    Node *rnn = createTreeBackFromLeftCloned(node->right);

    node->left = lnn;
    node->right = rnn;

    return node;
}
void printSingleChildNodes(Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right != NULL)
    {
        cout << node->data << " ";
    }
    else if (node->left != NULL && node->right == NULL)
    {
        cout << node->data << " ";
    }
    printSingleChildNodes(node->left);
    printSingleChildNodes(node->right);
}
Node *removeLeaves(Node *node)
{

    if (node == NULL)
        return NULL;
    if (node->left == NULL && node->right == NULL)
    {
        return NULL;
    }
    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);
    return node;
}
int diameterBT(Node *node)
{
    if (node == NULL)
        return 0;
    int ld = diameterBT(node->left);
    int rd = diameterBT(node->right);

    int f = heightBT(node->left) + heightBT(node->right) + 2;
    int d = (ld > rd) ? ld : rd;
    int ans = (d > f) ? d : f;
    return ans;
}
// Use D_Pair to implement diameterBT such that T(n)=O(n);
int tilt = 0;
int tiltBT(Node *node)
{
    if (node == NULL)
        return 0;
    int lsum = tiltBT(node->left);
    int rsum = tiltBT(node->right);

    int curr_tilt = abs(lsum - rsum);
    tilt += curr_tilt;

    int tsum = lsum + rsum + node->data;
    return tsum;
}
BST_Pair *isTreeBST(Node *node)
{
    if (node == NULL)
    {
        BST_Pair *bp = new BST_Pair();
        bp->mn = INT_MAX;
        bp->mx = INT_MIN;
        bp->isBST = true;
        return bp;
    }
    BST_Pair *lp = isTreeBST(node->left);
    BST_Pair *rp = isTreeBST(node->right);

    BST_Pair *mp = new BST_Pair();
    mp->isBST = lp->isBST && rp->isBST && (node->data >= lp->mx && node->data <= rp->mn);
    mp->mn = (lp->mn < rp->mn) ? lp->mn : rp->mn;
    mp->mx = (lp->mx > rp->mx) ? lp->mx : rp->mx;

    return mp;
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

    // display(root);
    // cout << sizeBT(root) << endl;
    // cout << sumBT(root) << endl;
    // cout << maxBT(root) << endl;
    // cout << heightBT(root) << endl;
    // preorderTraversal(root);
    // inorderTraversal(root);
    // postorderTraversal(root);
    // levelorderTraversal(root);
    // iterativeTraversals(root);
    // findElement(root, 37);
    // for (int p : pathNodeToRoot)
    // {
    //     cout << p << " ";
    // }
    // printKLevelsDown(root, 2);
    // printSingleChildNodes(root);
    // tiltBT(root);
    // cout << tilt << endl;
    BST_Pair *bp = isTreeBST(root);
    cout << boolalpha << bp->isBST;
    return 0;
}
