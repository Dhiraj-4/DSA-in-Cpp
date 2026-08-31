#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int f(int n) {
    int cnt = 0;
    
    while(n) {
        int maxDigit = INT_MIN;
        int x = n;

        while(x) {
            maxDigit = max(maxDigit, x%10);
            x /= 10;
        }
        cnt += 1;
        n = n -  maxDigit;
    }
    
    return cnt;
}

int main() {
    int n;
    cin>>n;

    cout<<f(n)<<endl;
}