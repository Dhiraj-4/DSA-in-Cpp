#include<iostream>
using namespace std;

long long combination(int n) {
    long long res = 1;

    for(int i = 0; i <= n; i++) {
        cout<<res<<" ";
        res = res * (n-i) / (i+1);
    }
    return res;
}
void pascalTriangle(int n) {
    for(int i = 0; i < n; i++) {
        combination(i);
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;

    pascalTriangle(n);
}

//  0 1 2 3
//0 1
//1 1 1 
//2 1 2 1
//3 1 3 3 1