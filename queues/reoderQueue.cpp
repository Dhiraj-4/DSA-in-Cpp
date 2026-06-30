#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int>& q) {
    int sz = q.size();

    while(sz) {
        int x = q.front();
        cout<<x<<" ";
        q.push(x);
        q.pop();
        sz--;
    }
    cout<<endl;
}
void reoderQueue(queue<int>& q) {
    // 1 2 3 4 5 6 7 8
    stack<int> st;

    // 1) empty half queue in st
    int halfLen = q.size()/2;

    while(halfLen) {
        st.push(q.front());
        q.pop();
        halfLen--;
    }
    
    // 2) empty st in queue
    while(st.size()) {
        q.push(st.top());
        st.pop();
    }

    // 3) empty half queue in st
    halfLen = q.size()/2;

    while(halfLen) {
        st.push(q.front());
        q.pop();
        halfLen--;
    }
    
    // 4) merge st and queue
        // a) one from st
        // b) one from queue
        // c) repeat
    while(st.size()) {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

    // 5) reverse and return;
        // a) empty the queue in st
        // b) empty st in queue
    while(q.size()) {
        st.push(q.front());
        q.pop();
    }

    while(st.size()) {
        q.push(st.top());
        st.pop();
    }

    return;
    // 1 5 2 6 3 7 4 8
}
int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    display(q);
    reoderQueue(q);
    display(q);
}