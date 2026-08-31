#include<iostream>
#include<vector>
using namespace std;

int b_frog2(int i, int k, int cost, vector<int>& stones) {
    if(i == stones.size()-1) return cost;

    int mn = INT_MAX;

    for(int j = i+1; j <= i+k; j++) {
        if(j < stones.size()) mn = min(mn, b_frog2(j, k, cost + abs(stones[i] - stones[j]), stones));
    }

    return mn;
}

int helper(int cur, int prev, int k , int n, vector<int>& stones, vector<int>& dp) {
    int mn = INT_MAX;
    if(cur == n-1) {
        mn = abs(stones[prev] - stones[cur]);
        return mn;
    }

    if(dp[cur] != -1) {
        mn = abs(stones[prev] - stones[cur]) + dp[cur];
        return mn;
    }

    for(int j = cur+1; j <= cur+k; j++) {
        if(j >= n) break;

        cout<<"(" << j <<" "<<cur<<" "<<k<<")"<<endl; 
        mn = min(mn, helper(j, cur, k, n, stones, dp));
    }

    dp[cur] = mn;

    return abs(stones[prev] - stones[cur]) + dp[cur];
}

int b_frog2II(vector<int>& stones, int k) {
    int n = stones.size();

    vector<int> dp(n, -1);

    return helper(0, 0, k, n, stones, dp);
}

int b_frog2III(vector<int>& stones, int k) {
    int n = stones.size();

    vector<int> dp(n, 0);

    for(int i = n-2; i >= 0; --i) {
        int mn = INT_MAX;
        for(int j = i+1; j <= i+k; j++) {
            if(j >= n) break;

            int cost = abs(stones[i] - stones[j]) + dp[j];
            mn = min(mn, cost);
        }
        dp[i] = mn;
    }
    return dp[0];
}

int main() {
    vector<int> stones = {10, 30, 40, 50, 20};

    int k = 3;

    cout<<b_frog2III(stones, k)<<endl;
}