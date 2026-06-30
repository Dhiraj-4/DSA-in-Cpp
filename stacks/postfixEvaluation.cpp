#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s = "79+4*8/3-";
    stack<int> st;

    for(int i = 0; i < s.size(); i++) {
        if(s[i]-48 >= 0 && s[i]-48 <= 9) st.push(s[i]-48);
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            int sum = 0;
            if(s[i] == '+') sum = val1 + val2;
            else if(s[i] == '-') sum = val1 - val2;
            else if(s[i] == '*') sum = val1 * val2;
            else if(s[i] == '/') sum = val1 / val2;
            st.push(sum);
        }
    }

    cout<<st.top()<<endl;
}