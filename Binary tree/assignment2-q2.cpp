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


bool exists(Node* root, int key) {
    if(root == NULL) return false;

    if(root->val == key) return true;
    else if(root->val > key) return exists(root->left, key);
    return exists(root->right, key);
}

Node* closestAncestor(Node* root, int key1, int key2) {
    if(root == NULL) return NULL;

    if(root->val > key1 && root->val > key2) return closestAncestor(root->left, key1, key2);
    if(root->val < key1 && root->val < key2) return closestAncestor(root->right, key1, key2);
    return root;
}

int find(Node* root, int key) {
    if(root == NULL) return 0;

    if(root->val == key) {
        return 0;
    }
    else if(root->val > key) return 1 + find(root->left, key);
    return 1 + find(root->right, key);

}
int q2(Node* root, int key1, int key2) {
    if(root == NULL) return 0;

    if(root->val > key1 && root->val > key2) return q2(root->left, key1, key2);
    if(root->val < key1 && root->val < key2) return q2(root->right, key1, key2);

    return find(root, key1) + find(root, key2);
}

int main() {

    // vector<int> arr = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    vector<int> arr = {3, 1, 5, 0, 2, 4, 6};

    Node* root = generateBinaryTree(arr);
    int key1 = 0;
    int key2 = 5;
    // std::cout<<closestAncestor(root, key1, key2)->val;
    std::cout<<q2(root, key1, key2);
}