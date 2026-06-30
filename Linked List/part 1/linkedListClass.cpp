#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }

    // void setNext(Node* next) {
    //     this->next = next;
    // }

    // void setVal(int val) {
    //     this->val = val;
    // }

    // int getVal() {
    //     return this->val;
    // }

    // Node* getNext() {
    //     return this->next;
    // }
};

class LinkedList {

public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void add(int val) {
        if(head == NULL) {
            head = new Node(val);
            tail = head;
        }else {
            Node* node = new Node(val);
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;

        if(tail == NULL) tail = node;
        sz++;
    }

    int size() {
        return sz;
    }

    Node* getIthNode(int idx) {
        int cnt = -1;

        Node* temp = head;

        while(temp != NULL) {
            cnt++;
            if(cnt == idx) return temp;
            temp = temp->next;
        }

        return temp;
    }

    void deleteAt(int idx) {
        if(head == NULL) return;
        if(sz <= idx) return;
        if(idx < 0) return;

        if(idx == 0) {
            Node* node = head->next;

            if(head == tail) tail = NULL;
            delete head;
            head = node;
        }
        else if(idx > 0) {
            Node* node = getIthNode(idx-1);
            if(node == NULL) return;
            if(node->next == NULL) return;

            Node* delNode = node->next;

            node->next = node->next->next;

            if(delNode == tail) {
                tail = node;
            }

            delete delNode;
        }
        sz--;
    }

    void inserAt(int idx, int val) {
        if(idx < 0) return;

        if(idx > sz) return;
        
        if(idx == sz) {
            Node* newNode = new Node(val);

            if(tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            sz++;
            return;
        }

        if(head == NULL) {
            head = new Node(val);
            tail = head;
            sz++;
            return;
        }

        if(idx == 0) {
            Node* node = new Node(val);

            node->next = head;
            head = node;

            if(tail == NULL) tail = node;
            sz++;
            return;
        }
        else if(idx > 0) {
            Node* node = getIthNode(idx-1);

            Node* newNode = new Node(val);

            newNode->next = node->next;

            node->next = newNode;
            sz++;
        }
    }

    void display() {
        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }

        cout<<endl;
        return;
    }

    ~LinkedList() {
        Node* temp = head;
        while(temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList ll;

    ll.add(3);

    ll.addAtHead(1);

    ll.inserAt(1,2);

    ll.display();

    ll.deleteAt(0);
    ll.deleteAt(0);
    ll.deleteAt(0);

    ll.display();
    cout<<"after deletion"<<endl;
}
