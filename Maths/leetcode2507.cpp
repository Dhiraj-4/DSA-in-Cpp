#include<iostream>
using namespace std;

    bool isPrime(int n) {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;

        return true;
    }
    int smallestValue(int n) {
        
        while(!isPrime(n)) {
            int sum = 0;
            for(int i = 1; i * i <= n; i++) {
                if(n % i == 0) {
                    if(i != 1 && isPrime(i)) sum += i;

                    if(n/i != i) {
                        if(i != 1 && isPrime(n/i)) sum += (n/i);
                    }
                }
            }
            cout<<n<<endl;
            n = sum;
        }

        return n;
    }

    int main() {
        cout<<smallestValue(15)<<endl;
    }