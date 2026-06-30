#include<iostream>
#include<queue>
#include<stack>
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
        int n = q.size();

        for(int i = 1; i <= n; i++) {
            Node* temp = q.front(); q.pop();
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<endl;
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

void printLeftNodes(Node* root) {
    if(root == NULL) return;
    stack<Node*> st;

    st.push(root);

    while(st.size()) {
        Node* temp = st.top(); st.pop();
        if(temp->left == NULL && temp->right == NULL) return;
        cout<<temp->val<<" ";
        if(temp->left) st.push(temp->left);
        else if(temp->right) st.push(temp->right);
    }
}

void printLeafNodes(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        cout<<root->val<<" ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRightNodes(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    
    if(root->right) printRightNodes(root->right);
    else printRightNodes(root->left);
    
    cout<<root->val<<" ";
}

void treeBoundary(Node* root) {
    if(root == NULL) return;
    cout<<root->val<<" ";
    printLeftNodes(root->left);
    printLeafNodes(root);
    printRightNodes(root->right);
}

int main() {

    vector<int> arr = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,29,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};

    Node* root = generateBinaryTree(arr);
    levelOrderQueue(root);

    treeBoundary(root);
}