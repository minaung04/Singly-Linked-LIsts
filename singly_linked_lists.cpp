//C++ singly linked list

#include <iostream>
using namespace std;

// creating node structure 
struct Node {
    int data;
    Node* next;
};

// inserting a node at a given index
int LinkedlistInsert(int data, int index, Node*& head) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    // head insertion
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return 0;
    }

    Node* temp = head;
    int count = 0;

    while (temp != nullptr && count < index - 1) {
        temp = temp->next;
        count++;
    }

    // If index is out of range
    if (temp == nullptr) {
        delete newNode;
        return -1;  // Failure
    }

    // inserting new node
    newNode->next = temp->next;
    temp->next = newNode;
    return 0;
}

// function to delete node
int LinkedlistDelete(int index, Node*& head) {
    if (head == nullptr) return 0;

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp;
        return 0;
    }

    Node* prev = nullptr;
    int count = 0;

    while (temp != nullptr && count < index) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return 0;

    // Removing the node
    prev->next = temp->next;
    delete temp;
    return 1;  // Success
}

// function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// function to test insert and delete operations
int main() {
    Node* head = nullptr; // empty list
    
    LinkedlistInsert(10, 0, head);
    LinkedlistInsert(20, 1, head);
    LinkedlistInsert(30, 2, head);
    LinkedlistInsert(15, 1, head);

    cout << "Linked List after insertions: ";
    display(head);  

    LinkedlistDelete(1, head);  
    cout << "Linked List after deleting index 1: ";
    display(head);  

    LinkedlistDelete(0, head);  
    cout << "Linked List after deleting head: ";
    display(head);  

    return 0;
}

