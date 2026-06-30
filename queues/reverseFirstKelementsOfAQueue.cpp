#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse_k_elements(queue<int>& q, int k) {
    if(q.size() == 1) return;

    stack<int> st;

    int i = 0;

    while( i < k) {
        int x = q.front();
        q.pop();
        st.push(x);
        i++;
    }

    while(st.size()) {
        q.push(st.top());
        st.pop();
    }

    i = 0;

    while(i < q.size()-k) {
        int x = q.front();
        q.pop();
        q.push(x);
        i++;
    }
}
void display(queue<int>& q) {
    int n = q.size();

    while(n) {
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        q.push(x);
        n--;
    }

    cout<<endl;
}
int main() {
    int k = 4;

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    display(q);
    reverse_k_elements(q, k);
    display(q);
}