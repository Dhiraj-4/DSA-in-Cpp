#include<iostream>
using namespace std;

int main() {
    int x = 12345;
    string str = to_string(x).substr(1,3);
    cout<<str.substr(1);
}