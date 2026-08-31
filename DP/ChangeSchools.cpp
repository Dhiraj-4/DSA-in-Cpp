#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, k;

    cin>>n>>k;

    unordered_map<int, int> mp;

    int mx = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        mp[x] += 1;
        mx = max(mx, mp[x]);
    }

    int cnt = 0;
    for(auto x : mp) if(x.second + 1 >= mx) cnt += 1;
    
    cout<<cnt<<endl;
}