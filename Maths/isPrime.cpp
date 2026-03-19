#include<iostream>
using namespace std;

bool isPrime(int n) {
    if(n == 1) return false;

    int cnt = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cnt += 2;
        }

        if(cnt > 2) return false;
    }

    if(cnt == 2) return true;
    return false;
}

bool isPrime2(int n) {
    if(n <= 1) return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) 
            return false;
        

    }

    return true;
}

int main() {
    cout<<isPrime2(18)<<endl;
}