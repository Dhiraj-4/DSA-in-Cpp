// Q1 Remove the last k elements of a queue.
#include<iostream>
#include<queue>
using namespace std;

void removeLastK(queue<int>& q, int k) {
    // 1 2 3 4 k = 2
    // 1 2

    // n-k = 4-2 = 2
    // 3 4 1 2
    // 1 2

    int n = q.size();
    int cnt = n-k;

    while(cnt) {
        int x = q.front();
        q.pop();
        q.push(x);
        cnt--;
    }

    while(k) {
        q.pop();
        k--;
    }
}

void display(queue<int>& q) {
    int n = q.size();

    while(n) {
        cout<<q.front()<<" ";
        int x = q.front();
        q.pop();
        q.push(x);
        n--;
    }
    cout<<endl;
}

int main() {
    queue<int> q;
    int k = 5;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    display(q);
    removeLastK(q, k);
    display(q);
}