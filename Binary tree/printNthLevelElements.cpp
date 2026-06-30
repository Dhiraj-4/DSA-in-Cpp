#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) : val(val) {};
};

void displayNthLevel(Node* root, int lvl) {
    if(root == NULL) return;

    if(lvl - 1 == 0) {
        cout<<root->val<<" ";
        return;
    }

    displayNthLevel(root->left, lvl-1);
    displayNthLevel(root->right, lvl-1);
}

void displayNthLevelRev(Node* root, int lvl) {
    if(root == NULL) return;

    if(lvl - 1 == 0) {
        cout<<root->val<<" ";
        return;
    }

    displayNthLevelRev(root->right, lvl-1);
    displayNthLevelRev(root->left, lvl-1);
}

int levels(Node* root) {
    if(root == NULL) return 0;

    return 1 + max(levels(root->left), levels(root->right));
}

void printLevels(Node* root) {
    int n = levels(root);

    for(int i = 1; i <= n; i++) {
        displayNthLevel(root, i);
        cout<<endl;
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

    int lvl = 1;

    printLevels(a);
}