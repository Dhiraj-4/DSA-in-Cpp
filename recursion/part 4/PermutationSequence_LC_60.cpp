#include<iostream>
#include<string>
#include<vector>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 2; i <= n; i++) fact *= i;
    return fact;
}
void getPermutations(
    int n, string ans, int k
) {
    if(0 == n) {
        cout<<ans<<endl;
        return;
    }

    int blockIndex = (k-1) / factorial(n-1) + 1;
    cout<<blockIndex<<endl;
    getPermutations(n-1, ans+to_string(blockIndex), k);
}
int main() {
    int n = 3;
    int k = 3;
    vector<bool> taken(n+1, false);
    int end = factorial(n);
    getPermutations(n, "", k);

    // cout<<res[0]<<endl;
}