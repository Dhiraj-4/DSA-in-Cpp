#include<iostream>
#include<vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {

public:
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int sz = 0;

    void add(int val) {
        if(head == NULL) {
            head = new ListNode(val);
            tail = head;
        }else {
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;

        if(tail == NULL) tail = node;
        sz++;
    }

    int size() {
        return sz;
    }

    ListNode* getIthNode(int idx) {
        int cnt = -1;

        ListNode* temp = head;

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
            ListNode* node = head->next;

            if(head == tail) tail = NULL;
            delete head;
            head = node;
        }
        else if(idx > 0) {
            ListNode* node = getIthNode(idx-1);
            if(node == NULL) return;
            if(node->next == NULL) return;

            ListNode* delNode = node->next;

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
            ListNode* newNode = new ListNode(val);

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
            head = new ListNode(val);
            tail = head;
            sz++;
            return;
        }

        if(idx == 0) {
            ListNode* node = new ListNode(val);

            node->next = head;
            head = node;

            if(tail == NULL) tail = node;
            sz++;
            return;
        }
        else if(idx > 0) {
            ListNode* node = getIthNode(idx-1);

            ListNode* newNode = new ListNode(val);

            newNode->next = node->next;

            node->next = newNode;
            sz++;
        }
    }

    void display() {
        ListNode* temp = head;

        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }

        cout<<endl;
        return;
    }

    ~LinkedList() {
        ListNode* temp = head;
        while(temp != NULL) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return vector<int>{-1, -1};
        vector<int> v(2, -1);

        ListNode* temp = head->next;
        ListNode* prev = head;

        int minMax = -1, maxMax = -1;
        int minMin = -1, maxMin = -1;
        int len = 2;

        while(temp->next) {
            if(
                (prev->val < temp->val && temp->val > temp->next->val)
                ||
                (prev->val > temp->val && temp->val < temp->next->val)
            ) {
                cout<<"idx = "<<len<<endl;

                if(minMax == -1) minMax = len;
                else maxMax = len;
                
                if(minMin == -1 && maxMin == -1) minMin = len;
                else if(minMin != -1 && maxMin == -1) maxMin = len;
                else if(maxMin - minMin > len - maxMin) {
                    minMin = maxMin;
                    maxMin = len;
                }
                
            }
            len++;
            prev = temp;
            temp = temp->next;
        }

        if(minMin == -1 || maxMin == -1 || maxMax == -1 || minMax == -1) return vector<int>{-1, -1};

        cout<<"minMin = "<<minMin<<endl;
        cout<<"maxMin = "<<maxMin<<endl;
        cout<<"minMax = "<<minMax<<endl;
        cout<<"maxMax = "<<maxMax<<endl;

        v[0] = maxMin - minMin;
        v[1] = maxMax - minMax;

        return v;
    }
int main() {
    LinkedList ll;

    vector<int> v = {43,69,47,14,12,80,96,55,47,7,45,75,8,51,82,35,33,27,38,27,60,85,39,57,100,57,41,87,8,20,75,62,1,4,55,59,67,57,79,33,38,14,39,16,22,55,44,64,55,31,65,73,66,34,41,72,3,78,87,49,77,76};
    
    for(int val : v) ll.add(val);

    ll.display();


    v = nodesBetweenCriticalPoints(ll.head);

    for(int val : v) cout<<val<<" ";
    // [5,3,1,9,5,6,287,5,1,2]
    //      c c c    c    c
    //  1 2 3 4 5 6  7  8 9 10
}
