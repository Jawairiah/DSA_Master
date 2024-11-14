#include <iostream>

using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Function to traverse and display the linked list
void displayLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating nodes for the linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Connecting the nodes to form the linked list
    head->next = second;
    second->next = third;

    // Displaying the linked list
    cout << "Linked List: ";
    displayLinkedList(head);

    // Clean up: free memory by deleting nodes (not necessary for demonstration purposes)
    delete head;
    delete second;
    delete third;

    return 0;
}
