#include <iostream>
#include <vector>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr),prev(nullptr) {}
};
void displayLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
void displaybackwardLinkedList(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->prev;
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
    second->prev = head;

    third->prev = second;

    // Displaying the linked list
    cout << "Linked List: ";
    displayLinkedList(head);

    cout << "\n\nLinked Backward List: ";
    displaybackwardLinkedList(third);

    // Clean up: free memory by deleting nodes (not necessary for demonstration purposes)
    delete head;
    delete second;
    delete third;

    return 0;
}