#include<iostream>
using namespace std;

int main() {
    int x;
    cin>>x;

    if((x % 5 == 0 || x % 3 == 0) && x % 15 != 0) cout<<"We got hit"<<endl;
    else cout<<"This is not a hit"<<endl;
}