#include<iostream>
using namespace std;
int main() {
    char ch;
    cout<<"Enter a capital alphabet: ";
    cin>>ch;

    cout<<"The position of given alphabet is: "<<((int)ch - 64)<<endl;
}