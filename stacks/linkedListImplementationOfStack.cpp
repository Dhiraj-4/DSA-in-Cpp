#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val) {};
};

class Stack {
    Node* head = NULL;
    int sz = 0;
public: 

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        sz++;
    }
   
    int top() {
        if(head == NULL) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        return head->val;
    }

    void pop() {
        if(head == NULL) {
            cout<<"Stack underflow"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        sz--;
    }

    int size() {
        return sz;
    }

};

int main() {
    Stack st;

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
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
}