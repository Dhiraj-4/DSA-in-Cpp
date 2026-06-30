#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next = NULL;
    Node(int val) : val(val) {};
};

class Queue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }

        sz++;
    }

    void pop() {
        if(sz == 0) return;

        Node* temp = head;

        if(head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
        }
        delete temp;
        sz--;
    }

    int front() {
        if(sz == 0) {
            cout<<"Queue is empty!!";
            return -1;
        }

        return head->val;
    }

    int back() {
        if(sz == 0) {
            cout<<"Queue is empty!!";
            return -1;
        }

        return tail->val;
    }

    int size() {
        return sz;
    }

    void display() {
        Node* temp = head;

        while(temp) {
            cout<<temp->val<<endl;
            temp = temp->next;
        }
    }
};

int main() {
    
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    q.display();

    cout<<endl;
    q.display();

    cout<<endl;

    cout<<q.front()<<endl;

    q.pop();
    cout<<endl;

    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    
}