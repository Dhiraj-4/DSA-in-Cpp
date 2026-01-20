#include<iostream>
using namespace std;
int main() {
    string str = "Dark Shader";
    cout<<str<<endl;

    string realName;
    getline(cin, realName);

    int age;
    cin>>age;

    cout<<realName<<" "<<age<<endl;
}