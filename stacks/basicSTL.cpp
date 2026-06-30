#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    stack<int> st;

    cout<<st.size()<<endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.size()<<endl;
    stack<int> store;
    while(st.size() != 0) {
        store.push(st.top());
        st.pop();
    }
    cout<<endl;

    while (store.size() > 0) {   
        int val = store.top();
        cout<<val<<" ";
        store.pop();
        st.push(val);
    }

    cout<<endl<<st.size()<<endl;

    while(st.size() != 0) {
        cout<<st.top()<<" ";
        store.push(st.top());
        st.pop();
    }
    
}