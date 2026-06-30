#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int val) : val(val) {};

    Node(int val, Node* next) : val(val), next(next) {};

    Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {};
};

class DLL {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        
        if(head) head->prev = newNode;
        head = newNode;
        if(size == 0) tail = head;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(size == 0) {
            head = tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }

    void addAt(int idx, int val) {
        if(idx < 0 || idx > size) return;
        
        if(idx == 0) addAtHead(val);
        else if(idx == size) addAtTail(val);
        else {
            Node* newNode = new Node(val);

            Node* temp = head;
            int len = 0;

            while(temp) {
                if(len == idx) {
                    temp->prev->next = newNode;
                    newNode->next = temp;
                    newNode->prev = temp->prev;
                    temp->prev = newNode;
                    size++;
                    return;
                }
                len++;
                temp = temp->next;
            }
        }
    }

    Node* getAt(int idx) {
        if(idx < 0 || idx >= size) return NULL;

        Node* temp = head;
        int len = 0;

        while(temp) {
            if(len == idx) return temp;
            len++;

            temp = temp->next;
        }

        return NULL;
    }

    void delAtHead() {
        if(size == 0) return;

        if(size == 1) {
            delete head;
            head = tail = NULL;
        }
        else {
            head->next->prev = NULL;
            Node* next = head->next;
            delete head;
            head = next;
        }
        size--;
    }

    void delAtTail() {
        if(size == 0) return;

        if(size == 1) {
            delete head;
            head = tail = NULL;
        }
        else {
            tail->prev->next = NULL;
            Node* temp = tail->prev;
            tail->prev = NULL;
            delete tail;
            tail = temp;
        }
        size--;
    }

    void delAt(int idx) {
        if(idx < 0 || idx >= size) return;

        if(idx == 0) delAtHead();
        else if(idx == size-1) delAtTail();
        else {
            Node* temp = head;
            int len = 0;

            while(temp) {
                if(len == idx) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    size--;
                    delete temp;
                    return;
                }
                len++;
                temp = temp->next;
            }
            
        }
    }

    ~DLL() {
        
        Node* next = head;

        while(head) {
            next = head->next;
            delete head;
            head = next;
        }
    }

    void display() {
        Node* temp = head;

        while(temp) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    DLL a;

    a.addAtTail(1);
    a.addAtTail(1);
    a.addAtTail(1);
    a.addAtTail(2);
    a.addAtTail(1);

    a.display();

    a.delAt(3);

    a.display();

    a.addAt(1,2);
    a.addAt(2,3);

    a.display();
    cout<<"--------------------------"<<endl;

    a.delAtTail();
    a.display();
    a.delAt(3);
    a.display();
    a.delAtTail();

    a.display();
}