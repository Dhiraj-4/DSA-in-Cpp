#include<iostream>
#include<vector>
using namespace std;

long long f(long long n, vector<long long>& fibo) {
    if(n < 0) return 0;
    if(n == 0 || n == 1) return n;
    
    long long left;
    if(fibo[n-1] == -1) {
        left = f(n-1, fibo);
        fibo[n-1] = left;
    }else {
        left = fibo[n-1];
    }
    
    long long right;
    if(fibo[n-2] == -1) {
        right = f(n-2, fibo);
        fibo[n-2] = right;
    }
    else {
        right = fibo[n-2];
    }

    return left + right; 
}

long long f2(long long n) {
    if(n < 0) return 0;
    if(n == 0 || n == 1) return n;
    
    long long left;
    left = f2(n-1);
    
    long long right;
    right = f2(n-2);

    return left + right; 
}
int main() {
    int n = 50;
    vector<long long> fibo(n, -1);
    fibo[0] = 0;
    fibo[1] = 1;

    cout<<f(n, fibo)<<endl;
    cout<<f2(n)<<endl;
}