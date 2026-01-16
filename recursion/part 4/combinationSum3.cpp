#include<iostream>
#include<vector>
using namespace std;
void generate(int n, string temp, vector<string>& ans, int open, int close) {
    if(n == open && n == close) {
        ans.push_back(temp);
        return;
    }

    // add open "(" if open < n
    if(open < n) generate(n, temp+"(", ans, open+1, close);

    // add close ")" if close < open
    if(close < open) generate(n, temp+")", ans, open, close+1);
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
        
    generate(n, "", ans, 0, 0);
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<endl;
    vector<string> ans = generateParenthesis(n);

    for(string s : ans) {
        cout<<s<<endl;
    }
}