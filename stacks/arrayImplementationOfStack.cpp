#include<iostream>
using namespace std;

class stack {

    int arr[8];
    int idx = -1;
public:

    void push(int val) {
        if(idx == 7) {
            cout<<"Stack overflow"<<endl;
            return;
        }

        arr[++idx] = val;
    }

    void pop() {
        if(idx == -1) {
            cout<<"Stack underflow"<<endl;
            return;
        }

        idx--;
    }

    int top() {
        if(idx == -1) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        return arr[idx];
    }

    int size() {
        return idx + 1;
    }


};

int main() {
    stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<st.size()<<endl;
}