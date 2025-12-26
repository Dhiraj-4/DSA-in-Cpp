#include<iostream>
using namespace std;
int main() {
    float x,y,z;
    cin>>x>>y>>z;

    if((x+y>z) && (x+z>y) && (z+y>x)) cout<<"It's a valid triangle"<<endl;
    else cout<<"It's not a valid triangle"<<endl;
}