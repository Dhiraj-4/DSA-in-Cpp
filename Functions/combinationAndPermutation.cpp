#include<iostream>
using namespace std;

long long combination2(int n, int r) {
    long long res = 1;
    r = max(r, (n-r));

    for(int i = 0; i < r; i++) {
        res = res * (n-i) / (i+1);
    }
    return res;
}
long factorial(int x) {
    long fact = 1;
    for(int i = 1; i <= x; i++) {
        fact *= i;
    }

    return fact;
}

long long combination(int n, int r) {
    long long res = 1;
    if(r > n) return 0;
    r = max(r, (n-r));

    for(int i = 0; i < r; i++) {
        res = res * (n-i) / (i+1);
    }
    return res;
}

long long permutation(int n, int r) {
    if(r > n) return 0;
    long long res = 1;

    for(int i = 0; i < r; i++) {
        res *= (n-i);
    }
    return res;
}

int main() {
    int n , r;

    cin>>n>>r;

    cout<<"combination "<<combination2(n,r)<<" And "<<"permutation "<<permutation(n,r)<<endl;
}

// 5 3
// combination 10 And permutation 60

