#include<iostream>
using namespace std;
int pow(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    int ans = pow(a, b/2);
    ans = ans*ans;
    if(b % 2) return ans * a;
    return ans;
}
int main() {
    int a, b;
    cin>>a>>b;
    cout<<pow(a, b);
}

// 2^8 = 2^4 * 2^4
// 2^4 = 2^2 * 2*2
// 2^2 = 2 * 2