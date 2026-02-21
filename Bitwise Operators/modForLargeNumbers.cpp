#include<iostream>
#include<vector>
using namespace std;
// I don't know what is happening over here
vector<long long> factorial(int n) {
    vector<long long> fact(n+1, 1);
    int MOD = 1000000007;

    for(int i = 2; i <= n; i++) 
        fact[i] = ((i % MOD) * (fact[i-1] % MOD)) % MOD;
    
    return fact;
}
int main() {
    vector<long long> res = factorial(25);

    for(int i = 0; i < res.size(); i++) cout<<i<<"! = "<<res[i]<<endl;
}