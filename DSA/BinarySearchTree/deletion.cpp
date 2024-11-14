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
// Function to find the minimum value node

Node* findMin(Node *node)
{
    while (node!= nullptr && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Delete function
Node* deleteNode(Node *node, int value)
{
    if (node == nullptr)
    {
        return node;
    }

    if (value < node->data)
    {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deleteNode(node->right, value);
    }
    else
    {
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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
    preOrder(p);
    cout<<endl;
    deleteNode(p, 1);
    preOrder(p);
}