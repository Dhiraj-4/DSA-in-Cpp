#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

vector<vector<int>>dp;

int ftd(int i, int j, string& s1, string& s2) {
    if(i >= s1.size() || j >= s2.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1 + ftd(i+1, j+1, s1, s2);

    return dp[i][j] = max(ftd(i+1, j, s1, s2), ftd(i, j+1, s1, s2));
}

int main() {
    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // top down solution:
    dp.clear();
    dp.resize(n+1, vector<int>(m+1, -1));
    ftd(0, 0, s1, s2);


    // bottom up solution:
    // dp.clear();
    // dp.resize(n+1, vector<int>(m+1, 0));

    // for(int i = n-1; i >= 0; i--) {
    //     for(int j = m-1; j >= 0; j--) {
    //         if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
            
    //         else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    //     }
    // }

    // cout<<dp[0][0];

    int i = 0, j = 0; 
    string ans = "";

    while(i < n && j < m) {
        if(s1[i] == s2[j]) {
            ans += s1[i];
            i++;
            j++;
        }

        else if(dp[i+1][j] >= dp[i][j+1]) i++;

        else j++;
    }

    cout<<ans<<endl;
}