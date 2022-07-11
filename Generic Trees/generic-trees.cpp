#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> child;
};

class Pair
{
public:
    Node *node;
    int level;

    Pair(Node *n, int l)
    {
        node = n;
        level = l;
    }
};

class Pair2
{
public:
    Node *node;
    int state;
    Pair2(Node *n, int s)
    {
        node = n;
        state = s;
    }
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

void display(Node *node)
{
    string str = to_string(node->data) + " ->";
    for (Node *c : node->child)
    {
        str += to_string(c->data) + ",";
    }
    str += ".";
    cout << str << endl;
    for (Node *c : node->child)
    {
        display(c);
    }
}

int treeSize(Node *root)
{
    int size = 0;
    for (Node *c : root->child)
    {
        int add = treeSize(c);
        size += add;
    }
    size += 1;
    return size;
}

int maxNode(Node *root)
{
    int mx = INT_MIN;
    for (Node *c : root->child)
    {
        int cm = maxNode(c);
        mx = max(cm, mx);
    }
    mx = max(root->data, mx);
    return mx;
}

int treeHeight(Node *root)
{
    int ht = -1;
    for (Node *c : root->child)
    {
        int ch = treeHeight(c);
        ht = max(ht, ch);
    }
    ht += 1;
    return ht;
}

void traversals(Node *node)
{
    // pre
    cout << "Node Pre " << node->data << endl;
    for (Node *c : node->child)
    {
        cout << "Edge Pre " << node->data << "--" << c->data << endl;
        traversals(c);
        cout << "Edge Post " << node->data << "--" << c->data << endl;
    }
    // post
    cout << "Node Post " << node->data << endl;
}

void levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        node = q.front();
        q.pop();
        cout << node->data << " ";

        for (Node *c : node->child)
        {
            q.push(c);
        }
    }
    cout << "." << endl;
}

void levelOrderLinewise(Node *node)
{
    queue<Node *> q;
    queue<Node *> cq;
    q.push(node);
    while (q.size() > 0)
    {
        node = q.front();
        q.pop();
        cout << node->data << " ";

        for (Node *c : node->child)
        {
            cq.push(c);
        }
        if (q.size() == 0)
        {
            q = cq;
            cq = queue<Node *>();
            cout << endl;
        }
    }
}

void levelOrderLinewiseZigzag(Node *node)
{
    stack<Node *> s;
    stack<Node *> cs;
    s.push(node);
    int level = 1;
    while (s.size() > 0)
    {
        node = s.top();
        s.pop();
        cout << node->data << " ";

        if (level % 2 == 1)
        {
            for (int i = 0; i < node->child.size(); i++)
            {
                Node *c = node->child[i];
                cs.push(c);
            }
        }
        else
        {
            for (int i = node->child.size() - 1; i >= 0; i--)
            {
                Node *c = node->child[i];
                cs.push(c);
            }
        }
        if (s.size() == 0)
        {
            s = cs;
            cs = stack<Node *>();
            level++;
            cout << endl;
        }
    }
}

void levelOrder2(Node *node)
{
    queue<Node *> q;
    q.push(node);
    q.push(NULL);

    while (q.size() > 0)
    {
        node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            for (Node *c : node->child)
            {
                q.push(c);
            }
        }
        else
        {
            if (q.size() > 0)
            {
                q.push(NULL);
                cout << endl;
            }
        }
    }
}

void levelOrder3(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            node = q.front();
            q.pop();
            cout << node->data << " ";

            for (Node *c : node->child)
            {
                q.push(c);
            }
        }
        cout << endl;
    }
}

void levelOrder4(Node *node)
{
    queue<Pair *> q;
    q.push(new Pair(node, 1));

    int level = 1;
    while (q.size() > 0)
    {
        Pair *p = q.front();
        q.pop();
        if (p->level > level)
        {
            level = p->level;
            cout << endl;
        }
        cout << p->node->data << " ";
        for (Node *c : p->node->child)
        {
            Pair *cp = new Pair(c, p->level + 1);
            q.push(cp);
        }
    }
}

