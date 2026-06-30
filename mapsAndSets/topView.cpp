#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void topView(Node* root) {
    if(root == NULL) return;

    std::unordered_map<int, int> topNodeMap;


    std::queue<std::pair<Node*, int>> q;

    q.push({root, 0});

    while(q.size()) {
        auto p = q.front();
        q.pop();

        Node* cur = p.first;
        int lvl = p.second;

        if(topNodeMap.find(lvl) == topNodeMap.end()) {
            topNodeMap[lvl] = cur->val;
        }

        if(cur->left) q.push({cur->left, lvl-1});
        if(cur->right) q.push({cur->right, lvl+1});
    }

    int mn = INT_MAX;
    int mx = INT_MIN;

    for(auto ele : topNodeMap) {
        mn = std::min(mn, ele.first);
        mx = std::max(mx, ele.first);
    }

    for(int i = mn; i <= mx; i++) std::cout<<topNodeMap[i]<<" ";
    std::cout<<std::endl;
}

Node* generateBT(std::vector<int>& arr) {

    int n = arr.size();
    int i = 1, j = 2;
    std::queue<Node*> q;
    Node* root = new Node(arr[0]);
    if(root->val == INT_MIN) return NULL;

    q.push(root);
    while(i < n) {
        Node* temp = q.front(); q.pop();

        Node* left = NULL;
        Node* right = NULL;
        if(arr[i] != INT_MIN) left = new Node(arr[i]);
        if(j < n && arr[j] != INT_MIN) right = new Node(arr[j]);

        temp->left = left;
        temp->right = right;

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

        i += 2;
        j += 2;
    }

    return root;
}

void levelOrder(Node* root) {
    if(root == NULL) return;

    std::queue<Node*> q;

    q.push(root);

    while(q.size()) {
        int n = q.size();
        
        for(int i = 0; i < n; i++) {
            Node* temp = q.front(); q.pop();

            std::cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        std::cout<<"\n";
    }
}
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8}; 
    Node* root = generateBT(arr);

    levelOrder(root);

    std::cout<<"Top view : "<<std::endl;

    topView(root);
}