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

        int size = q.size();
        for(int i = 0; i < size; i++) {
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


bool helper(Node* root, int& low, int& high, int& ans) {
    if(root == NULL) return true;

    bool left = helper(root->left, low, high, ans);
    bool right = helper(root->right, low, high, ans);

    if(left && right && (root->val >= low && root->val <= high)) {
        ans++;
        return true;
    }
    else return false;
}

int q1(Node* root, int low, int high) {
    int ans = 0;
    helper(root, low, high, ans);
    return ans;
}

int main() {

    // vector<int> arr = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    vector<int> arr = {40, 25, 50, 20, 30, 45, 60};

    Node* root = generateBinaryTree(arr);
    levelOrderQueue(root);
    int low = 15;
    int high = 47;
    std::cout<<q1(root, low, high);
}