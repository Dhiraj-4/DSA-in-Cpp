#include<iostream>
using namespace std;
int main() {
    int x;
    cin>>x;

    if(x % 5 == 0 || x % 3 == 0) cout<<"Divisible by 5 or 3"<<endl;
    else cout<<"No"<<endl;
}