#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int dd):data(dd),right(nullptr),left(nullptr){}
};
void postorder(Node *root)
{
    if(root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
    return;
}
int main()
{
    Node *p = new Node(2);
    Node *p1 = new Node(1);
    Node *p2 = new Node(4);
    Node *p3 = new Node(11);
    Node *p4 = new Node(7);

    p->left = p1;
    p->right = p2;
    p1->left =p3;
    p1->right=p4;

    postorder(p);

}