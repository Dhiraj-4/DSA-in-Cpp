#include<iostream>
#include<stack>
using namespace std;

int solve(int val1, char op, int val2) {
    if(op == '+') return val1 + val2;
    else if(op == '-') return val1 - val2;
    else if(op == '*') return val1 * val2;
    return val1 / val2;
}

int main() {
    string s = "-/*+79483";
            //          i
            //  
    stack<int> st; // 7+9*4/8-3
    int val1 = 0, val2 = 0, cnt = 0;

    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i]-48 >= 0 && s[i]-48 <= 9) st.push(s[i]-48);
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            int res = solve(val1, s[i], val2);
            st.push(res);
        }
    }

    cout<<st.top()<<endl;
}