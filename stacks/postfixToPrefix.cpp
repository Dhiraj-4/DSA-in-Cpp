#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s = "79+4*8/3-";
            //          i
  
    stack<string> st; // 7+9*4/8-3

    for(int i = 0; i < s.size(); i++) {
        if(s[i]-48 >= 0 && s[i]-48 <= 9) st.push(to_string(s[i]-48));
        else {
            
            string val2 = st.top();
            st.pop();
            string val1 = st.top();
            st.pop();

            string res = "";
            res.push_back(s[i]);
            res += val1;
            res += val2;
            st.push(res);
        }
    }

    cout<<st.top()<<endl;
}