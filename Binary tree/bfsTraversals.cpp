#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) : val(val) {};
};

int levels(Node* root) {
    if(root == NULL) return 0;

    return 1 + max(levels(root->left), levels(root->right));
}

void levelOrderQueue(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {
        Node* temp = q.front(); q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

        cout<<temp->val<<" ";
    }
}

Node* generateBinaryTree(vector<int>& arr) {
    queue<Node*> q;

    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1, j = 2;
    int n = arr.size();

    while(q.size() != 0 && i < n) {
        Node* temp = q.front(); q.pop();

        Node* l = NULL;
        Node* r = NULL;

        if(arr[i] != INT_MIN) {
            l = new Node(arr[i]);
            q.push(l);
        }

        if(j < n && arr[j] != INT_MIN) {
            r = new Node(arr[j]);
            q.push(r);
        }

        temp->left = l;
        temp->right = r;

        i += 2;
        j += 2;
    }

    return root;
}

int main() {

    vector<int> arr = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};

    Node* root = generateBinaryTree(arr);
    levelOrderQueue(root);
}