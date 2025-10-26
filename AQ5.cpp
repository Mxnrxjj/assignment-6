#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if(head == nullptr)
        return true; 

    Node* temp = head->next;

    while(temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    Node* n1 = new Node{2, nullptr};
    Node* n2 = new Node{4, nullptr};
    Node* n3 = new Node{6, nullptr};
    Node* n4 = new Node{7, nullptr};
    Node* n5 = new Node{5, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
	n4->next = n5;
	n5->next = n1;
	 

    if(isCircular(n1))
        cout<<"The linked list is circular.\n";
    else
        cout<<"The linked list is NOT circular.\n";

    
    Node* h1 = new Node{2, nullptr};
    Node* h2 = new Node{4, nullptr};
    Node* h3 = new Node{6, nullptr};
    Node* h4 = new Node{7, nullptr};
    Node* h5 = new Node{5, nullptr};

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h3->next = h5;
    h3->next = nullptr; 

    if(isCircular(h1))
        cout<<"The linked list is circular.\n";
    else
        cout<<"The linked list is NOT circular.\n";

    return 0;
}

