#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp(100005, vector<int>(4,-1));

int ftd (int n, int ban, vector<vector<int>>& activity) {
    if(n == 0) return 0;

    if(dp[n][ban] != -1) return dp[n][ban];

    int first = 0, second = 0, third = 0;

    if(ban != 1) { // call for a
        first = activity[n][1] + ftd(n-1, 1, activity);
    }

    if(ban != 2) { // call for b
        second = activity[n][2] + ftd(n-1, 2, activity);
    }

    if(ban != 3) third = activity[n][3] + ftd(n-1, 3, activity); // call for c

    return dp[n][ban] = max(first, max(second, third));      
}

int fbu(int n, vector<vector<int>>& activity) {

    dp[1][1] = activity[1][1];
    dp[1][2] = activity[1][2];
    dp[1][3] = activity[1][3];

    for(int i = 2; i <= n; i++) {
        dp[i][1] = activity[i][1] + max(dp[i-1][2] , dp[i-1][3]);

        dp[i][2] = activity[i][2] + max(dp[i-1][1], dp[i-1][3]);

        dp[i][3] = activity[i][3] +max(dp[i-1][1], dp[i-1][2]);
    }

    return max(dp[n][1], max(dp[n][2], dp[n][3]));
}
int main() {
    int n;
    cin>>n;

    vector<vector<int>> activity(n+1, vector<int>(4, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin>>activity[i][j];
        }
    }

    cout<<ftd(n, 0, activity)<<endl;

    dp.clear();
    dp.resize(100005, vector<int>(4, -1));

    cout<<fbu(n, activity)<<endl;

    return 0;
}
