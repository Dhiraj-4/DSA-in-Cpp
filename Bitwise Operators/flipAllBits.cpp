#include<iostream>
using namespace std;
int flipAllBits(int y) {
    int n = y;

    n = n | (n>>1);
    n = n | (n>>2);
    n = n | (n>>4);
    n = n | (n>>8);
    n = n | (n>>16);

    n = (n+1) >> 1;

    n = n << 1;

    n = n-1;

    return y ^ n;
}
int main() {
    int y = 19;
    cout<<flipAllBits(y)<<endl;
}