#include<iostream>
#include<queue>
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
 int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    display(q);
    cout<<endl;
    display(q);

 }