#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int reduce(int n) {
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;

    if(dp[n] != -1) return dp[n];

    int mn = INT_MAX;

    if(n % 3 == 0) mn = min(mn, reduce(n/3));
    if(n % 2 == 0) mn = min(mn, reduce(n/2));
    if(n > 1) mn = min(mn, reduce(n-1));

    return dp[n] = 1 + mn;
}

int reduce2(int n) {
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= n; i++) {
        int mn = INT_MAX;

        if(i % 3 == 0) mn = min(mn, dp[i/3]);
        if(i % 2 == 0) mn = min(mn, dp[i/2]);
        mn = min(mn, dp[i-1]);

        dp[i] = 1 + mn;
    }

    return dp[n];
}

int main() {
    int n;
    cin>>n;
    
    dp.clear();
    dp.resize(n+5, -1);
    // cout<<reduce(n);
    cout<<reduce2(n);
}