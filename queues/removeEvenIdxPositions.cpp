#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int>& q) {
    int sz = q.size();

    while(sz) {
        int x = q.front();
        cout<<x<<" "<<endl;
        q.push(x);
        q.pop();
        sz--;
    }
}
void removeEvenPositions(queue<int>& q) {
    int n = q.size()-1;

    while(n >= 0) {
        int x = q.front();
        q.pop();
        if(n % 2) q.push(x);
        n--;
    }
}
 int main() {
    queue<int> q;

    q.push(10);   // 0
    q.push(20); // 1
    q.push(30);   // 2
    q.push(40); // 3
    q.push(50);   // 4

    display(q);
    removeEvenPositions(q);
    cout<<endl;
    display(q);

 }