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
void deletionBydata(int d)
{
    Node *current = head;
    if (current->data == d)
    {
        head = current->next;
        delete current;
    }
    else
    {
        while (current != nullptr)
        {
            Node *temp = current->next;
            if (temp->data == d)
            {
                current->next = temp->next;
                delete temp;
                break;
            }
            current = current->next;
        }
    }
    if (current->next == nullptr)
        tail = current;
}
void deletion(int n)
{
    Node *current = head;

    for (int i = 1; i < n - 1; i++)
    {
        if (current == nullptr)
        {
            cout << "No such index\n";
            return;
        }
        current = current->next;
    }
    if (n == 1)
    {
        head = current->next;
        delete current;
    }
    else
    {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    if (current->next == nullptr)
        tail = current;
}
int main()
{
    head = tail;
    Node *first = new Node(1);
    head = first;
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Linked List: ";
    displayLinkedList();
    deletionBydata(2);
    displayLinkedList();
    cout << head->data << " " << tail->data;

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}