#include<iostream>
using namespace std;

class Node {
public:
    Node* next = NULL;
    int val;

    Node(int val) {
        this->val = val;
    }
};

class LL {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    Node* getNodeIdx(int idx) {
        if(idx < 0 || idx >= size) return NULL;

        int cnt = -1;

        Node* temp = head;

        while(temp != NULL) {
            cnt++;
            if(cnt == idx) return temp;
            temp = temp->next;
        }

        return NULL;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);

        if(size == 0) {
            head = tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);

        if(size == 0) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val) {
        if(idx < 0 || idx > size) return;

        else if(idx == 0) insertAtHead(val);

        else if(idx == size) insertAtTail(val);

        else {
            Node* temp = getNodeIdx(idx-1);
            Node* newNode = new Node(val);

            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteAtHead() {
        if(size == 0) return;
        else if(size == 1) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
    }

    void deleteAtTail() {
        if(size == 0) return;
        else if(size == 1) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = getNodeIdx(size-2);
            Node* delNode = temp->next;
            temp->next = NULL;
            tail = temp;
            delete delNode;
        }
        size--;
    }

    void deleteAtIdx(int idx) {
        if(idx < 0 || idx >= size) return;
        else if(idx == 0) deleteAtHead();
        else if(idx == size-1) deleteAtTail();
        else {
            Node* temp = getNodeIdx(idx-1);
            Node* delNode = temp->next;

            temp->next = temp->next->next;
            delete delNode;
            size--;
        }
    }

    int get(int idx) {
        if(idx < 0 || idx >= size) return -1;
        else if(idx == 0) return head->val;
        else if(idx == size-1) return tail->val;
        else {
            Node* temp = getNodeIdx(idx);

            return temp->val;
        }
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LL list;

    list.insertAtHead(1);
    list.insertAtTail(3);
    list.insertAtIdx(1, 2);

    list.display();// 1 2 3
    list.deleteAtIdx(1);
    list.display();// 1 3
    list.deleteAtHead();
    list.display();// 3
}