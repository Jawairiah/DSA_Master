#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int dd):data(dd),right(nullptr),left(nullptr){}
};
Node* Search(Node *root,int key)
{
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }

}
int main()
{
    Node *p = new Node(5);
    Node *p1 = new Node(3);
    Node *p2 = new Node(6);
    Node *p3 = new Node(1);
    Node *p4 = new Node(4);

     //      5
     //     / \
     //    3   6
     //   / \
     //  1   4                                 
    
    p->left = p1;
    p->right = p2;
    p1->left =p3;
    p1->right=p4;

    Node *n = Search(p,3);
    if(n!=nullptr){
        cout<<"Found "<<n->data;
    }
    else{
        cout<<"not found";
    }
                                
    
}