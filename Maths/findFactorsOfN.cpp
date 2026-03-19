#include<iostream>
#include<cmath>
using namespace std;

void factors(int n) {
    if(n == 1) {
        cout<<1<<endl;
        return;
    }

    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cout<<i<<endl;

            if(n/i != i) {
                cout<<n/i<<endl;
            }
        }
    }
}

void factorsSorted(int n) {
    if(n == 1) {
        cout<<1<<endl;
        return;
    }
    
    for(int i = 1; i * i < n; i++) {
        if(n % i == 0) cout<<i<<" ";
    }

    for(int i = sqrt(n); i >= 1; i--) {
        if(n % i == 0) cout<<n/i<<" ";
    }
}
int main() {
    factorsSorted(64);
}