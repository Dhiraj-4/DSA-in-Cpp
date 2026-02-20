#include<iostream>
using namespace std;
int maxPowerOfTwo(int n) { // only 32 bit input
    n = (n | (n >> 1));
    n = (n | (n >> 2));
    n = (n | (n >> 4));
    n = (n | (n >> 8));
    n = (n | (n >> 16));

    // 111 = (2^3) - 1
    // (2^3) >> 1 = 2^2;
    // ans = 2^2;
    return (n+1) >> 1; 
}
int main() {
    int n = 64;
    int x = n;

    while((n & (n-1)) != 0) {
        n = (n & (n-1));
    }
    cout<<n<<endl;
    cout<<maxPowerOfTwo(x)<<endl;
}