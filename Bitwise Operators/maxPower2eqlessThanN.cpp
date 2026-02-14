#include<iostream>
using namespace std;

int main() {
    int n = 100;

    while((n & (n-1)) != 0) {
        n = (n & (n-1));
    }
    cout<<n<<endl;
}