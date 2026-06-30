#include<iostream>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) : val(val) {};
};

void preorder(Node* root) {
    if(root == NULL) return;

    cout<<root->val<<" "; // root

    preorder(root->left); // left
    preorder(root->right); // right
}

void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left); // left

    cout<<root->val<<" "; // root

    inorder(root->right); // right
}

void postorder(Node* root) {
    if(root == NULL) return;
    
    postorder(root->left); // left
    postorder(root->right); // right
    cout<<root->val<<" "; // root
}

void preoderTraversalItrative(Node* root) {
    stack<Node*> st;

    st.push(root);

    while(st.size() != 0) {
        Node* temp = st.top(); st.pop();

        cout<<temp->val<<" ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
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

    preorder(a);
    cout<<endl;
    preoderTraversalItrative(a);
    // inorder(a);
    // cout<<endl;
    // postorder(a);
}