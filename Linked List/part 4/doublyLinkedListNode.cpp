#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int val) : val(val) {};

    Node(int val, Node* next) : val(val), next(next) {};

    Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {};
};

int main() {
    Node* head = new Node(0);

    cout<<head->val<<endl;
}