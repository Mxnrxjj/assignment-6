#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getSize(Node* head) {
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    Node* n1 = new Node{10, nullptr};
    Node* n2 = new Node{20, nullptr};
    Node* n3 = new Node{30, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    Node* head = n1;

    cout<<"Size of Circular Linked List: "<<getSize(head)<<endl;

    return 0;
}

