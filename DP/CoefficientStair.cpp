#include<bits/stdc++.h>
using namespace std;
// failed 
void helper(int num, int n, int k) {
    int sum = 0;
    vector<int> digits(n);

    for(int j = n - 1; j >= 0; j--) {
        digits[j] = num % 10;
        num /= 10;
    }

    for(int j = 0; j < n; j++) {
        sum += (n - j) * digits[j];
    }

    if(sum == k) {
        for(int digit : digits) {
            cout << digit << " ";
        }
        cout << '\n';
    }
}
int main() {
    int n, k;
    cin>>n>>k;
    int e = 1;
    for(int i = 1; i < n; i++) e *= 10;

    int i = 0;
    while(i <= k*e) {
        helper(i, n, k);
        i += 1;
    } 
}