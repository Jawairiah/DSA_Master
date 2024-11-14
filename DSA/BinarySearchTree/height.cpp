#include <iostream>
using namespace std;


// Define the structure of a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;


    // Constructor to initialize the node
    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};


// Function to calculate the height of a binary tree
int calculateHeight(TreeNode* node) {
    // Base case: If the node is NULL, the height is -1 (for an empty tree)
    if (node == nullptr)
        return -1;


    // Recursively calculate the height of the left and right subtrees
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);


    // The height of the tree is 1 + maximum of leftHeight and rightHeight
    return 1 + max(leftHeight, rightHeight);
}


int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);


    // Calculate the height of the tree
    cout << "Height of the tree: " << calculateHeight(root) << endl;


    return 0;
}
