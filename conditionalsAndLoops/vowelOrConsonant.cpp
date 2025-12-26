#include<iostream>
using namespace std;
int main() {
    char ch;
    cin>>ch;

    int ascii = (int)ch;

    if((ascii >= 65 && ascii <= 90) || (ascii <= 122 && ascii >= 97)) {
        if(ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e' ||
        ch == 'A' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'E') {
            cout<<"Is a vowel"<<endl; 
        }else cout<<"Is a consonant"<<endl;
    }
    else cout<<"It's no an alphabet"<<endl;
}