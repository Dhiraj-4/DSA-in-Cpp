#include<iostream>
using namespace std;
int main() {
    char ch;
    cin>>ch;

    int ascii = (int)ch;

    if((ascii >= 65 && ascii <= 90) || (ascii <= 122 && ascii >= 97)) cout<<"It's an alphabet"<<endl;
    else cout<<"It's no an alphabet"<<endl;
}