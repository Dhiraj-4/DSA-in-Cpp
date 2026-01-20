#include<iostream>
using namespace std;
int main() {
    string str = "Dark Shader";
    cout<<str<<endl;
    str[0] = 'd'; // strings are mutable in c++
    str[5] = 's';
    cout<<str<<endl; 
}