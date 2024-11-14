#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void preorder(TreeNode *root)
    {
        if (root != nullptr)
        {
            cout << root->val << endl;
            preorder(root->left);
            preorder(root->right);
        }
        return;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        static TreeNode *temp=root;
        if (root == nullptr)
        { 
            return temp;
        }
        TreeNode *n = root->right;
        root->right = root->left;
        root->left = n;
        invertTree(root->left);
        invertTree(root->right);
        return temp;
    }
};
int main()
{
    TreeNode *p = new TreeNode(8);
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(9);
    TreeNode *p3 = new TreeNode(1);
    TreeNode *p4 = new TreeNode(6);
    //     / \
     //    5   9
    //   / \
     //  1   6

    p->left = p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    TreeNode *q = new TreeNode(8);
    TreeNode *q1 = new TreeNode(5);

    //      8
    //     / \
     //    5   9
    //   / \
     //  1   6

    q->right = q1;
    Solution ss;
    ss.preorder(p);
    cout<<"inverted\n";
    ss.invertTree(p);
    ss.preorder(p);
}