#include<iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    cout<<a%b<<endl;
    cout<<1%4<<endl;
    // cout<<1.0%23; this will throw error, float value are not allowed in modules

    cout<<10%(-3)<<endl; // same as a%b
    cout<<(-10) % 3<<endl; // -(a % b)
    cout<<(-10) % (-3) <<endl; // -(a % b);
}