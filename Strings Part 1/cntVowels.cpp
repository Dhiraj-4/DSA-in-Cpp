#include<iostream>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int cnt = 0;

    for(int i = 0; str[i] != '\0'; i++) 
        if(str[i] == 'a' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'e')
            cnt++;

    
    cout<<"Output "<<cnt<<endl;
}