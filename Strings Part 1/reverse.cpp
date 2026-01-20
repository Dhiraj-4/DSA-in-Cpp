#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main() {
    string str = "Dark Shader";
    cout<<str<<endl;
    reverse(str.begin(), str.end()-7);
    cout<<str<<endl;
}