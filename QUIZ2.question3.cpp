#include <iostream>

using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(12);

    Node* reversedHead = reverseLinkedList(head);

    printList(reversedHead);

    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
