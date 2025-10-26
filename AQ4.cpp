#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

bool isPalindrome(Node* head) {
    if(head == nullptr) return true;

    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }

    while(head != tail && tail->next != head) {
        if(head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main() {
    Node* n1 = new Node{'L', nullptr, nullptr};
    Node* n2 = new Node{'E', nullptr, n1};
    Node* n3 = new Node{'V', nullptr, n2};
    Node* n4 = new Node{'E', nullptr, n3};
    Node* n5 = new Node{'L', nullptr, n4};
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Node* head = n1;

    if(isPalindrome(head))
        cout<<"The doubly linked list is palindrome."<<endl;
    else
        cout<<"The doubly linked list is NOT palindrome."<<endl;

    return 0;
}

