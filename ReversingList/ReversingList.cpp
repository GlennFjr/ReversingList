#include <iostream>

using namespace std;

struct Node {
    int number;
    Node* prev;
    Node* next;
    
    Node(int value){
        number = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Reverses list until prev != null
void reverseLinkedList(Node*& headPointer) {
    Node* current = headPointer;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        headPointer = current;
        current = current->prev;
    }
}

// Prints list before reversal
void printList(Node* headPointer) {
    while (headPointer != nullptr) {
        cout << headPointer->number << " ";
        headPointer = headPointer->next;
    }
    cout << endl;
}

int main() {
    int values[5];
    cout << "Provide 5 integers:" << endl;
    for (int x = 0; x < 5; x++) {
        cout << "Int " << x+1 << ": ";
        cin >> values[x];
    };
    
    // Creates the doubly linked list
    Node* headPointer = new Node(values[0]);
    headPointer->next = new Node(values[1]);
    headPointer->next->prev = headPointer;
    headPointer->next->next = new Node(values[2]);
    headPointer->next->next->prev = headPointer->next;
    headPointer->next->next->next = new Node(values[3]);
    headPointer->next->next->next->prev = headPointer->next->next;
    headPointer->next->next->next->next = new Node(values[4]);
    headPointer->next->next->next->next->prev = headPointer->next->next->next;

    cout << "List before reversal:" << endl;
    printList(headPointer);

    // Reversing the linked list
    reverseLinkedList(headPointer);
    cout << "List after reversal:" << endl;
    printList(headPointer);
}