#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int dd):data(dd),right(nullptr),left(nullptr){}
};
int main()
{
    Node *p = new Node(2);
    Node *p1 = new Node(1);
    Node *p2 = new Node(4);

    p->left = p1;
    p->right = p2;
}