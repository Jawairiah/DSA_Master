#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
Node *head;
Node *tail;
void displayLinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        tail = current;
        current = current->next;
    }
    cout << "NULL" << endl;
}
void sort(){
    Node *current = head;
    while (current != nullptr)
    {
        Node* temp = current->next;
        while (temp != nullptr){
            if(current->data>temp->data){
                int t=temp->data;
                temp->data = current->data;
                current->data = t;
            }
            temp=temp->next;
        }
        current = current->next;
    }
}
int main()
{
    head = tail;
    Node *first = new Node(7);
    head = first;
    Node *second = new Node(5);
    Node *third = new Node(9);
    Node *fourth = new Node(3);

    head->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Linked List: ";
    sort();
    displayLinkedList();
    cout << head->data << " " << tail->data;

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}