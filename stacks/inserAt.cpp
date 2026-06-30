#include<iostream>
#include<stack>
using namespace std;

void insertAt(stack<int>& st, int val, int idx) {
    if(idx < 0 || idx > st.size()) return;

    stack<int> temp;
    int i = st.size();

    while(i != idx) {
        temp.push(st.top());
        st.pop();
        i--;
    }

    st.push(val);

    while(temp.size()) {
        st.push(temp.top());
        temp.pop();
    }
}

void print(stack<int> st) {
    while(st.size()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
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

   print(st);
   insertAt(st, 100, 0);
   print(st);
    
}