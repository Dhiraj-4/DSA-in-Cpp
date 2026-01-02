#include<iostream>
using namespace std;
int main() {
    string str = "abbcdeffghh";
    getline(cin, str);
    int len = str.size();
    int cnt = 0;
    if(len == 1) {
        cout<<0<<endl;
        return 0;
    }

    if(str[0] != str[1]) cnt++;
    if(str[len-1] != str[len-2]) cnt++;

    for(int i = 1; i < len-1; i++) {
        if(str[i-1] != str[i] && str[i+1] != str[i]) cnt++;
    }

    cout<<cnt<<endl;
}