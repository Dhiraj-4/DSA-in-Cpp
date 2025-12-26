#include<iostream>
using namespace std;
int main() {
    int x;
    cout<<"Enter first number: ";
    cin>>x;
    int y;
    cout<<"Enter second number: ";
    cin>>y;
    int z;
    cout<<"Enter third number: ";
    cin>>z;

    if(x > y && x > z) cout<<"The largest of three is "<<x<<endl;
    else if(y > x && y > z) cout<<"The largest of three is "<<y<<endl;
    else if(z > y && z > x)cout<<"The largest of three is "<<z<<endl;
    else cout<<"All are equal"<<endl;
    
}