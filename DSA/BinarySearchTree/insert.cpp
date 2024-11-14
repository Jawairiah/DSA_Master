#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int dd) : data(dd), right(nullptr), left(nullptr) {}
};
void insert(Node *root, int key)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    Node *n = new Node(key);
    if (key < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
    return;
}
int main()
{
    Node *p = new Node(8);
    Node *p1 = new Node(5);
    Node *p2 = new Node(9);
    Node *p3 = new Node(1);
    Node *p4 = new Node(6);

    //      8
    //     / \
     //    5   9
    //   / \
     //  1   6

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 7);
    inorder(p);
}