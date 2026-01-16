#include<iostream>
using namespace std;
int gcd(int& a, int& b) {
    while(a != 0 && b != 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a != 0) return a;
    return b;
}
int gcdRecursion(int& a, int& b) {
    if(a == 0) return b;
    if(b == 0) return a;

    b = b%a;
    return gcdRecursion(b, a);
}
int main() {
    int a, b;
    cin>>a>>b;
    // time complexity of gcd and gcdRecursion is O(log(a+b)); this comes from crazy math
    // one day i will learn it, but now craking interview is the priority, for now just 
    // remember O(log(a+b));
    cout<<gcdRecursion(a,b)<<endl;
}