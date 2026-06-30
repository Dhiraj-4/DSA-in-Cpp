#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev = NULL;
    Node* next = NULL;
    Node(int val) : val(val) {};
};

class Deque {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(sz == 0) {
            head = tail = newNode;
        }else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        sz++;
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);

        if(sz == 0) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sz++;
    }

    void pop_front() {
        if(sz == 0) return;

        Node* temp = head;
        if(sz == 1) head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        
        delete temp;
        sz--;
    }

    void pop_back() {
        if(sz == 0) return;

        Node* temp = tail;
        if(sz == 1) head = tail = NULL;
        else {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        delete temp;
        sz--;
    }

    int front() {
        if(sz == 0) return -1;
        return head->val;
    }

    int back() {
        if(sz == 0) return -1;
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
    Deque q;

    // Elements added to the back
    q.push_back(20);
    q.push_back(30);

    // Element sneaked into the front
    q.push_front(10);

    cout << "--- Initial Deque ---" << endl;
    q.display(); 

    cout << "\nFront element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Pop one from the front, one from the back
    q.pop_front(); // Removes 10
    q.pop_back();  // Removes 30

    cout << "\n--- After Popping Front & Back ---" << endl;
    q.display(); 

    cout << "\nRemaining Size: " << q.size() << endl;
    
    return 0;
}