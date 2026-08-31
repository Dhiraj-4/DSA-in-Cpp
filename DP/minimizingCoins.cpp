#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp;

int f(int n, int sum, int& x, vector<int>& coins) {
    if(sum > x) return -1;
    if(sum == x) return 0;

    if(dp[sum] != -2) return dp[sum];

    int mn = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(sum + coins[i] <= x) {
            int temp = f(n, sum+coins[i], x, coins);
            if(temp != -1) mn = min(mn, temp);
        }
    }

    if(mn == INT_MAX) return dp[sum] = -1;

    return dp[sum] = 1 + mn;
}

int ftd(int x, vector<int>& coins) {
    if(x < 0) return -1;
    if(x == 0) return 0;

    if(dp[x] != -2) return dp[x];

    int mn = INT_MAX;
    for(int i = 0; i < coins.size(); i++) {
        if(x - coins[i] >= 0) {
            int temp = ftd(x - coins[i], coins);
            if(temp != -1) mn = min(mn, temp);
        }
    }

    if(mn == INT_MAX) return dp[x] = -1;
    return dp[x] = 1 + mn;
}

int fbu(int x, vector<int>& coins) {
    vector<int> memo(x+5, -2);

    memo[0] = 0;

    for(int i = 1; i <= x; i++) {
        
        int mn = INT_MAX;
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0 && memo[i - coins[j]] != -1) {
                mn = min(mn, memo[i - coins[j]]);
            }
        }

        if(mn == INT_MAX) memo[i] = -1;
        else memo[i] = 1 + mn; 
    }
    
    return memo[x];
}

int main() {
    int n, x;

    cin>>n>>x;

    // dp.clear();
    // dp.resize(1e6 + 7, -2);

    vector<int> coins(n);

    for(int i = 0; i < n; i++) cin>>coins[i];

    // cout<<f(n, 0, x, coins)<<endl;

    // dp.clear();
    // dp.resize(1e6 + 7, -2);

    // cout<<ftd(x, coins)<<endl;

    cout<<fbu(x, coins);
}