#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

int main() {
    Node* n1 = new Node(1);

    Node* n2 = new Node(2);
    n1->next = n2;

    Node* n3 = new Node(3);
    n2->next = n3;

    Node* n4 = new Node(4);
    n3->next = n4;

    Node* n5 = new Node(5);
    n4->next = n5;

    Node* n6 = new Node(6);
    n5->next = n6;

    int len = 0;

    Node* temp = n1;
    while(temp != NULL)  {
        len++;
        temp = temp->next;
    }

    cout<<len<<endl;

}