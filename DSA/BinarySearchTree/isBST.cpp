#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;                                                    
    Node(int dd):data(dd),right(nullptr),left(nullptr){}
};
int isBST(Node* root){
    static Node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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

    cout<<isBST(p);
                                
    
}