#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int d)
    {
        val = d;
        left = right = NULL;
    }
};
void dfs(TreeNode *root, string &s)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        s += to_string(root->val) + "#";

    dfs(root->left, s);
    dfs(root->right, s);
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    string t1, t2;
    t1 = t2 = "";
    dfs(root1, t1);
    dfs(root2, t2);

    return t1 == t2;
}
int main()
{
    // tree1
    TreeNode *root1 = new TreeNode(5);
    TreeNode *left1 = new TreeNode(6);
    TreeNode *right1 = new TreeNode(7);
    TreeNode *left11 = new TreeNode(1);
    TreeNode *right11 = new TreeNode(8);
    TreeNode *right12 = new TreeNode(4);
    TreeNode *right111 = new TreeNode(2);
    TreeNode *right112 = new TreeNode(3);

    root1->left = left1;
    root1->right = right1;
    left1->left = left11;
    right1->left = right11;
    right1->right = right12;
    right11->left = right111;
    right11->right = right112;

    // tree2
    TreeNode *root2 = new TreeNode(5);
    TreeNode *left2 = new TreeNode(6);
    TreeNode *right2 = new TreeNode(7);
    TreeNode *left21 = new TreeNode(1);
    TreeNode *left22 = new TreeNode(2);
    TreeNode *right21 = new TreeNode(3);
    TreeNode *right22 = new TreeNode(4);

    root2->left = left2;
    root2->right = right2;
    left2->left = left21;
    left2->right = left22;
    right2->left = right21;
    right2->right = right22;

    if (leafSimilar(root1, root2))
        cout << "Same!";
    else
        cout << "Different:(";

    return 0;
}