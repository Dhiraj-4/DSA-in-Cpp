#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> st;

    cout<<st.size()<<endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<st.size()<<endl;

    stack<int> gt;

    while(st.size() != 0) {
        gt.push(st.top());
        st.pop();
    }
    cout<<endl;

    stack<int> rt;

    while(gt.size()) {
        rt.push(gt.top());
        gt.pop();
    }

    while(rt.size() != 0) {
        st.push(rt.top());
        rt.pop();
    }

    while(st.size() != 0) {
        cout<<st.top()<<" ";
        gt.push(st.top());
        st.pop();
    }
    cout<<endl;
    
}