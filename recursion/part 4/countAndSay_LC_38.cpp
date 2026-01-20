#include<iostream>
#include<string>
using namespace std;
    string countAndSay(int n) {
        if(n == 1) return "1";

        string prevStr = countAndSay(n-1);

        string temp = "";
        int cnt = 1;
        char ch = prevStr[0];
        
        for(int i = 1; i < prevStr.size(); i++) {
            if(ch != prevStr[i]) {
                temp += to_string(cnt) + ch;
                ch = prevStr[i];
                cnt = 1;

            } else cnt++;
        }

        temp += to_string(cnt) + ch;

        return temp;
    }
int main() {
    cout<<countAndSay(1)<<endl;
    cout<<countAndSay(2)<<endl;
    cout<<countAndSay(3)<<endl;
    cout<<countAndSay(4)<<endl;
}