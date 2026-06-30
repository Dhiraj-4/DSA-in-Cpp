#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* next = NULL;
    Node* random = NULL;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
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

Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        Node* dummy = new Node(0);
        Node* d = dummy;
        Node* temp = head;

        // create copy list without random pointer
        while(temp) {
            Node* newNode = new Node(temp->val);
            d->next = newNode;

            d = d->next;
            temp = temp->next;
        }

        cout<<"original list 1"<<endl;
        temp = head;
        while(temp) {
            int val = (temp->random) ? temp->random->val : -1;
            cout<<temp->val<<","<<val<<endl;
            temp = temp->next;
        }

        d = dummy;
        Node* a = dummy->next;
        temp = head;

        // create alternate connections(merge);
        while(a) {
            d->next = temp;
            d = d->next;
            temp = temp->next;

            d->next = a;
            d = d->next;
            a = a->next;
        }
        cout<<"Lists after merge into 1"<<endl;
        temp = dummy->next;
        while(temp) {
            int val = (temp->random) ? temp->random->val : -1;
            cout<<temp->val<<","<<val<<endl;
            temp = temp->next;
        }

        temp = dummy->next;
        int i = 0;
        // connect the random pointers
        while(temp) {
            // [7,NULL], [7,NULL], [13,0], [13,NULL]
            if(i % 2 == 0) 
            temp->next->random = (temp->random) ? temp->random->next : NULL;

            i++;
            temp = temp->next;
        }

        i = 0;

        Node* dummy2 = new Node(0);
        Node* d2 = dummy2;
        d = dummy;
        temp = dummy->next;
        // separate our result list
        while(temp) {
            if(i % 2) {
                d->next = temp;
                d = d->next;
            }else {
                d2->next = temp;
                d2 = d2->next;
            }
            i++;
            temp = temp->next;
        }
        d2->next = NULL;
        d->next = NULL;
        return dummy->next;
    }
int main() {

    // [[7,null],[13,0],[11,4],[10,2],[1,0]]

    LinkedList l1;

    l1.add(7);
    l1.add(13);
    l1.add(11);
    l1.add(10);
    l1.add(1);

    l1.getIthNode(0)->random = NULL;
    l1.getIthNode(1)->random = l1.getIthNode(0);
    l1.getIthNode(2)->random = l1.getIthNode(4);
    l1.getIthNode(3)->random = l1.getIthNode(2);
    l1.getIthNode(4)->random = l1.getIthNode(0);
    
    Node* head = copyRandomList(l1.head);

    Node* temp = head;

    cout<<"deep copy list"<<endl;
    while(temp) {
        int val = (temp->random) ? temp->random->val : -1;
        cout<<temp->val<<","<<val<<endl;
        temp = temp->next;
    }

    cout<<"original list list"<<endl;
    temp = l1.head;
    while(temp) {
        int val = (temp->random) ? temp->random->val : -1;
        cout<<temp->val<<","<<val<<endl;
        temp = temp->next;
    }
}