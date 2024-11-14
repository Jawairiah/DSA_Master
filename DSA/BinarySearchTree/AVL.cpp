#include <iostream>
using namespace std;

// AVL Tree Node
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Function to get the height of the tree
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
Node *findMinNode(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Utility function to get the balance factor of a node
int getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to create a new node
Node *createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // new node is initially at leaf
    return node;
}

// Right rotate subtree rooted with y (for Left-Left imbalance)
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x (for Right-Right imbalance)
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert function to insert a node and balance the AVL tree
Node *insert(Node *node, int key)
{
    // Step 1: Perform normal BST insertion
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Equal keys are not allowed in AVL tree

    // Step 2: Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Step 3: Get the balance factor of this ancestor node to check for imbalance
    int balance = getBalance(node);

    // Case 1: Left-Left (Zig-Zig) case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2: Right-Right (Zig-Zig) case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3: Left-Right (Zig-Zag) case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right-Left (Zig-Zag) case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Utility function to print pre-order traversal of the tree
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Utility function to find the node with the minimum key value
Node *minValueNode(Node *node)
{
    Node *current = node;

    // Loop to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Delete a node from the AVL tree
Node *deleteNode(Node *root, int key)
{
    // Step 1: Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp; // One child case

            delete temp;
        }
        else
        {
            // Node with two children
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (root == nullptr)
        return root;

    // Step 2: Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get the balance factor to check whether the node is unbalanced
    int balance = getBalance(root);

    // Case 1: Left-Left case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);


 // Case 3: Right-Right case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
        
    // Case 2: Left-Right case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

   

    // Case 4: Right-Left case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Main program to test AVL tree operations
int main()
{
    Node *root = nullptr;

    // Inserting nodes to trigger all cases
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Right-Right (Zig-Zig) case
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Right-Left (Zig-Zag) case

    // Pre-order traversal of the tree
    cout << "Pre-order traversal of the AVL tree is: ";
    preOrder(root);
    cout << endl;

    // Deleting a node and balancing the AVL tree
    root = deleteNode(root, 50);
    cout << "Pre-order traversal after deleting 50: ";
    preOrder(root);
    cout << endl;
    
    
    return 0;
}
