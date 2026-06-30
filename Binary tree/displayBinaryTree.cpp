#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) : val(val) {};
};

void display(Node* root) {
    if(root == NULL) return;

    cout<<root->val<<endl;

    display(root->left);
    display(root->right);
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* g = new Node(6);
    Node* h = new Node(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = g;
    c->right = h;

    display(a);
}