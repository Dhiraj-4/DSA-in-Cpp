#include<iostream>
#include<stack>
using namespace std;

string solve(string val1, char op, string val2) {
    string s = "";
    s += val1;
    s += val2;
    s.push_back(op);
    return s;
}

int main() {
    string s = "-/*+79483"; // 79+4*8/3-
    // s = "-+2/*6483"; // 264*8/+3-
            //          i
            //  
    stack<string> st; // 7+9*4/8-3
    int val1 = 0, val2 = 0, cnt = 0;

    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i]-48 >= 0 && s[i]-48 <= 9) st.push(to_string(s[i]-48));
        else {
            string val1 = st.top();
            st.pop();
            string val2 = st.top();
            st.pop();

            string res = solve(val1, s[i], val2);
            st.push(res);
        }
    }

    cout<<st.top()<<endl;
}