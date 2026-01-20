#include<iostream>
using namespace std;
int main() {
    string str = "1234567890";
    int x = stoi(str); // this is to convert string to integer;
    cout<<x+1<<endl;

    str = "1234567890987654321";
    long long xLongLong = stoll(str);// this is to convert string to long long;
    cout<<xLongLong + 1<<endl;
}