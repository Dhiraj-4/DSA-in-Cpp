#include<iostream>
#include<stack>
using namespace std;

int pr(char c) {
    if(c == '+' || c == '-') return 1;
    return 2;
}

int main() {
    string s = "2+6*4/8-3"; // -+2/*6483
    // s = "(7+9)*4/8-3";

    stack<string> st; //
    stack<char> op;   //
                      // -+2/*6483
    for(int i = 0; i < s.size(); i++) {

        if(s[i]-48 >= 0 && s[i]-48 <= 9) st.push(to_string(s[i]-48));
         
        else if(op.size() == 0 || op.top() == '(' || s[i] == '(') op.push(s[i]);
        else if(s[i] == ')') {
            while(op.top() != '(') {
                char ch = op.top();
                op.pop();
    
                string val2 = st.top();
                st.pop();
                string val1 = st.top();
                st.pop();
    
                string res = ch + val1 + val2;
                st.push(res);
            }
            op.pop();
        }
        else if(pr(op.top()) < pr(s[i])) op.push(s[i]);
        else {
            while(op.size() && pr(op.top()) >= pr(s[i])) {
                char ch = op.top();
                op.pop();
    
                string val2 = st.top();
                st.pop();
                string val1 = st.top();
                st.pop();
    
                string res = ch + val1 + val2;
                st.push(res);
            }
            op.push(s[i]);
        }
    }

    while(op.size()) {
        char ch = op.top();
        op.pop();

        string val2 = st.top();
        st.pop();
        string val1 = st.top();
        st.pop();

        string res = ch + val1 + val2;
        st.push(res);
    }

    cout<<st.top()<<endl;
}
