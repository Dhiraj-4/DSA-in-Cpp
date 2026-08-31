#include<iostream>
#include<string>
using namespace std;

int helper(char prev, int n) {
    if(n == 0) return 1;

    int left = 0, right = 0;

    if(prev != '1') left = helper('1', n-1);
    
    right = helper('0', n-1);

    return left + right;
}
int f(int n) {
    
    return helper('0', n);
}

int f2(int n) {

    int a = 2, b = 3, c;

    if(n == 1) return a;
    if(n == 2) return b;

    for(int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    cout<<f2(n)<<endl;
}