#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int>& st, int val) {
    if(st.size() == 0) {
        st.push(val);
        return;
    }

    int x = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(x);
}

void reverseStack(stack<int>& st) {
    if(st.size() <= 1) return;

    int x = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, x);
}

void print(stack<int>& st) {
    if(st.size() == 0) return;
    
    int x = st.top();
    st.pop();
    print(st);
    cout<<x<<" ";
    st.push(x);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    print(st);
    cout<<endl;
    reverseStack(st);
    print(st);
}