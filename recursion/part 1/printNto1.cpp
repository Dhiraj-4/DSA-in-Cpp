#include<iostream>
using namespace std;
void printNto1(int n) {
    if(n == 0) return;
    cout<<n<<" ";
    printNto1(n-1);
}
int main() {
    int n;
    cin>>n;
    if(n <= 0) {
        cout<<"N should be a positive integer";
        return 0;
    }
    printNto1(n);
}