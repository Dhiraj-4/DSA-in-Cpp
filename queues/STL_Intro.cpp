#include<iostream>
#include<queue>
using namespace std;

 int main() {
    queue<int> q;

    q.push(5);
    cout<<q.size()<<endl;
    q.push(9);
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    q.push(8);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

 }