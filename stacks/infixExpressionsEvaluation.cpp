#include<iostream>
#include<stack>
using namespace std;

int pr(char c) {
    if(c == '*' || c == '/') return 2;
    return 1;
}

int main() {
    string s = "(7+9)*4/8-3";
    // 2+24/8 - 3
    // 2+ 3 - 3;
    // 5-3
    stack<int> numSt;
    stack<char> opSt;

    for(int i = 0; i < s.size(); i++) {

        if(s[i]-48 >= 0 && s[i]-48 <= 9) numSt.push(s[i]-48);
        else if(opSt.size() == 0 || s[i] == '(' || opSt.top() == '(') 
            opSt.push(s[i]);
        else if(s[i] == ')') {
            while(opSt.top() != '(') {
                char op = opSt.top();
                opSt.pop();
                int val2 = numSt.top();
                numSt.pop();
                int val1 = numSt.top();
                numSt.pop();

                int res = 0;

                if(op == '*') res = val1 * val2;
                else if(op == '/') res = val1 / val2;
                else if(op == '+') res = val1 + val2;
                else if(op == '-') res = val1 - val2;

                numSt.push(res);
            }
            opSt.pop();
        }
        else if(pr(opSt.top()) < pr(s[i])) opSt.push(s[i]);
        else {
            while(opSt.size() && pr(opSt.top()) >= pr(s[i])) {
                char op = opSt.top();
                opSt.pop();
                int val2 = numSt.top();
                numSt.pop();
                int val1 = numSt.top();
                numSt.pop();

                int res = 0;

                if(op == '*') res = val1 * val2;
                else if(op == '/') res = val1 / val2;
                else if(op == '+') res = val1 + val2;
                else if(op == '-') res = val1 - val2;

                numSt.push(res);
            }
            opSt.push(s[i]);
        }
    }

    while(opSt.size()) {
        char op = opSt.top();
        opSt.pop();
        int val2 = numSt.top();
        numSt.pop();
        int val1 = numSt.top();
        numSt.pop();

        int res = 0;

        if(op == '*') res = val1 * val2;
        else if(op == '/') res = val1 / val2;
        else if(op == '+') res = val1 + val2;
        else if(op == '-') res = val1 - val2;

        numSt.push(res);
    }

    cout<<numSt.top()<<endl;
    cout<<(7+9)*4/8-3<<endl;
}