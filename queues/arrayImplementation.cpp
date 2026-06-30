#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class queue {
public: 
    vector<int> v;
    int frontIdx = 0;

    void push(int val) {
        v.push_back(val);
    }
    void pop() {
        if(v.size() - frontIdx <= 0) return;
        
        frontIdx++;
    }

    int front() {
        if(v.size() - frontIdx <= 0) return -1;
        return v[frontIdx];
    }

    int back() {
        if(v.size() - frontIdx <= 0) return -1;
        return v[v.size()-1];
    }

    int size() {
        return v.size() - frontIdx;
    }

};

void display(queue& q) {
    int sz = q.size();

    while(sz) {
        int x = q.front();
        cout<<x<<" "<<endl;
        q.push(x);
        q.pop();
        sz--;
    }
}

void removeEvenPositions(queue& q) {
    int n = q.size()-1;

    while(n >= 0) {
        int x = q.front();
        q.pop();
        if(n % 2) q.push(x);
        n--;
    }
}
void reverse(queue& q) {
    stack<int> st;

    while(q.size()) {
        st.push(q.front());
        q.pop();
    }

    while(st.size()) {
        q.push(st.top());
        st.pop();
    }
}
int main() {
    queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    display(q);
    removeEvenPositions(q);
    reverse(q);
    cout<<endl;
    display(q);

    cout<<endl;

    cout<<q.front()<<endl;

    q.pop();
    cout<<endl;

    cout<<q.front()<<endl;
    
}