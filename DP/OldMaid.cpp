#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        mp[x] += 1;
    }

    int sum = 0;
    for(auto x : mp) {
        if(x.second % 2 != 0) sum += x.first;
    }

    cout<<sum;
}