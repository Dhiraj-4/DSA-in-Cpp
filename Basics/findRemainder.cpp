#include<iostream>
using namespace std;

int main() {
    int a, b;

    cin>>a>>b;

    cout<<endl;

    int q = a/b;

    int remainder = a - (b*q);

    cout<<remainder<<endl;
}