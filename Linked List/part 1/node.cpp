#include<iostream>
using namespace std;

class Node {
    public:

    int val;
    Node* prev = NULL;
    Node* next = NULL;

    Node(Node* prev, int val, Node* next) {
        this->prev = prev;
        this->val = val;
        this->next = next;
    }
};

int main() {
    Node* p1 = new Node(NULL, 1, NULL);

    Node* p2 = new Node(p1, 2, NULL);
    p1->next = p2;

    Node* p3 = new Node(p2, 3, NULL);
    p2->next = p3;

    cout<<p1->next->val<<endl;

    Node* temp = p1;

    while(temp != NULL) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}