void mirror(Node *node)
{
    for (Node *c : node->child)
    {
        mirror(c);
    }
    reverse(node->child.begin(), node->child.end());
}

void removeLeaves(Node *node)
{
    for (int i = node->child.size() - 1; i >= 0; i--)
    {
        Node *c = node->child[i];
        if (c->child.size() == 0)
        {
            node->child.erase(remove(node->child.begin(), node->child.end(), c), node->child.end());
        }
    }
    for (Node *c : node->child)
    {
        removeLeaves(c);
    }
}

Node *getTail(Node *node)
{
    while (node->child.size() == 1)
    {
        node = node->child[0];
    }
    return node;
}

void linearize(Node *node)
{
    for (Node *c : node->child)
    {
        linearize(c);
    }
    while (node->child.size() > 1)
    {
        int pos = node->child.size() - 1;
        Node *last = node->child[pos];
        node->child.erase(remove(node->child.begin(), node->child.end(), last), node->child.end());
        Node *s_last = node->child[pos - 1];
        Node *s_last_tail = getTail(s_last);
        s_last_tail->child.push_back(last);
    }
}

bool findElement(Node *root, int val)
{
    if (root->data == val)
    {
        return true;
    }
    for (Node *c : root->child)
    {
        bool fic = findElement(c, val);
        if (fic)
            return true;
    }
    return false;
}

vector<int> nodeToRoot(Node *root, int val)
{
    if (root->data == val)
    {
        vector<int> list;
        list.push_back(root->data);
        return list;
    }
    for (Node *c : root->child)
    {
        vector<int> pathTillChild = nodeToRoot(c, val);
        if (pathTillChild.size() > 0)
        {
            pathTillChild.push_back(root->data);
            return pathTillChild;
        }
    }
    return {};
}

