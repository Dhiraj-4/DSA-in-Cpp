#include<iostream>
#include<vector>
using namespace std;

    bool isPrime(int n) {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }

        return true;
    }

    int countPrimes(int n) {
        vector<bool> arr(n+1, true);
        arr[0] = false;
        arr[1] = false;
        
        for(int i = 2; i * i <= n; i++) {
            if(arr[i] && isPrime(i)) {
                for(int j = i+1; j <= n; j++) {
                    if(arr[j] && j % i == 0) arr[j] = false;
                }
            }
            else arr[i] = false;
        }

        int cnt = 0;

        for(int i = 2; i < n; i++) {
            if(arr[i]) {
                cout<<i<<" "<<endl;
                cnt++;
            }
        }

        return cnt;
    }
int main() {
    countPrimes(10);
}