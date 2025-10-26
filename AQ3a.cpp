#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int getSize(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* n1 = new Node{10, nullptr, nullptr};
    Node* n2 = new Node{20, nullptr, n1};
    Node* n3 = new Node{30, nullptr, n2};

    n1->next = n2;
    n2->next = n3;

    Node* head = n1;

    cout<<"Size of Doubly Linked List: "<<getSize(head)<<endl;

    return 0;
}