int lowestCommonAncestor(Node *root, int val1, int val2)
{
    vector<int> path1 = nodeToRoot(root, val1);
    vector<int> path2 = nodeToRoot(root, val2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while (i >= 0 && j >= 0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return path1[i];
}

int distanceBetweenNodes(Node *root, int val1, int val2)
{
    vector<int> path1 = nodeToRoot(root, val1);
    vector<int> path2 = nodeToRoot(root, val2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while (i >= 0 && j >= 0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return i + j;
}

bool areSimilar(Node *n1, Node *n2)
{
    if (n1->child.size() != n2->child.size())
    {
        return false;
    }
    for (int i = 0; i < n1->child.size(); i++)
    {
        Node *c1 = n1->child[i];
        Node *c2 = n2->child[i];
        if (areSimilar(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}

bool areMirror(Node *n1, Node *n2)
{
    if (n1->child.size() != n2->child.size())
    {
        return false;
    }
    for (int i = 0; i < n1->child.size(); i++)
    {
        int j = n1->child.size() - 1 - i;
        Node *c1 = n1->child[i];
        Node *c2 = n2->child[j];
        if (areMirror(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}

bool isSymmetric(Node *root)
{
    return areMirror(root, root);
}

Node *predecessor = NULL;
Node *successor = NULL;
int state = 0;
void predecessorSuccesor(Node *root, int val)
{
    if (state == 0)
    {
        if (root->data == val)
        {
            state = 1;
        }
        else
        {
            predecessor = root;
        }
    }
    else if (state == 1)
    {
        successor = root;
        state = 2;
    }

    for (Node *c : root->child)
    {
        predecessorSuccesor(c, val);
    }
}

int ceil_ = INT_MAX;
int floor_ = INT_MIN;
void ceilAndFloor(Node *node, int val)
{
    if (node->data > val)
    {
        if (node->data < ceil_)
        {
            ceil_ = node->data;
        }
    }
    if (node->data < val)
    {
        if (node->data > floor_)
        {
            floor_ = node->data;
        }
    }

    for (Node *c : node->child)
    {
        ceilAndFloor(c, val);
    }
}

int kthLargest(Node *root, int k)
{
    floor_ = INT_MIN;
    int factor = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        ceilAndFloor(root, factor);
        factor = floor_;
        floor_ = INT_MIN;
    }
    return factor;
}

int maxSumNode = 0;
int maxSum = INT_MIN;
int maxSubtreeSum(Node *node)
{
    int sum = 0;
    for (Node *c : node->child)
    {
        int csum = maxSubtreeSum(c);
        sum += csum;
    }
    sum += node->data;
    if (sum > maxSum)
    {
        maxSumNode = node->data;
        maxSum = sum;
    }
    return sum;
}

int d = 0;
int calculateDiameter(Node *node)
{
    int dch = -1;
    int sdch = -1;
    for (Node *c : node->child)
    {
        int ch = calculateDiameter(c);
        if (ch > dch)
        {
            sdch = dch;
            dch = ch;
        }
        else if (ch > sdch)
        {
            sdch = ch;
        }
    }
    if (dch + sdch + 2 > d)
    {
        d = dch + sdch + 2;
    }
    dch += 1;
    return dch;
}

void iterativePrePost(Node *node)
{
    stack<Pair2 *> st;
    st.push(new Pair2(node, -1));

    string pre = "";
    string post = "";

    while (st.size() > 0)
    {
        Pair2 *top = st.top();

        if (top->state == -1)
        {
            pre += to_string(top->node->data) + " ";
            top->state++;
        }
        else if (top->state == top->node->child.size())
        {
            post += to_string(top->node->data) + " ";
            st.pop();
        }
        else
        {
            Pair2 *cp = new Pair2(top->node->child[top->state], -1);
            st.push(cp);
            top->state++;
        }
    }
    cout << pre << endl;
    cout << post << endl;
}

int main()
{
    Node *root = newNode(10);
    (root->child).push_back(newNode(20));
    (root->child).push_back(newNode(30));
    (root->child).push_back(newNode(40));
    (root->child[0]->child).push_back(newNode(50));
    (root->child[0]->child).push_back(newNode(60));
    (root->child[1]->child).push_back(newNode(70));
    (root->child[1]->child).push_back(newNode(80));
    (root->child[1]->child).push_back(newNode(90));
    (root->child[2]->child).push_back(newNode(100));
    ((root->child[1])->child[1]->child).push_back(newNode(110));
    ((root->child[1])->child[1]->child).push_back(newNode(120));

    // display(root);
    // cout << treeSize(root);
    // cout << maxNode(root);
    // cout << treeHeight(root);
    // traversals(root);
    // levelOrder(root);
    // levelOrderLinewise(root);
    // levelOrderLinewiseZigzag(root);
    // levelOrder2(root);
    // levelOrder3(root);
    // levelOrder4(root);
    // mirror(root);
    // removeLeaves(root);
    // linearize(root);
    // cout << boolalpha << findElement(root, 120) << endl;
    // cout << boolalpha << findElement(root, 12) << endl;
    // vector<int> path = nodeToRoot(root, 120);
    // for (int pt : path)
    //     cout << pt << " ";
    // cout << lowestCommonAncestor(root, 110, 120);
    // cout << distanceBetweenNodes(root, 100, 50);
    // cout << boolalpha << areSimilar(root->child[0], root->child[1]->child[1]);
    // cout << boolalpha << isSymmetric(root);
    // predecessorSuccesor(root, 120);
    // int pre = (predecessor != NULL) ? predecessor->data : 0;
    // int suc = (successor != NULL) ? successor->data : 0;
    // cout << pre << " " << suc;
    // ceilAndFloor(root, 60);
    // cout << ceil_ << " " << floor_;
    // cout << kthLargest(root, 5);
    // maxSubtreeSum(root);
    // cout << maxSumNode << " " << maxSum;
    // calculateDiameter(root);
    // cout << d;
    iterativePrePost(root);

    return 0;
}
