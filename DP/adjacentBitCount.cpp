#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<long long>>> dp;
long long f(int k, int i, bool on, int n) {
    if(k == 0 && i >= n) return 1;
    if(i >= n) return 0;

    if(dp[i][k][on] != -1) return dp[i][k][on];

    int ans = 0;
    if(on == true && k > 0) ans = f(k-1, i+1, true, n);
    else if(on == false) ans = f(k, i+1, true, n);

    ans += f(k, i+1, false, n);

    return dp[i][k][on] = ans;
}

int main() {
    int p;
    cin>>p;
    
    vector<long long> ans(p);
    for(int i = 0; i < p; i++) {
        int idx, n, k;
        cin>>idx>>n>>k;
        dp.clear();
        dp.resize(n+1, vector<vector<long long>>(k+1, vector<long long>(2, -1)));
        ans[idx-1] = f(k, 0, false, n);
    }
    

    for(int i = 0; i < p; i++) {
        cout<<i+1<<" "<<ans[i]<<endl;
    }
}