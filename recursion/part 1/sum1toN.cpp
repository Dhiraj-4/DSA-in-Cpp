#include<iostream>
using namespace std;
int sum1toN(int n) {
    if(n == 1) return 1;
    return sum1toN(n-1)+n;
}
int main() {
    int n;
    cin>>n;
    if(n <= 0) {
        cout<<"N should be a positive integer";
        return 0;
    }
    cout<<sum1toN(n);
}