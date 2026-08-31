#include<iostream>
#include<vector>
#include<climits>
using namespace std;

long long MOD = 1000000000 + 7;
vector<long long> dp;

long long ftd(int n) {
    if(n == 0) return 1;

    if(dp[n] != -2) return dp[n];

    long long cnt = 0;

    for(int i = 1; i <= 6; i++) {
        if(n - i >= 0) {
            cnt = ((cnt % MOD) + (ftd(n - i) % MOD)) % MOD ;
        }
    }

    return dp[n] = cnt;
}

long long fbu(int n) {
    if(n == 0) return 1;

    dp[0] = 1;

    for(int i = 1; i <= n; i++) {

        long long cnt = 0;
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                cnt = ((cnt % MOD) + (dp[i - j] % MOD)) % MOD;
            }
        }

        dp[i] = cnt;
    }

    return dp[n];
}

int main() {
    long long n;
    cin>>n;

    dp.clear();
    dp.resize(n + 5, -2);
    // 10^9+7
    // cout<<(ftd(n) % (MOD))<<endl;

    // dp.clear();
    // dp.resize(n + 5, -2);
    cout<<(fbu(n) % MOD)<<endl;
}